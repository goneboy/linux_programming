#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_NUM 3
#define TCOUNT 10
#define COUNT_LIMIT 12

int counter = 0;	
int thread_ids[THREAD_NUM] = {0, 1, 2};
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void *inc_counter(void *data_in);
void *watch_counter(void *data_in);

int main(int argc, char *argv[])
{
	int i;
	long t1 = 1, t2 = 2, t3 = 3;
	pthread_t threads[THREAD_NUM];
	
	/* Initialize mutex and condition variable objects */
	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init(&count_threshold_cv, NULL);
	
	/* For portability, explicitly create threads in a joinable state */
	pthread_create(&threads[0], NULL, watch_counter, (void *) t1);
	pthread_create(&threads[1], NULL, inc_counter, (void *) t2);
	pthread_create(&threads[2], NULL, inc_counter, (void *) t3);
	
	/* Wait for all threads to complete */
	for(i = 0; i < THREAD_NUM; i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	printf ("Main(): Waited on %d  threads. Done.\n", THREAD_NUM);

	/* Clean up and exit */
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);
	pthread_exit(NULL);
}

void *inc_counter(void *data_in)
{
	int i;
	long my_id;
	my_id = (long) data_in;
	
	for(i = 0; i < TCOUNT; i++)
	{
		pthread_mutex_lock(&count_mutex);
		counter++;
		
		/* 
		Check the value of count and signal waiting thread when condition is
		reached.  Note that this occurs while mutex is locked. 
		*/
		if(counter == COUNT_LIMIT)
		{
			pthread_cond_signal(&count_threshold_cv);
			printf("[inc_counter()]: thread %ld, counter = %d. Threshold reached\n", my_id, counter);
		}
		
		printf("[inc_counter()]: thread %ld, counter = %d. Unlocking mutex\n", my_id, counter);
		
		pthread_mutex_unlock(&count_mutex);
		
		/* Do some "work" so threads can alternate on mutex lock */
		sleep(1);
	}
	pthread_exit(NULL);
}

void *watch_counter(void *data_in)
{
	long my_id;
	my_id = (long) data_in;
		
	printf("Starting watch_count(): thread %ld\n", my_id);
	
	/*
	Lock mutex and wait for signal.  Note that the pthread_cond_wait 
	routine will automatically and atomically unlock mutex while it waits. 
	Also, note that if COUNT_LIMIT is reached before this routine is run by
	the waiting thread, the loop will be skipped to prevent pthread_cond_wait
	from never returning. 
	*/

	pthread_mutex_lock(&count_mutex);
	
	while(counter < COUNT_LIMIT)
	{
		pthread_cond_wait(&count_threshold_cv, &count_mutex);
		printf("[watch_count()]: thread %ld Condition signal received.\n", my_id);
		counter += 125;
		printf("[watch_count()]: thread %ld count now = %d.\n", my_id, counter);
	}

	pthread_mutex_unlock(&count_mutex);
	pthread_exit(NULL);
}
