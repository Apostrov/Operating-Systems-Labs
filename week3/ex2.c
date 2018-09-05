#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int *arr, int size)
{
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        for(int j = 1; j < size; j++)
        {
            if(arr[j - 1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                swapped = true;
            }
        }
        size--;
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int array[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    bubbleSort(array, size);
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
