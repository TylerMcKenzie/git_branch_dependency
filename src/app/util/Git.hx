package app.util;

import sys.io.Process;
import app.util.GitCommand;
import app.util.GitProcess;

enum abstract GIT_COMMANDS(String) to String
{
    var PULL      = "pull";
    var BRANCH    = "branch";
    var COMMIT    = "commit";
    var CONFIG    = "config";
    var DIFF      = "diff";
    var FETCH     = "fetch";
    var REMOTE    = "remote";
    var RESET     = "reset";
    var REV_LIST  = "rev-list";
    var REV_PARSE = "rev-parse";
}

class Git
{
    static public inline function process(cmd: String, args: Array<String>, callback: Process->Void) : Void
    {
        var process: Process = null;

        switch (cmd) {
            case BRANCH:
                process = GitProcess.branch(args);
            case COMMIT:
                process = GitProcess.commit(args);
            case CONFIG:
                process = GitProcess.config(args);
            case DIFF:
                process = GitProcess.diff(args);
            case FETCH:
                process = GitProcess.fetch(args);
            case PULL:
                process = GitProcess.pull(args);
            case REMOTE:
                process = GitProcess.remote(args);
            case RESET:
                process = GitProcess.reset(args);
            case REV_LIST:
                process = GitProcess.revList(args);
            case REV_PARSE:
                process = GitProcess.revParse(args);
            default:
                Sys.println('Git Command: "$cmd", does not exist.');
        }

        callback(process);
    }

    static public inline function command(cmd: String, args: Array<String>) : Int
    {
        var exitCode: Int = 0;

        switch (cmd) {
            case BRANCH:
                exitCode = GitCommand.branch(args);
            case COMMIT:
                exitCode = GitCommand.commit(args);
            case CONFIG:
                exitCode = GitCommand.config(args);
            case DIFF:
                exitCode = GitCommand.diff(args);
            case FETCH:
                exitCode = GitCommand.fetch(args);
            case PULL:
                exitCode = GitCommand.pull(args);
            case REMOTE:
                exitCode = GitCommand.remote(args);
            case RESET:
                exitCode = GitCommand.reset(args);
            case REV_LIST:
                exitCode = GitCommand.revList(args);
            case REV_PARSE:
                exitCode = GitCommand.revParse(args);
            default:
                Sys.println('Git Command: "$cmd", does not exist.');
        }

        return exitCode;
    }
}
