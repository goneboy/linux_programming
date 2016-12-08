#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

#define TRUE 1
#define THREAD_NUM 5

int counter = 0;

void signal_handler(void);
void *do_thread(void *data_in);


int main(int argc, char *argv[])
{
	pthread_t thread_id;
	int ret;

	//printf("This is parent thread\n");

	pthread_create(&thread_id, NULL, do_thread, (void *) 0);

	printf("This is parent thread\n");
	sleep(10);

	ret = pthread_kill(thread_id, SIGALRM);
	
	pthread_join(thread_id, NULL);
	

	return EXIT_SUCCESS;	
}


void signal_handler(void)
{
	int i, a = 0;
	printf("When target thread receives signal\nIt will be stopped for the signal handler\n");
	printf("Begin implementation is signal handler function\n");
	
	for(i = 0; i < 10; i++)
	{
		printf("[signal handler]: %d\n", a++);
		sleep(1);
	}
	printf("Complete the signal handler fucntion\n");
}


void *do_thread(void *data_in)
{
	//int i;

	while(TRUE)
	{
		printf("This is child thread %d\n", counter++);
		sleep(1);
		signal(SIGINT, (void *) signal_handler);
	}

	pthread_exit(NULL);	
}
