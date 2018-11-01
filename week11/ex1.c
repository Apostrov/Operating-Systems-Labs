#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int main()
{
    char *filename = "ex1.txt";
    char *text = "This is a nice day";
    int fd = open(filename, O_RDWR | O_CREAT);

    ftruncate(fd, strlen(text));
    fsync(fd);
    
    void* map = mmap(NULL, strlen(text), PROT_WRITE, MAP_SHARED, fd, 0);
    memcpy(map, text, strlen(text));
    msync(map, strlen(text), MS_SYNC);
    munmap(map, strlen(text));
    close(fd);
    return 0;
}