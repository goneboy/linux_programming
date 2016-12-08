#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 6

int global_var;

pthread_mutex_t mutex_thr;

void *do_thread_1(void *data_in);
void *do_thread_2(void *data_in);


int main(int argc, char *argv[])
{
	int ret;
	pthread_t thr_1;
	pthread_t thr_2;
	
	//Create the MUTEX thread
	ret = pthread_mutex_init(&mutex_thr, NULL);
	//or mutex_thr = PTHREAD_MUTEX_INITIALIZER; --> Quickly MUTEX
	//or mutex_thr = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP --> Recursive MUTEX

	if(ret)
	{
		printf("Initialize MUTEX error\n");
		exit(EXIT_FAILURE);
	}
		
	//Create thread 1
	ret = pthread_create(&thr_1, NULL, do_thread_1, 0);
	
	if(ret)
	{
		printf("Create thread 1 error\n");
		exit(EXIT_FAILURE);
	}

	//Create thread 1
	ret = pthread_create(&thr_2, NULL, do_thread_2, 0);
	
	if(ret)
	{
		printf("Create thread 2 error\n");
		exit(EXIT_FAILURE);
	}

	pthread_exit(NULL);
	//printf("Done");

	return 0;
}


void *do_thread_1(void *data_in)
{
	int i;	
	pthread_mutex_lock(&mutex_thr); //MUTEX lock
	
	for(i = 0; i < THREAD_NUM; i++)
	{
		printf("Global variable in thread 1 is: %d\n", global_var++);
		sleep(0);
	}

	pthread_mutex_unlock(&mutex_thr); //MUTEX unlock

}


void *do_thread_2(void *data_in)
{
	int i;	
	pthread_mutex_lock(&mutex_thr); //MUTEX lock
	
	for(i = 0; i < THREAD_NUM; i++)
	{
		printf("Global variable in thread 2 is: %d\n", global_var--);
		sleep(0);
	}

	pthread_mutex_unlock(&mutex_thr); //MUTEX unlock	
}

