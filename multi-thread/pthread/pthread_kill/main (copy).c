#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void *do_thread(void *data_in)
{
	int thread_num, ret;
	thread_num = (int) data_in;
	sigset_t set;
	int sig;	

	printf("Thread %d is executing\n", thread_num);
	ret = sigemptyset(&set);

	if(ret == 0)
	{
		printf("Initialize set successfully\n");
	}

	if((sigaddset(&set, SIGUSR1)) == -1)
	{
		printf("Add signal to set error\n");
		pthread_exit((void *) 1);
	}

	if((sigwait(&set, &sig)) != SIGUSR1)
	{
		printf("Wait for signal error\n");
		pthread_exit((void *) 2);
	}

	pthread_exit(0);	
}

int main(int argc, char *argv[])
{
	pthread_t thr_id;
	int ret;
	int thr_param = 1;	
	int thread_return;	

	ret = pthread_create(&thr_id, NULL, do_thread, (void *) thr_param);

	if(ret)
	{
		printf("Can't create thread\n");
		exit(EXIT_FAILURE);
	}

	sleep(5);

	ret = pthread_kill(thr_id, SIGUSR1);
	
	if(ret)
	{
		printf("pthread_kill() failed\n");
	}

	ret = pthread_join(thr_id, (void *)&thread_return);

	if(ret)
	{
		printf("pthread_join() failed\n");
	}
	
	return EXIT_SUCCESS;	
}
