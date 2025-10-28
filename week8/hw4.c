#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

void signal_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Signal handler invoked for signal %d\n", signum);
        sleep(1);
    }
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("error: could not register signal handler");
        return 1;
    }

    pid_t pid = getpid();
    printf("PID is %d\n", pid);

    // Send SIGUSR1 twice
    kill(pid, SIGUSR1);
    kill(pid, SIGUSR1);

    printf("waiting for signals to complete\n");
    sleep(3);

    return 0;
}