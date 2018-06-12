/*
 * This program will wait for time_out seconds and execute a function on timeout. Else, if we get a user input, we will exit
 *
 * This is to demonstrate a program that needs to execute after 'n' seconds without a sleep()and thus be responsive (in this case to user input)
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

typedef int bool;
enum { false, true };

bool gExitProgram = false;

void at_exit_function() {
    printf("at_exit_function\n");
}

void ctrl_c_handler(int sig) {
    gExitProgram = true;
    printf("ctrl_c_handler sig: %d\n", sig);
}

void runTheMethod(void *arg) {
    int *pCount = (int *) arg;
    printf("runTheMethod: %d\n", *pCount);
}

bool wait_in_loop(int timeOutInMsecs, void (*func)(void *)) {
    struct timeval tWaitTime;
    fd_set fdInput;
    bool exitLoop;
    int n;
    char ch;
    int count;

    count = 0;
    exitLoop = false;
    while ((gExitProgram == false) && (exitLoop == false)) {
        tWaitTime.tv_sec = (timeOutInMsecs / 1000);
        tWaitTime.tv_usec = (timeOutInMsecs % 1000) * 1000;

        FD_ZERO(&fdInput);
        FD_SET(STDIN_FILENO, &fdInput);
        n = (int) STDIN_FILENO + 1;

        printf ("Count = %d\n", ++count);
        if (select(n, &fdInput, NULL, NULL, &tWaitTime)) {
            //Means the user pressed <enter> at stdin
            exitLoop = true;
        } else {
            // Execute the function passed if no user input detected
            func((void *)&count);
        }
    }
    printf ("Count at exit = %d\n", count);
    return true;
}

int main(int argc, char *argv[]) {
    (void) signal (SIGINT, ctrl_c_handler);
    (void) signal (SIGQUIT, ctrl_c_handler);

    atexit(at_exit_function);

    wait_in_loop(1000, runTheMethod);
    return 0;
}
