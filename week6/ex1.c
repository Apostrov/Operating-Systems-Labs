#include <stdio.h>
#include <unistd.h>

int main()
{
    char strIn[] = "Hello from pipe";
    char strOut[80];
    int mypipe[2];
    pipe(mypipe);
    write(mypipe[1], strIn, sizeof(strIn));
    read(mypipe[0], strOut, sizeof(strOut));
    printf("%s\n", strOut);
    return 0;
}