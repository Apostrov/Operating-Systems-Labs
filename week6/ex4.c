#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signal) 
{
    printf("\nCatch %d\n", signal);
}

int main()
{
    signal(SIGKILL, signalHandler);
    signal(SIGSTOP, signalHandler);
    signal(SIGUSR1, signalHandler);
    sleep(10);
    return 0;
}