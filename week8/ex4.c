#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    struct rusage usage;
    int tenMB = 10 * 1024 * 1024;
    for(int seconds = 0; seconds < 10; seconds++)
    {
        void *ptr = malloc(tenMB);
        memset(ptr, 0, tenMB);
        getrusage(RUSAGE_SELF, &usage);
        printf("%d\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}
