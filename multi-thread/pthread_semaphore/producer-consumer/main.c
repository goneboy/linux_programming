#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define TRUE 1

int product_val;

sem_t semaphore; //Declare a semaphore vatiable

void *do_thread(void *data_in);


int main(int argc, char *argv[])
{
	int i, ret;
	pthread_t thr;
	
	//Create a semaphore object, set value for semaphore is 2
	ret = sem_init(&semaphore, 0, 2);

	if(ret)
	{
		printf("Init error/n");
		exit(EXIT_FAILURE);
	}
	
	//Initialize thread with consumer role
	ret = pthread_create(&thr, NULL, do_thread, (void *) NULL);
	
	//Main thread with producer role		
	for (i = 0; i < 5; i++)
	{
		product_val++;
		printf ("Producer product value = %d \n\n", product_val);
		
		//Increase semaphore, notify that product was added in store
		sem_post(&semaphore);
		sleep(2);
	}

	exit(EXIT_SUCCESS);
}


void *do_thread(void *data_in)
{
	while(TRUE)
	{
		sem_wait(&semaphore);
		product_val--;
		printf ("Consumer product value = %d \n", product_val);
		sleep(1);
	}

	pthread_exit(NULL);
}
