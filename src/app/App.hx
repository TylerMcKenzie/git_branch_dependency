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
                case "status":
                    checkDependencyRemoteStatus();
                case "update":
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

        for(dep in deps) {
//            mergeBranch(dep);
        }
    }

    private function mergeBranch(branch:String)
    {
        new Process("git", ["merge", branch, "--no-ff"]);
    }

    private function checkDependencyRemoteStatus()
    {
        var deps = dependencyModel.getDependencies();

        for(dep in deps) {
            var status = getBranchRemoteStatus(dep);
            Sys.print(dep + ": [ahead " + status.ahead + ", behind " + status.behind + "]\n");
        }
    }

    private function getBranchRemoteStatus(branch:String)
    {
        var aheadDiff = branch+"...origin/"+branch;
        var behindDiff = branch+"..origin/"+branch;

        var ahead = new Process("git", ["rev-list", "--count", aheadDiff]).stdout.readAll().toString();
        var behind = new Process("git", ["rev-list", "--count", behindDiff]).stdout.readAll().toString();

        return {
            ahead: ahead,
            behind: behind
        };
    }

    private function getCurrentBranch() : String
    {
        return new Process("git", ["rev-parse", "--abbrev-ref", "HEAD"]).stdout.readAll().toString();
    }
}
