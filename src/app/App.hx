package app;

import app.model.DependencyModel;
import sys.io.Process;

class App {
    private var dependencyModel:DependencyModel = new DependencyModel();

    public function new()
    {
        dependencyModel.loadDependencies(getCurrentBranch());
    }

    public function run() : Void
    {
        var args:Array<String> = Sys.args();

        for (i in 0...args.length) {
            switch args[i] {
                case "list":
                    var currBranch = getCurrentBranch();
                    Sys.println('Showing dependencies for [$currBranch]:');
                    for (dependency in dependencyModel.getDependencies()) {
                        Sys.println(dependency);
                    }
                case "status":
                    Sys.println("Checking for remote updates...");
                    updateRemotes();

                    checkDependencyRemoteStatus();
                case "update":
                    Sys.println("Updating remotes...");
                    updateRemotes();

                    updateDependencyRemotes();
                case "-a":
                    var dep = args[i+1];
                    addDependency(dep);
                case "-d":
                    var dep = args[i+1];
                    removeDependency(dep);
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

    private function updateDependencyRemotes() : Void
    {
        var deps = dependencyModel.getDependencies();
        var updated = false;

        var preparedBranches:Array<String> = [];

        for(dep in deps) {
            var dependencyStatus = getBranchRemoteStatus(dep);

            if (Std.parseInt(dependencyStatus.behind) > 0) {
                updateBranch(dep);
            }

            if (getBranchMergeStatus(dep) == "unmerged") {
                preparedBranches.push(dep);
            }
        }

        if (preparedBranches.length > 0) {
            var gitPullArgs = ["pull", "origin"].concat(preparedBranches);
            gitPullArgs.push("--no-ff");

            // If Octopus fails fall back to merging in order
            if (Sys.command("git", gitPullArgs) != 0) {
                Sys.println("Falling back to indiviually merging dependencies.");
                
                new Process("git reset --hard");

                for(branch in preparedBranches) {
                    if (Sys.command("git", ["pull", "origin", branch, "--no-ff"]) != 0) {
                        var diffFiles = new Process("git diff --diff-filter=U --name-only").stdout.readAll().toString();

                        var unmergedFiles = [];
                        for (file in diffFiles.split("\n")) {
                            if (file.length > 0) {
                                unmergedFiles.push(StringTools.trim(file));
                            }
                        }

                        // Open default editor if one exists
                        var editor = StringTools.trim(new Process("git config --global core.editor").stdout.readAll().toString());

                        if (editor.length > 0) {
                            if (Sys.command(editor, unmergedFiles) != 0) {
                                Sys.println('An error occurred when opening \'${editor}\'');
                                return;
                            }
                        }
                    }
                }
            }
        } else {
            Sys.println("Nothing updated.");
        }
    }

    private function updateBranch(branch:String) : Void
    {
        new Process("git", ["fetch", "origin", '$branch:$branch']).exitCode();
    }

    private function checkDependencyRemoteStatus() : Void
    {
        var deps = dependencyModel.getDependencies();

        for(dep in deps) {
            var status = getBranchRemoteStatus(dep);

            var mergedStatus = getBranchMergeStatus(dep);

            if (Std.parseInt(status.ahead) > 0 || Std.parseInt(status.behind) > 0) {
                Sys.println('(${dep}) Remote: [ahead ${status.ahead}, behind ${status.behind}] Local: ${mergedStatus}');
            } else {
                Sys.println('(${dep}) Remote: [up to date] Local: ${mergedStatus}');
            }
        }
    }

    private function getBranchRemoteStatus(branch:String) : Dynamic
    {
        var branchToOrigin = '$branch...origin/$branch';

        var ahead = StringTools.trim(new Process("git", ["rev-list", "--left-only", "--count", branchToOrigin]).stdout.readAll().toString());
        var behind = StringTools.trim(new Process("git", ["rev-list", "--right-only", "--count", branchToOrigin]).stdout.readAll().toString());

        return {
            ahead: ahead,
            behind: behind
        };
    }

    private function getBranchMergeStatus(branch:String) : String
    {
        var dirtyMergedBranches = new Process("git", ["branch", "--merged"]).stdout.readAll().toString().split("\n");
        var cleanMergedBranches = [for (dB in dirtyMergedBranches) StringTools.trim(dB)];

        if (cleanMergedBranches.indexOf(branch) == -1) {
            return "unmerged";
        }

        return "merged";
    }

    private function getCurrentBranch() : String
    {
        var process = new Process("git", ["rev-parse", "--abbrev-ref", "HEAD"]);

        process.exitCode();

        var b = StringTools.trim(process.stdout.readAll().toString());

        return b;
    }

    private function updateRemotes() : Void
    {
        // This updates remotes to get accurate checks
        new Process("git", ["remote", "update"]).exitCode();
    }
}
