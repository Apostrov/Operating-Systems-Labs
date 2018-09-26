#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler() 
{
    printf("\nCatch SIGINT\n");
}

int main()
{
    signal(SIGINT, signalHandler);
    sleep(2);
    return 0;
}