package app.util;

class GitCommand {
    public static function branch(args: Array<String>) : Int
    {
        return Sys.command("git", ["branch"].concat(args));
    }

    public static function commit(args: Array<String>) : Int
    {
        return Sys.command("git", ["commit"].concat(args));
    }

    public static function config(args: Array<String>) : Int
    {
        return Sys.command("git", ["config"].concat(args));
    }

    public static function diff(args: Array<String>) : Int
    {
        return Sys.command("git", ["diff"].concat(args));
    }

    public static function fetch(args: Array<String>) : Int
    {
        return Sys.command("git", ["fetch"].concat(args));
    }

    public static function pull(args: Array<String>) : Int
    {
        return Sys.command("git", ["pull"].concat(args));
    }

    public static function remote(args: Array<String>) : Int
    {
        return Sys.command("git", ["remote"].concat(args));
    }

    public static function reset(args: Array<String>) : Int
    {
        return Sys.command("git", ["reset"].concat(args));
    }

    public static function revList(args: Array<String>) : Int
    {
        return Sys.command("git", ["rev-list"].concat(args));
    }

    public static function revParse(args: Array<String>) : Int
    {
        return Sys.command("git", ["rev-parse"].concat(args));
    }
}
