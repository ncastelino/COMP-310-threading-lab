#include<stdio.h>
#include<pthread.h>

void * view(void * t)
{
  printf("Thread 2");
}

int main()
 {
   pthread_t new;
   pthread_create(&new, NULL, &view, NULL);
   printf("Thread 1");

   pthread_join(new,NULL);
   return 0;

}
