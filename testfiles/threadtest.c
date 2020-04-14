#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *use(void *var)

{
     sleep(2);
     printf("This is a thread");
     return NULL;
}

int main()
{
    pthread_t t_id;
    printf("Other thread \n");
    pthread_create(&t_id, NULL, use, NULL);
    pthread_join(t_id, NULL);

    printf("Thread after \n");

    exit(0);

}
