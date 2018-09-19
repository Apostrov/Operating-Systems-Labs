#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int producerSleep = 1;
int consumerSleep = 1;
int buffer = 0;

void *add_to_buffer()
{
    while(1)
    {
        while(producerSleep){}
        if(buffer < BUFFER_SIZE)
        {
            buffer++;
            printf("%d\n", buffer);
            sleep(1);
        }
        else
        {
            producerSleep = 1;
            consumerSleep = 0;
        }
    }
}

void *remove_from_buffer()
{
    while(1)
    {
        while(consumerSleep){}
        if(buffer > 0)
        {
            buffer--;
            printf("%d\n", buffer);
            sleep(1);
        }
        else
        {
            consumerSleep = 1;
            producerSleep = 0;
        }
    }
}

int main()
{
    pthread_t producer, consumer;
    producerSleep = 0;
    pthread_create(&producer, NULL, add_to_buffer, NULL);
    pthread_create(&consumer, NULL, remove_from_buffer, NULL);
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    return 0;
}