package app;

import app.model.DependencyModel;

import app.util.Formatter;
import app.util.GitCommand;
import app.util.GitProcess;

import haxe.io.Input;

import sys.io.Process;

@:enum abstract COMMAND(String) {
    var ADD_L = "add";
    var ADD_S = "-a";

    var DELETE_L = "delete";
    var DELETE_S = "-d";

    var HELP_L = "help";
    var HELP_S = "-h";

    var LIST_L = "list";
    var LIST_S = "-l";

    var PRUNE_L = "prune";
    var PRUNE_S = "-p";

    var STATUS_L = "status";
    var STATUS_S = "-s";

    var UPDATE_L = "update";
    var UPDATE_S = "-u";
}

class App {
    private var dependencyModel:DependencyModel;
    private var formatter:Formatter;
    private var currentBranch:String;
    private var input:Input = Sys.stdin();

    public function new()
    {
        currentBranch = loadCurrentBranch();
        formatter = new Formatter();
        dependencyModel = new DependencyModel();
        dependencyModel.loadDependencies(currentBranch);
    }

    public function run() : Void
    {
        var args:Array<String> = Sys.args();

        for (i in 0...args.length) {
            switch args[i] {
                case LIST_L | LIST_S:
                    Sys.println('Showing dependencies for [${currentBranch}]:');
                    for (dependency in dependencyModel.getDependencies()) {
                        Sys.println(dependency);
                    }
                    break;
                case STATUS_L | STATUS_S:
                    Sys.println("Checking for remote updates...");
                    updateRemotes();

                    checkDependencyRemoteStatus();
                    break;
                case UPDATE_L | UPDATE_S:
                    var dependencies = dependencyModel.getDependencies();
                    var arg_dependencies = [];
                    var j = i + 1;

                    if (args[j] != null) {
                        if (
                            dependencies.indexOf(args[j]) > -1
                        ) {
                            arg_dependencies.push(args[j]);

                            var dependencyFound = true;
                            while (dependencyFound) {
                                j++;

                                if (
                                    dependencies.indexOf(args[j]) > -1 &&
                                    arg_dependencies.indexOf(args[j]) < 0
                                ) {
                                    arg_dependencies.push(args[j]);
                                } else {
                                    dependencyFound = false;
                                }
                            }
                        } else {
                            Sys.println('[WARN] Branch: \'${args[j]}\' not found in dependency list.');
                            break;
                        }
                    }

                    if (arg_dependencies.length > 0) {
                        dependencies = arg_dependencies;
                    }

                    Sys.println("Updating remotes...");
                    updateRemotes();

                    updateDependencyRemotes(dependencies);
                    break;
                case ADD_L | ADD_S:
                    var dep = args[i+1];
                    addDependency(dep);
                case DELETE_L | DELETE_S:
                    var dep = args[i+1];
                    removeDependency(dep);
                case PRUNE_L | PRUNE_S:
                    updateRemotes();

                    pruneDependencies();
                    break;
                case HELP_L | HELP_S:
                    outputHelp();
                    break;
            }
        }
    }

    private function addDependency(dependency:String) : Void
    {
        dependencyModel.addDependency(dependency);
        dependencyModel.save();
    }

    private function removeDependency(dependency:String) : Void
    {
        dependencyModel.removeDependency(dependency);
        dependencyModel.save();
    }

    private function updateDependencyRemotes(dependencies:Array<String>) : Void
    {
        var updated = false;

        var preparedBranches:Array<String> = [];

        for(dependency in dependencies) {
            var dependencyStatus = getBranchRemoteStatus(dependency);

            if (Std.parseInt(dependencyStatus.behind) > 0) {
                updateBranch(dependency);
            }

            if (getBranchMergeStatus(dependency) == "unmerged") {
                preparedBranches.push(dependency);
            }
        }

        if (preparedBranches.length > 0) {
            var gitPullArgs = ["origin"].concat(preparedBranches);
            gitPullArgs.push("--no-ff");

            // If Octopus fails fall back to merging in order
            if (GitCommand.pull(gitPullArgs) != 0) {
                Sys.println("Falling back to indiviually merging dependencies.");
                
                GitProcess.reset(["--hard"]).exitCode();

                for(branch in preparedBranches) {
                    if (!updateDependencyBranch(branch)) {
                        throw 'There was an error updating: \'$branch\'';
                    }
                }
            }
        } else {
            Sys.println("Nothing updated.");
        }
    }

    private function updateDependencyBranch(branch:String) : Bool
    {
        if (GitCommand.pull(["origin", branch, "--no-ff"]) != 0) {
            var diffFiles = GitProcess.diff(["-diff-filter=UU", "--name-only"]).stdout.readAll().toString();

            var unmergedFiles = [];
            for (file in diffFiles.split("\n")) {
                if (file.length > 0) {
                    unmergedFiles.push(StringTools.trim(file));
                }
            }

            // Open default editor if one exists
            var editor = StringTools.trim(GitProcess.config(["--global", "core.editor"]).stdout.readAll().toString());

            if (editor.length > 0) {
                if (unmergedFiles.length > 0) {
                    if (Sys.command(editor, unmergedFiles) != 0) {
                        Sys.println('An error occurred when opening \'${editor}\'');
                        return false;
                    }

                    Sys.println("Commit these changes? [Y/n]: ");

                    var userInput = input.readLine();
                    var confReg:EReg = ~/[Yy]/;

                    if (confReg.match(userInput)) {
                        GitProcess.commit(["-am", "\'Updated merge conflicts\'"]).exitCode();
                    }
                }
            } else {
                return false;
            }
        }

        return true;
    }

    private function updateBranch(branch:String) : Void
    {
        GitProcess.fetch(["origin", '$branch:$branch']).exitCode();
    }

    private function checkDependencyRemoteStatus() : Void
    {
        var deps = dependencyModel.getDependencies();

        var branchRows = [];
        for(dep in deps) {
            var status = getBranchRemoteStatus(dep);

            var mergedStatus = getBranchMergeStatus(dep);

            branchRows.push([dep, status.ahead, status.behind, mergedStatus]);
        }

        formatter.printTable(["branch", "ahead", "behind", "status"], branchRows);
    }

    private function getBranchRemoteStatus(branch:String) : Dynamic
    {
        var branchToOrigin = '$branch...origin/$branch';

        var ahead = StringTools.trim(GitProcess.revList(["--left-only", "--count", branchToOrigin]).stdout.readAll().toString());
        var behind = StringTools.trim(GitProcess.revList(["--right-only", "--count", branchToOrigin]).stdout.readAll().toString());

        return {
            ahead: ahead,
            behind: behind
        };
    }

    private function getBranchMergeStatus(branch:String) : String
    {
        var dirtyMergedBranches = GitProcess.branch(["--merged"]).stdout.readAll().toString().split("\n");
        var cleanMergedBranches = [for (dB in dirtyMergedBranches) StringTools.trim(dB)];

        if (cleanMergedBranches.indexOf(branch) == -1) {
            return "unmerged";
        }

        return "merged";
    }

    private function loadCurrentBranch() : String
    {
        var process = GitProcess.revParse(["--abbrev-ref", "HEAD"]);

        process.exitCode();

        var b = StringTools.trim(process.stdout.readAll().toString());

        return b;
    }

    private function updateRemotes() : Void
    {
        // This updates remotes to get accurate checks
        GitProcess.remote(["update"]).exitCode();
    }

    private function pruneDependencies() : Void
    {
        var dependencies = dependencyModel.getDependencies();
        var masterMergedBranches = GitProcess.branch(["--merged", "master"]).stdout.readAll().toString().split("\n");
        masterMergedBranches = [ for (branch in masterMergedBranches) StringTools.trim(branch) ];

        for (dependency in dependencies) {
            if (masterMergedBranches.indexOf(dependency) > -1 && dependency != "master") {
                removeDependency(dependency);
            }
        }
    }

    private function outputHelp() : Void
    {
        Sys.println("GIT-DEPENDENCY");
        Sys.println("");
        Sys.println("NAME");
        Sys.println("    git-dependency - Manages branches as dependencies for complex features.");
        Sys.println("");
        Sys.println("SYNOPSIS");
        Sys.println("    git dependency [add|-a <branch>] [delete|-d <branch>] [help|-h]");
        Sys.println("                   [update <branch> |-u <branch>] [status|-s] [list|-s] [prune|-p]");
        Sys.println("");
        Sys.println("OPTIONS");
        Sys.println("    add | -a");
        Sys.println("        add a branch as a dependency.");
        Sys.println("    delete | -d");
        Sys.println("        remove a branch from the dependency list.");
        Sys.println("    -help | h");
        Sys.println("        display help.");
        Sys.println("    update <branch> | -u <branch>");
        Sys.println("        attempts to update and pull in dependency. If no branch is supplied it will attempt to pull in all dependencies with an octopus merge. If the merge fails it will fallback to individual merge/conflict resolution.");
        Sys.println("    status | -s");
        Sys.println("        checks to see if there are any changes between the current HEAD and the branches dependencies and outputs a table with those changes.");
        Sys.println("    list | -l");
        Sys.println("        list dependencies for the current branch.");
        Sys.println("    prune | -p");
        Sys.println("        prune dependencies from the dependency list that are merged with master.");
    }
}
