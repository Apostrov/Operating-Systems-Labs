#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter array size:");
    int arraySize;
    scanf("%d", &arraySize);
    int *array = malloc(arraySize * sizeof(int));
    for(int arrayIndex = 0; arrayIndex < arraySize; arrayIndex++)
    {
        array[arrayIndex] = arrayIndex;
    }
    for(int arrayIndex = 0; arrayIndex < arraySize; arrayIndex++)
    {
        printf("%d\n", array[arrayIndex]);
    }
    free(array);
    return 0;
}