package app.util;

class GitCommand {
    static public function branch(args: Array<String>) : Int
    {
        return Sys.command("git", ["branch"].concat(args));
    }

    static public function commit(args: Array<String>) : Int
    {
        return Sys.command("git", ["commit"].concat(args));
    }

    static public function config(args: Array<String>) : Int
    {
        return Sys.command("git", ["config"].concat(args));
    }

    static public function diff(args: Array<String>) : Int
    {
        return Sys.command("git", ["diff"].concat(args));
    }

    static public function fetch(args: Array<String>) : Int
    {
        return Sys.command("git", ["fetch"].concat(args));
    }

    static public function pull(args: Array<String>) : Int
    {
        return Sys.command("git", ["pull"].concat(args));
    }

    static public function remote(args: Array<String>) : Int
    {
        return Sys.command("git", ["remote"].concat(args));
    }

    static public function reset(args: Array<String>) : Int
    {
        return Sys.command("git", ["reset"].concat(args));
    }

    static public function revList(args: Array<String>) : Int
    {
        return Sys.command("git", ["rev-list"].concat(args));
    }

    static public function revParse(args: Array<String>) : Int
    {
        return Sys.command("git", ["rev-parse"].concat(args));
    }
}
