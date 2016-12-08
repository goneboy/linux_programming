#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define THREAD_NUM 5

int global_var;

//Declare global mutex var 
pthread_mutex_t a_mutex;

//Thread function
void *do_thread1(void *data_in);
void *do_thread2(void *data_in);


int main(int argc, char *argv[])
{
	int ret, i;
	pthread_t thr_1, thr_2;

	//Initialize mutex
	ret = pthread_mutex_init(&a_mutex, NULL);
	// or a_mutex = PTHREAD_MUTEX_INITIALIZER;
	
	if(ret)
	{
		perror ("Mutex create error");
		exit (EXIT_FAILURE);
	}

	//Create 1st thread
	ret = pthread_create(&thr_1, NULL, do_thread1, NULL);
	
	if(ret)
	{
		perror ("Thread create error");
		exit (EXIT_FAILURE);
	}

	//Create 2nd thread
	ret = pthread_create(&thr_2, NULL, do_thread2, NULL);
	
	if(ret)
	{
		perror ("Thread create error");
		exit (EXIT_FAILURE);
	}

	//Main thread
	/*for (i = 1; i < 20; i++)
	{
		printf ("Main thread waiting %d second \n", i);
		sleep (1);
	} */	

	pthread_exit(NULL);

	return 0;				
}


void *do_thread1(void *data_in)
{
	int i;
	//pthread_mutex_lock(&a_mutex); //Lock mutex
	
	for(i = 1; i <= THREAD_NUM; i++)
	{
		pthread_mutex_lock(&a_mutex); //Lock mutex
		global_var++;
		pthread_mutex_unlock(&a_mutex); //Unlock mutex	
		printf("Thread 1 counts: %d with global variable value: %d\n", i, global_var);
		sleep(1);
	}

	//pthread_mutex_unlock(&a_mutex); //Unlock mutex
	printf("Thread 1 completed\n");
}


void *do_thread2(void *data_in)
{
	int i;
	//pthread_mutex_lock(&a_mutex); //Lock mutex
	
	//sleep(1);
	for(i = 1; i <= THREAD_NUM; i++)
	{
		pthread_mutex_lock(&a_mutex); //Lock mutex
		global_var--;
		pthread_mutex_unlock(&a_mutex); //Unlock mutex
		printf("Thread 2 counts: %d with global variable value: %d\n", i, global_var);
		sleep(1);
	}

	//pthread_mutex_unlock(&a_mutex); //Unlock mutex
	printf("Thread 2 completed\n");	
}

