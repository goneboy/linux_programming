#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_NUM 6

char message[] = "Bao Trung";

void *do_thread(void *data_in);

int main(int argc, char *argv[])
{
	pthread_t thr[THREAD_NUM];
	int i, ret, thr_return;
	
	//Create the threads
	for(i = 1; i < THREAD_NUM; i++)
	{
		ret = pthread_create(&thr[i], NULL, do_thread, (void *) i);
		if(ret)
		{
			printf("Can't create thread: %d\n", i);
			exit(EXIT_FAILURE);
		}
	}

	//Waiting for thread end
	for(i = THREAD_NUM - 1; i > 0; i--)
	{
		ret = pthread_join(thr[i], (void *) &thr_return);
		//printf("ret = %d, thread return = %d\n", ret, thr_return);
	}
	
	printf("Done\n");
}


void *do_thread(void *data_in)
{
	int my_number;
	my_number = (int) data_in;
	printf("The argument is: %d\n", my_number);
	//sleep(3);
	printf("Finished\n");	
}
