#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
pthread_cond_t cond;
pthread_mutex_t mutex;
void* route_t1(void* arg)
{
    while(1)
    {
        pthread_cond_wait(&cond,&mutex);
        printf("i am thread A\n");
    }
}
void* route_t2(void* arg)
{
    while(1)
    {
        pthread_cond_signal(&cond);
        printf("i am thread B\n");
        sleep(1);
    }
}
int main()
{
    pthread_t t1,t2;
    pthread_cond_init(&cond,NULL);
 //   pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1,NULL,route_t1,(void**)"thread 1");
    pthread_create(&t2,NULL,route_t2,(void**)"thread 2");

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_cond_destroy(&cond);
//    pthread_mutex_destroy(&mutex);

}
