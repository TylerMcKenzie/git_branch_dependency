package app;

import app.model.DependencyModel;

class App {
    private var dependencyModel:DependencyModel = new DependencyModel();

    public function new() {
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

    private function processArgs()
    {
        
    }

    private function addDependency(dependency:String)
    {
        trace("add");
    }

    private function removeDependency(dependency:String)
    {
        trace("remove");
    }

    private function updateDependencyRemotes()
    {}

    private function checkDependencyRemoteStatus()
    {}

    private function getCurrentBranch() : String
    {
        var currentBranch:String = new Process("git", ["rev-parse", "--abbrev-ref", "HEAD"]).stdout.readAll().toString();
        return currentBranch;
    }
}
