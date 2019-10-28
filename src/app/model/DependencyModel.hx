package app.model;

import app.util.Git;

import sys.io.File;
import sys.FileSystem;

import haxe.Json;
import haxe.DynamicAccess;

typedef DependencyData = {
    @optional var deps:Array<String>;
}

class DependencyModel {
    public var JSON_FILE:String = "git-dep.json";

    private var currentBranch:String = null;

    private var dependencies:Array<String> = null;

    private var dependencyGraph:DynamicAccess<DependencyData> = null;

    public function new()
    {
        var root = getRootDirectory();

        if (root.length > 0) {
            JSON_FILE = root + "/.git/" + JSON_FILE;
        }

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
            throw "A branch is required to be loaded.";
        }

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
        var root = '';

        Git.process("rev-parse", ["--show-toplevel"], function (process) {
            root = process.stdout.readAll().toString();
            process.exitCode();
        });

        return StringTools.trim(root);
    }
}
