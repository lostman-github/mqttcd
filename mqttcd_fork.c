/* vim: set et fenc=utf-8 ff=unix ts=4 sw=4 sts=4 : */

#include "mqttcd_fork.h"

int fork_current_process(int* pid) {
    int ret = fork();

    // fork is failed
    if (ret == -1) {
        return MQTTCD_FORK_FAILED;
    }

    *pid = ret;

    // parent process
    if (ret != 0) {
        return MQTTCD_SUCCEEDED;
    }

    // child process
    // close stdin, stdout, stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    // create new session (disconnect from current terminal)
    setsid();
    // change working directory
    chdir("/");
    // reset umask
    umask(0);
    // ignore SIGCHLD for avoiding zombie process
    signal(SIGCHLD, SIG_IGN);

    return MQTTCD_SUCCEEDED;
}
