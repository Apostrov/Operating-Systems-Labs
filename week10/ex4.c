#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

typedef struct File File;

struct File
{
    long inode;
    char *name;
    char *links[20];
    int linkCount;
};

int main()
{
    DIR *tmpDir;
    tmpDir = opendir("tmp");
    if(tmpDir == NULL)
    {
        return -1;
    }
    
    struct dirent *tmpDirFile;
    File files[10];
    memset(files, 0, sizeof(File) * 10);
    int fileCount = 0, link = 0;
    while((tmpDirFile = readdir(tmpDir)) != NULL)
    {
        link = 0;
        for(int fileIndex = 0; fileIndex < fileCount; fileIndex++)
        {
            if(files[fileIndex].inode == tmpDirFile->d_ino)
            {
                link = 1;
                int index = files[fileCount].linkCount;
                files[fileIndex].links[index] = tmpDirFile->d_name;
                files[fileIndex].linkCount++;
            }
        }

        if(!link)
        {
            files[fileCount].inode = tmpDirFile->d_ino;
            files[fileCount].name = tmpDirFile->d_name;
            files[fileCount].linkCount = 0;
            fileCount++;
        }
    }

    FILE *outputFile = fopen("ex4.txt", "a");
    for(int fileIndex = 0; fileIndex < fileCount; fileIndex++)
    {
        fprintf(outputFile, files[fileIndex].name);
        fprintf(outputFile, ":\n");
        for(int linkIndex = 0; linkIndex < files[fileIndex].linkCount; linkIndex++)
        {
            fprintf(outputFile, "- ");

            fprintf(outputFile, files[fileIndex].links[linkIndex]);
            fprintf(outputFile, "\n");
        }
    }

    fclose(outputFile);
    return 0;
}