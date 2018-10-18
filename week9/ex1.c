#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int pageNumber;
    sscanf(argv[1], "%d", &pageNumber);

    int page[pageNumber];
    int pageMap[pageNumber];
    for(int pageIndex = 0; pageIndex < pageNumber; pageIndex++)
    {
        page[pageIndex] = 0;
        pageMap[pageIndex] = -1;
    }

    FILE *inputFile = fopen("input.txt", "r");

    int readInt = 0;
    int hit = 0, miss = 0, hitted = 0;
    while(fscanf(inputFile, "%d", &readInt) == 1)
    {
        hitted = 0;
        for(int pageIndex = 0; pageIndex < pageNumber; pageIndex++)
        {
            page[pageIndex] = page[pageIndex] >> 1;
            if(pageMap[pageIndex] == readInt)
            {
                hitted = 1;
                page[pageIndex] = page[pageIndex] | 0b10000000;
                hit++;
            }
        }

        if(hitted == 0)
        {
            miss++;
            int min = 0b11111111, minIndex = 0;
            for(int pageIndex = 0; pageIndex < pageNumber; pageIndex++)
            {
                if(pageMap[pageIndex] == -1)
                {
                    minIndex = pageIndex;
                    break;   
                }
                else if(min < page[pageIndex])
                {
                    minIndex = pageIndex;
                    min = page[pageIndex];
                }
            }

            page[minIndex] = 0b10000000;
            pageMap[minIndex] = readInt;
        }
    }
    printf("hit: %d /miss: %d\n", hit, miss);
    fclose(inputFile);
    return 0;
}
