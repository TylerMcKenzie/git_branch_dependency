package app.util;

import sys.io.Process;

class GitProcess {
    public static function branch(args: Array<String>) : Process
    {
        return new Process("git", ["branch"].concat(args));
    }

    public static function commit(args: Array<String>) : Process
    {
        return new Process("git", ["commit"].concat(args));
    }

    public static function config(args: Array<String>) : Process
    {
        return new Process("git", ["config"].concat(args));
    }

    public static function diff(args: Array<String>) : Process
    {
        return new Process("git", ["diff"].concat(args));
    }

    public static function fetch(args: Array<String>) : Process
    {
        return new Process("git", ["fetch"].concat(args));
    }

    public static function pull(args: Array<String>) : Process
    {
        return new Process("git", ["pull"].concat(args));
    }

    public static function remote(args: Array<String>) : Process
    {
        return new Process("git", ["remote"].concat(args));
    }

    public static function reset(args: Array<String>) : Process
    {
        return new Process("git", ["reset"].concat(args));
    }

    public static function revList(args: Array<String>) : Process
    {
        return new Process("git", ["rev-list"].concat(args));
    }

    public static function revParse(args: Array<String>) : Process
    {
        return new Process("git", ["rev-parse"].concat(args));
    }
}
