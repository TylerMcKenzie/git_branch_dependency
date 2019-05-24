package app.model;

import sys.io.File;
import sys.FileSystem;
import haxe.Json;

typedef DependencyData = {
    var branches:Map<String, Array<String>>;
}

class DependencyModel {
    public static var JSON_FILE:String = ".git-dep.json";

    private var dependencies = null;

    public function new() {}

    public function save(content = "", convertJson = false) : Void
    {
        if (convertJson) {
            content = Json.stringify(content);
        }

        File.saveContent(JSON_FILE, content);
    }

    public function getDependencies() : Dynamic
    {
        return dependencies;
    }

    public function loadDependencies(branch:String) : Void
    {
        if (FileSystem.exists(JSON_FILE)) {
            var fileDependencies:DependencyData = Json.parse(File.getContent(JSON_FILE));
            dependencies = fileDependencies.branches[branch];
        } else {
           save();
        }
    }
}
