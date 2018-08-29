#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;
    sscanf(argv[1], "%d", &n);
    int length = 2*n - 1;
    for(int i = n - 1; i >= 0; i--)
    {
        for(int s = 0; s < i; s++)
        {
            printf(" ");
        }
        for(int w = 0; w < length - 2*i; w++)
        {
            printf("*");
        }
        for(int s = 0; s < i; s++)
        {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}