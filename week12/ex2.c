#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int aflag = 0, isfile[argc], files_count = 0;
    for (int argIndex = 0; argIndex < argc; argIndex++)
    {
        if (strcmp(argv[argIndex],"-a") == 0)
        {
            aflag = 1;
            isfile[argIndex] = 0;
            files_count++;
        }
        else if (strcmp(argv[argIndex], "./mytee") != 0)
        {
            isfile[argIndex] = 1;
            files_count++;
        }
        else
        {
            isfile[argIndex] = 0;
            files_count++;
        }
    }

    char output[1024];
    fgets(output, 1024, stdin);
    FILE *file;

    for (int i = 0; i < argc; i++)
    {
        if (isfile[i])
        {
            if (aflag)
            {
                file = fopen(argv[i], "a+");
            }
            else
            {
                file = fopen(argv[i], "w+");
            }

            fprintf(file, output);
        }
    }

    fclose(file);
    return 0;
}