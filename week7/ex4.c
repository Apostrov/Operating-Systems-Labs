#include <stdlib.h>
#include <malloc.h>

void *myRealloc(void *ptr, size_t size)
{
    if(ptr == NULL) return malloc(size);
    free(ptr);
    if(size == 0) return NULL;
    return malloc(size);
}

int main()
{
    int *pointer = myRealloc(NULL, sizeof(int)*1);
    size_t size_old = malloc_usable_size(pointer);
    printf("%d\n", size_old);
    pointer = myRealloc(pointer, sizeof(int)*100);
    size_t size_new = malloc_usable_size(pointer);
    printf("%d", size_new);
    return 0;
}