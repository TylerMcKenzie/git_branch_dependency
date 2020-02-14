package app.util;

import sys.io.Process;

class GitProcess {
    static public inline function branch(args: Array<String>) : Process
    {
        return new Process("git", ["branch"].concat(args));
    }

    static public inline function commit(args: Array<String>) : Process
    {
        return new Process("git", ["commit"].concat(args));
    }

    static public inline function config(args: Array<String>) : Process
    {
        return new Process("git", ["config"].concat(args));
    }

    static public inline function diff(args: Array<String>) : Process
    {
        return new Process("git", ["diff"].concat(args));
    }

    static public inline function fetch(args: Array<String>) : Process
    {
        return new Process("git", ["fetch"].concat(args));
    }

    static public inline function pull(args: Array<String>) : Process
    {
        return new Process("git", ["pull"].concat(args));
    }

    static public inline function remote(args: Array<String>) : Process
    {
        return new Process("git", ["remote"].concat(args));
    }

    static public inline function reset(args: Array<String>) : Process
    {
        return new Process("git", ["reset"].concat(args));
    }

    static public inline function revList(args: Array<String>) : Process
    {
        return new Process("git", ["rev-list"].concat(args));
    }

    static public inline function revParse(args: Array<String>) : Process
    {
        return new Process("git", ["rev-parse"].concat(args));
    }
}
