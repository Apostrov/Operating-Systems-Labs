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
        printf("CHILD 1: Start\n");
        pid_t child2;
        read(mypipe[0], &child2, sizeof(child2));
        printf("CHILD 1: Read from pipe child2 pid\n");
        sleep(3);
        kill(child2, SIGSTOP);
        printf("CHILD 1: Send SIGSTOP to child2\n");
        exit(0);
    }
    else
    {
        pid_t child2 = fork();
        if(child2 == 0)
        {
            printf("CHILD 2: Start\n");
            while(1) {
                printf("CHILD 2: Alive\n");
                sleep(1);
            }
        } else {
            write(mypipe[1], &child2, sizeof(child2));
            printf("PARENT: Send to pipe child2 pid\n");
            printf("PARENT: Wait child2\n");
            int *status;
            waitpid(child2, status, WUNTRACED);
            printf("PARENT: Parent awake\n");
        }
    }
    return 0;
}