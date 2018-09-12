#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_SIZE 100

int main()
{
    char command[MAX_CMD_SIZE];
    do
    {
        printf("> ");
        fgets(command, MAX_CMD_SIZE, stdin);
        if(fork() == 0)
            system(command);
    } while(strncmp(command, "exit", 4) != 0);
    return 0;
}