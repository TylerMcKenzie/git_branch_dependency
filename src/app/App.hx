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
                    Sys.println("Updating remotes");
                    updateRemotes();

                    checkDependencyRemoteStatus();
                case "update":
                    Sys.println("Updating remotes");
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

            preparedBranches.push(dep);
        }

        var gitPullArgs = ["pull", "origin"].concat(preparedBranches);
        Sys.command("git", gitPullArgs);
    }

    private function updateBranch(branch:String) : Void
    {
        new Process("git", ["fetch", "origin", '$branch:$branch']).exitCode();
    }

    private function mergeBranch(branch:String) : Void
    {
        var originBranch = 'origin/$branch';
        new Process("git", ["merge", originBranch, "--no-ff"]).exitCode(true);
    }

    private function checkDependencyRemoteStatus() : Void
    {
        var deps = dependencyModel.getDependencies();

        for(dep in deps) {
            var status = getBranchRemoteStatus(dep);
            if (Std.parseInt(status.ahead) > 0 || Std.parseInt(status.behind) > 0) {
                Sys.println(dep + ": [ahead " + status.ahead + ", behind " + status.behind + "]");
            } else {
                Sys.println(dep + ": [up to date]");
            }
        }
    }

    private function getBranchRemoteStatus(branch:String) : Dynamic
    {
        var branchToOrigin = '$branch..origin/$branch';

        var ahead = StringTools.trim(new Process("git", ["rev-list", "--left-only", "--count", branchToOrigin]).stdout.readAll().toString());
        var behind = StringTools.trim(new Process("git", ["rev-list", "--right-only", "--count", branchToOrigin]).stdout.readAll().toString());

        return {
            ahead: ahead,
            behind: behind
        };
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
