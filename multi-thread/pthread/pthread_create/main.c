#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define THREAD_NUM 5

void *do_thread(void *data_in);

int main(int argc, char *argv[])
{
	pthread_t threads[THREAD_NUM];
	int i, ret, thr_result;
	int thr_id[THREAD_NUM];	

	//Create 5 threads
	for(i = 0; i < THREAD_NUM; i++)
	{
		//printf("Begin to create the threads\n");
		thr_id[i] = i;
		ret = pthread_create(&threads[i], NULL, do_thread, (void *) thr_id[i]);

		if(ret)
		{
			printf("Can't create thread %d\n", i);
			exit(EXIT_FAILURE);
		}
		//sleep(1);
	}	
	
	for(i = 0; i < THREAD_NUM; i++)
	{
		thr_result = pthread_join(threads[i], (void *) &thr_result);
	}

}


void *do_thread(void *data_in)
{
	int thread_id;
	thread_id = (int) data_in;
	printf("Thread ID: %d\n", thread_id);
	pthread_exit(NULL);
}
