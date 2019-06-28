package app.util;

class GitCommand {
    public static function branch(args: Array<String>) : Bool
    {
        return new Sys.command("git branch", args);
    }

    public static function commit(args: Array<String>) : Bool
    {
        return new Sys.command("git commit", args);
    }

    public static function config(args: Array<String>) : Bool
    {
        return new Sys.command("git config", args);
    }

    public static function diff(args: Array<String>) : Bool
    {
        return new Sys.command("git diff", args);
    }

    public static function fetch(args: Array<String>) : Bool
    {
        return new Sys.command("git fetch", args);
    }

    public static function pull(args: Array<String>) : Bool
    {
        return new Sys.command("git pull", args);
    }

    public static function remote(args: Array<String>) : Bool
    {
        return new Sys.command("git remote", args);
    }

    public static function reset(args: Array<String>) : Bool
    {
        return new Sys.command("git reset", args);
    }

    public static function revList(args: Array<String>) : Bool
    {
        return new Sys.command("git rev-list", args);
    }

    public static function revParse(args: Array<String>) : Bool
    {
        return new Sys.command("git rev-parse", args);
    }
}