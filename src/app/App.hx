package app;

import app.model.DependencyModel;
import sys.io.Process;

class App {
    private var dependencyModel:DependencyModel = new DependencyModel();

    public function new()
    {
        dependencyModel.loadDependencies(getCurrentBranch());
    }

    public function run()
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

    private function addDependency(dependency:String)
    {
        dependencyModel.addDependency(dependency);
        dependencyModel.save();
    }

    private function removeDependency(dependency:String)
    {
        dependencyModel.removeDependency(dependency);
        dependencyModel.save();
    }

    private function updateDependencyRemotes()
    {
        var deps = dependencyModel.getDependencies();
        var updated = false;

        for(dep in deps) {
            var dependencyStatus = getBranchRemoteStatus(dep);

            if (Std.parseInt(dependencyStatus.behind) > 0) {
                mergeBranch(dep);
                updated = true;
            }
        }

        if (updated) {
            Sys.println("Branch Dependencies updated.");
        } else {
            Sys.println("Nothing updated.");
        }
    }

    private function mergeBranch(branch:String)
    {
        var originBranch = 'origin/$branch';
        new Process("git", ["merge", originBranch, "--no-ff"]).exitCode(true);
    }

    private function checkDependencyRemoteStatus()
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

    private function getBranchRemoteStatus(branch:String)
    {
        var aheadDiff = 'origin/$branch..$branch';
        var behindDiff = '$branch..origin/$branch';

        var ahead = StringTools.trim(new Process("git", ["rev-list", "--count", aheadDiff]).stdout.readAll().toString());
        var behind = StringTools.trim(new Process("git", ["rev-list", "--count", behindDiff]).stdout.readAll().toString());

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

    private function updateRemotes()
    {
        // This updates remotes to get accurate checks
        new Process("git", ["remote", "update"]).exitCode();
    }
}
