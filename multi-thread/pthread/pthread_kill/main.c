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
	int ret, i;

	ret = pthread_create(&thread_id, NULL, do_thread, (void *) 0);

	if(ret)
	{
		printf("Can't create thread\n");
		exit(EXIT_FAILURE);
	}
	
	printf("[Parent thread] Wake up child thread after 10s\n");
	for(i = 10; i > 0; i--)
	{
		printf("%d\n", i);
		sleep(1);
	}

	pthread_kill(thread_id, SIGALRM);	

	pthread_join(thread_id, NULL);	

	return EXIT_SUCCESS;	
}


void *do_thread(void *data_in)
{
	printf("[child thread] Begins to sleep\n");
	printf("...z...z...");
	pause();
	
	while(1)
	{
		printf("[child thread] I wake up\n");
	}

	pthread_exit(NULL);	
}
