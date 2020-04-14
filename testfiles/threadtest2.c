#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int d=0;
void *use(void *var)

{
    int *id = (int *)var;
    static int i = 0;

    i = 5;
    d = 5;

    printf("Thread 1: %d", *id);
    printf("Thread 2: %d", i);
    printf("Thread 3: %d", d);
}

int main()
{
    pthread_t th_id;

    for(int i=0; i<9; i++)
    {
         pthread_create(&th_id, NULL, use, (void*)&th_id);
    }

    pthread_exit(NULL);
    return 0;
}
