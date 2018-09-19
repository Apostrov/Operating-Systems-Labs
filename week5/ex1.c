#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 20

void *say_hello() 
{
    pthread_t id = pthread_self();
    printf("hello from thread %d!\n", id);
    pthread_exit(0);
}

int main()
{
    pthread_t tid[THREAD_COUNT];
    printf("Start thread creation\n");
    for(int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(&(tid[i]), NULL, say_hello, NULL);
        printf("Create thread: %d\n", tid[i]);
        pthread_join(tid[i], NULL);
    }
    return 0;
}