#include <stdlib.h>

int main()
{
    system("dd if=/dev/random of=ex1.txt bs=1 count=20 status=none");
    return 0;
}