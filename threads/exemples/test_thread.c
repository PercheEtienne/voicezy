#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define NB_THREADS 1
void* do_something(){
    while(1){
        sleep(2);
        printf("test\n");
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]){

    int pid, j;
    pthread_t th;
    void * ret;

    for (j = 0; j < NB_THREADS; j++)
    {
        pthread_create(&th, NULL,do_something,NULL);
    }
    sleep(30);
    pthread_cancel(th);
//    for (j = 0; j < NB_THREADS; j++)
//    {
//        pthread_join(th, &ret);
//    }

    return EXIT_SUCCESS;
}