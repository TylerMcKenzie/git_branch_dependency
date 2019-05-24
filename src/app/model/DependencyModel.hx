package app.model;

import sys.io.File;
import sys.FileSystem;
import haxe.Json;

typedef DependencyData = Map<String, Array<String>>;

class DependencyModel {
    public static var JSON_FILE:String = ".git-dep.json";

    private var dependencies = null;

    private var dependencyGraph = null;

    public function new() {
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
        if (var depIndex = dependencies.indexOf(dependency) != -1) {
            return dependencies.remove(dependency);
        } else {
            return false;
        }
    }

    public function loadDependencies(branch:String) : Void
    {
        dependencies = dependencyGraph[branch];
    }

    private function loadDependencyGraph() : Void
    {
         if (FileSystem.exists(JSON_FILE)) {
            var fileDependencies:DependencyData = Json.parse(File.getContent(JSON_FILE));
            dependencyGraph = fileDependencies;
        } else {
            dependencyGraph = new Map<String, Array<String>>();
            save();
        }
    }
}
