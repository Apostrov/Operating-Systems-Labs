#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("%c", 'H');
    sleep(1);
    printf("%c", 'e');
    sleep(1);
    printf("%c", 'l');
    sleep(1);
    printf("%c", 'l');
    sleep(1);
    printf("%c", 'o');
    sleep(1);
    printf("%c", '\n');
    return 0;
}