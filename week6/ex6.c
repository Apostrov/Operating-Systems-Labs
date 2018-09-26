#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int mypipe[2];
    pipe(mypipe);
    pid_t child1 = fork();
    if(child1 == 0)
    {
        printf("First child start\n");
        pid_t child2;
        read(mypipe[0], &child2, sizeof(child2));
        printf("Read from pipe child2 pid\n");
        sleep(3);
        kill(child2, SIGSTOP);
        printf("Send SIGSTOP to child2\n");
        exit(0);
    }
    else
    {
        pid_t child2 = fork();
        if(child2 == 0)
        {
            printf("Second child start\n");
            while(1) {
                printf("Child2 alive\n");
                sleep(1);
            }
        } else {
            write(mypipe[1], &child2, sizeof(child2));
            printf("Send to pipe child2 pid\n");
            printf("Wait child2\n");
            int *status;
            waitpid(child2, status, 0);
            printf("Parent awake\n");
        }
    }
    return 0;
}