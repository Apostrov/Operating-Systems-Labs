#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[20];
    do
    {
        printf("> ");
        scanf("%s", command);
        system(command);
    } while(strcmp(command, "exit") != 0);
    return 0;
}