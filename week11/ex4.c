#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main()
{
    char *filenameSrc = "ex1.txt";
    char *filenameDest = "ex1.memcpy.txt";
    int fdSource = open(filenameSrc, O_RDONLY);
    int fdDest = open(filenameDest, O_RDWR | O_CREAT);
    
    
    struct stat fileSrc;
    stat(filenameSrc, &fileSrc);

    ftruncate(fdDest, fileSrc.st_size);
    fsync(fdDest);

    void* mapSrc = mmap(NULL, fileSrc.st_size, PROT_READ, MAP_PRIVATE, fdSource, 0);
    void* mapDest = mmap(NULL, fileSrc.st_size, PROT_WRITE, MAP_SHARED, fdDest, 0);

    memcpy(mapDest, mapSrc, fileSrc.st_size);
    msync(mapDest, fileSrc.st_size, MS_SYNC);

    munmap(mapSrc, fileSrc.st_size);
    munmap(mapDest, fileSrc.st_size);
    close(fdSource);
    close(fdDest);
    return 0;
}