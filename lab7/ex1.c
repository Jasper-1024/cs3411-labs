#include "circle.h"
#include <pthread.h>
#define NUM_THREADS 1
/* shared variable for the threads to update */
volatile int var = -1;
pthread_mutex_t lock;

void *
wrapper(__attribute__((unused)) void *v){
    pthread_mutex_lock(&lock);
    if(var == -1){
        var = circle();
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}


int
main(void)
{
	/* number of samples */
	int niters = 10000;
	int count = 0;
	int i = 0;
    pthread_t pid;
    //pthread_create(&pid, NULL, &wrapper, NULL); 
	for(i = 0; i < niters; i++) {
        pthread_create(&pid, NULL, &wrapper, NULL); 

        if(var == 0 || var == 1){
            if(var == 1){
                count++;
            }
            var = -1;
        }
        pthread_join(pid, NULL);
    //    if (circle() == 1)
	//		count++;
	}

	printf("The value of pi is: %f\n", (double)count / niters * 4);

	return 0;
}
