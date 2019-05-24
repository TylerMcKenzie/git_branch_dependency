package app.model;

import sys.io.File;
import sys.FileSystem;
import haxe.Json;
import haxe.DynamicAccess;

typedef DependencyData = {
    var deps:Array<String>;
}

class DependencyModel {
    public static var JSON_FILE:String = ".git-dep.json";

    private var dependencies = null;

    private var dependencyGraph:DynamicAccess<DependencyData> = null;

    public function new()
    {
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
        trace(dependencyGraph);
        if (dependencyGraph.exists(branch)) {
            dependencies = dependencyGraph[branch];
        } else {
            dependencyGraph[branch] = [];
            dependencies = dependencyGraph[branch];
            save();
        }
    }

    private function loadDependencyGraph() : Void
    {
         if (FileSystem.exists(JSON_FILE)) {
            var fileDependencies:DynamicAccess<DependencyData> = Json.parse(File.getContent(JSON_FILE));
            dependencyGraph = fileDependencies;
        } else {
            dependencyGraph = { master: { deps: [] }};
            save();
        }
    }
}
