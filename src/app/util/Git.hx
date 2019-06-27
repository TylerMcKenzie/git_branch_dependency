package app.util;

import sys.io.Process;

class Git {
    public static function branch(args: Array<String>) : Process
    {
        return new Process("git branch", args);
    }

    public static function commit(args: Array<String>) : Process
    {
        return new Process("git commit", args);
    }

    public static function config(args: Array<String>) : Process
    {
        return new Process("git config", args);
    }

    public static function diff(args: Array<String>) : Process
    {
        return new Process("git diff", args);
    }

    public static function fetch(args: Array<String>) : Process
    {
        return new Process("git fetch", args);
    }

    public static function pull(args: Array<String>) : Process
    {
        return new Process("git pull", args);
    }

    public static function remote(args: Array<String>) : Process
    {
        return new Process("git remote", args);
    }

    public static function reset(args: Array<String>) : Process
    {
        return new Process("git reset", args);
    }

    public static function revList(args: Array<String>) : Process
    {
        return new Process("git rev-list", args);
    }

    public static function revParse(args: Array<String>) : Process
    {
        return new Process("git rev-parse", args);
    }
}
