#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_NUM 5

char message[] = "Bao Trung";

void *do_thread(void *data_in);

int main(int argc, char *argv[])
{
	pthread_t thr;
	int ret, thr_return;
	
	//Create thread
	ret = pthread_create(&thr, NULL, do_thread, (void *) NULL);

	if(ret)
	{
		printf("Can't create thread\n");
		exit(EXIT_FAILURE);	
	}

	//Waiting for thread end
	sleep(1);
	printf("Waiting for thread end\n");

	ret = pthread_join(thr, (void *) &thr_return);
	
	if(ret)
	{
		printf("Waiting error\n");
		exit(EXIT_FAILURE);	
	}

	printf("Thread complete!\n");

}


void *do_thread(void *data_in)
{
	int thread_id;
	thread_id = (int) data_in;
	//strcpy(message, "Ngoc Tuyen");	
	printf("This is new thread\n");	
	sleep(5);
	pthread_exit(NULL);
}
