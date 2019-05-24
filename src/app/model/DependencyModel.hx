package app.model;

import sys.io.File;
import sys.io.Process;
import sys.FileSystem;

import haxe.Json;
import haxe.DynamicAccess;

typedef DependencyData = {
    @optional var deps:Array<String>;
}

class DependencyModel {
    public var JSON_FILE:String = "/.git/git-dep.json";

    private var currentBranch:String = null;

    private var dependencies:Array<String> = null;

    private var dependencyGraph:DynamicAccess<DependencyData> = null;

    public function new()
    {
        var root = getRootDirectory();
        JSON_FILE = root + JSON_FILE;
        loadDependencyGraph();
    }

    public function save() : Void
    {
        File.saveContent(JSON_FILE, Json.stringify(dependencyGraph));
    }

    public function getDependencies() : Array<String>
    {
        return dependencies;
    }

    public function addDependency(dependency:String) : Bool
    {
        if (dependencies.indexOf(dependency) == -1) {
            dependencies.push(dependency);
            return true;
        } else {
            return false;
        }
    }

    public function removeDependency(dependency:String) : Bool
    {
        if (dependencies.indexOf(dependency) != -1) {
            return dependencies.remove(dependency);
        }

        return false;
    }

    public function loadDependencies(branch:String) : Void
    {
        if (branch.length == 0) {
            throw "A branch is required to be loaded.\n";
        }

        branch = StringTools.trim(branch);

        if (dependencyGraph.exists(branch)) {
            dependencies = dependencyGraph[branch].deps;
            currentBranch = branch;
        } else {
            dependencyGraph[branch] = { deps: [] };
            dependencies = dependencyGraph[branch].deps;
            currentBranch = branch;
            save();
        }
    }

    private function loadDependencyGraph() : Void
    {
         if (FileSystem.exists(JSON_FILE)) {
            var fileDependencies:DynamicAccess<DependencyData> = Json.parse(File.getContent(JSON_FILE));
            dependencyGraph = fileDependencies;
        } else {
            dependencyGraph = {};
            save();
        }
    }

    private function getRootDirectory() : String
    {
        return StringTools.trim(new Process("git", ["rev-parse", "--show-toplevel"]).stdout.readAll().toString());
    }
}
