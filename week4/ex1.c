#include <stdio.h>
#include <unistd.h>

int main()
{
    int n = 1111;
    printf("Hello from parent %d\n", getpid() - n);
    fork();
    printf("Hello from child %d\n", getpid() - n);
    return 0;
}