#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int tenMB = 10 * 1024 * 1024;
    for(int seconds = 0; seconds < 10; seconds++)
    {
        char *ptr = malloc(tenMB);
        memset(ptr, '0', tenMB);
        sleep(1);
    }
    return 0;
}
