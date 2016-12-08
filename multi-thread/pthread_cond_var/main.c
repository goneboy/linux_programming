#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_cond_t is_zero;
pthread_mutex_t mutex;	//Condition variable needs a mutex
int shared_data = 10;

void *thread_func(void *arg)
{
	while(shared_data > 0)
	{
		pthread_mutex_lock(&mutex);
		printf("[child thread]: shared_data = %d\n", shared_data);
		shared_data--;
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	
	//Signal the condition
	pthread_cond_signal(&is_zero);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread_ID;
	void *exit_status;
	//int i;

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&is_zero, NULL);

	pthread_create(&thread_ID, NULL, thread_func, (void *) NULL);

	//Wait for the shared data to reach zero
	pthread_mutex_lock(&mutex);
	
	printf("[parent thread]: Wait for child thread\n");

	while(shared_data != 0)
	{
		pthread_cond_wait(&is_zero, &mutex);
	}

	printf("[parent thread]: I came back and complete the program\n");

	pthread_mutex_unlock(&mutex);
	
	pthread_join(thread_ID, (void *) &exit_status);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&is_zero);
	return 0;
}
