#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */

void *do_thread(void *data_in);


sem_t mutex; //The semaphore was used is mutex

int counter;


int main(int argc, char *argv[])
{
	//int arg[2] = {1, 2};
	int arg[5] = {1, 2, 3, 4, 5};
	int i;
	pthread_t thr[5];

	sem_init(&mutex, 0, 3);
		
	//pthread_create(&thr[0], NULL, do_thread, (void *) arg[0]);

	//pthread_create(&thr[1], NULL, do_thread, (void *) arg[1]);

	for(i = 0; i < 5; i++)
	{
		pthread_create(&thr[i], NULL, do_thread, (void *) arg[i]);
	}

	for(i = 0; i < 5; i++)
	{
		pthread_join(thr[i], NULL);
	}
	
	sem_destroy(&mutex);

	exit(EXIT_SUCCESS);
}


void *do_thread(void *data_in)
{
	int x, sem_value;
	x = (int) data_in;

	printf("Thread %d: Waiting to enter critical region...\n", x);

    	sem_wait(&mutex);       /* down semaphore */
   	
    	printf("Thread %d: Now in critical region...\n", x);
    	printf("Thread %d: Counter Value: %d\n", x, counter);
    	printf("Thread %d: Incrementing Counter...\n", x);

    	counter++;
    	printf("Thread %d: New Counter Value: %d\n", x, counter);
    	printf("Thread %d: Exiting critical region...\n", x);
	printf("\n");
    
    	sem_post(&mutex);       /* up semaphore */

    	pthread_exit(0); /* exit thread */	
}

