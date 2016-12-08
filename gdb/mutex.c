#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 5

void *inc(void *data_in);
void *dec(void *data_in); 

int global_var = 0;
pthread_mutex_t mutex_thr;

int main(int argc, char *argv[])
{
	pthread_t thr_id[THREAD_NUM];
	int i; //counter index	
	//int ret; //return value

	printf("Main thread starts...\n");
	sleep(1);

	//create mutex thread
	pthread_mutex_init(&mutex_thr, NULL);
	
	for(i = 0; i < THREAD_NUM; i++)
	{
		thr_id[i] = i;

		pthread_create(&thr_id[i], NULL, inc, (void *) i);
		pthread_create(&thr_id[i], NULL, dec, (void *) i);
	}

	//destroy mutex thread
	pthread_mutex_destroy(&mutex_thr);
	

	for(i = 0; i < THREAD_NUM; i++)
	{
		pthread_join(thr_id[i], NULL);
	}


	return 0;
}

void *inc(void *data_in)
{
	int my_id;
	int tmp;
	my_id = (int) data_in;

	pthread_mutex_lock(&mutex_thr);

	//increase global_var
	global_var++;
	tmp = global_var;
	pthread_mutex_unlock(&mutex_thr);

	printf("[Thread %d]: a = %d\n", my_id, tmp);
}

void *dec(void *data_in)
{
	int my_id;
	int tmp;
	my_id = (int) data_in;

	pthread_mutex_lock(&mutex_thr);

	//decrease global_var
	global_var--;
	tmp = global_var;
	pthread_mutex_unlock(&mutex_thr);

	printf("[Thread %d]: a = %d\n", my_id, tmp);
}


