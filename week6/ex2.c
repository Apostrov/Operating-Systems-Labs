#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    char strIn[] = "Hello from pipe";
    char strOut[80];
    int mypipe[2];
    pipe(mypipe);
    pid_t pid = fork();
    if(pid == 0)
    {
        read(mypipe[0], strOut, sizeof(strOut));
        printf("%s\n", strOut);
    }
    else
    {
        write(mypipe[1], strIn, strlen(strIn) + 1);
    }
    return 0;
}