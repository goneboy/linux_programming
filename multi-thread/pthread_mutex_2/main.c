#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define THREAD_NUM 5


//Declare global mutex var 
pthread_mutex_t a_mutex;

int counter = 0;
//Thread function
void *do_thread(void *data_in);


int main(int argc, char *argv[])
{
	pthread_t thr[3];
	int ret, i;
	int arg[3] = {1, 2, 3};
	
	pthread_mutex_init(&a_mutex, NULL);

	//Create thread 1
	ret = pthread_create(&thr[0], NULL, do_thread, (void *) arg[0]);
	
	if(ret)
	{
		printf("Can't create thread\n");
		exit(EXIT_FAILURE);	
	}		
	
	//Create thread 2
	ret = pthread_create(&thr[1], NULL, do_thread, (void *) arg[1]);
	
	if(ret)
	{
		printf("Can't create thread\n");
		exit(EXIT_FAILURE);	
	}
	
	//Create thread 3
	ret = pthread_create(&thr[2], NULL, do_thread, (void *) arg[2]);
	
	if(ret)
	{
		printf("Can't create thread\n");
		exit(EXIT_FAILURE);	
	}

	for(i = 0; i < 3; i++)
	{
		pthread_join(thr[i], NULL);
	}

	pthread_mutex_destroy(&a_mutex);
	
	return 0;				
}
void set_counter(int val) {
	
	//lock
	counter = val;
	//unlock
}
int get_counter() {
	int val;
	//lock
	val = counter;
	//unlock
	return val;
}

void *do_thread(void *data_in)
{
	int var, val;
	var = (int) data_in;

	pthread_mutex_lock(&a_mutex);

	counter++;
	val = counter;
	//sleep(1);
	//printf("[Thread %d] Counter value: %d\n", var, counter);

	pthread_mutex_unlock(&a_mutex);
	
	printf("[Thread %d] Counter value: %d\n", var, counter);
}
	


