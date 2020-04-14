#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//help from linuxhint site and Neil video

pthread_mutex_t locked;

int b;

void procfunc()
{
     pthread_mutex_lock(&locked);
    
     int i=0;

     b++;

     while(i <6)
{
     printf("%d", b);
     sleep(3);
     i++;
}

    printf("Done");
    pthread_mutex_unlock(&locked);

}

int main()
{
    int error;
    pthread_t num1, num2;

    if( pthread_mutex_init(&locked, NULL) !=0)
   {
     printf("Mutex Unsuccessful");
     exit(0);

}
     b=0;
      
     pthread_create(&num1, NULL, procfunc, NULL);
     pthread_create(&num2, NULL, procfunc, NULL);

     pthread_join(num1, NULL);
     pthread_join(num2, NULL);

     return 0;
}
