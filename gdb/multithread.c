#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define THREAD_NUM 2

void *do_thread_1(void *data_in);
void *do_thread_2(void *data_in);
void assign(int *, int);


int main(int argc, char *argv[])
{
	pthread_t thr_id[THREAD_NUM];
	int i;	

	printf("Main thread start...\n");	
	sleep(1);

	for(i = 0; i < THREAD_NUM; i++)
	{
		thr_id[i] = i;

		if(i % 2 == 0)
		{
			pthread_create(&thr_id[i], NULL, do_thread_1, (void *) i);
		}
		else
		{
			pthread_create(&thr_id[i], NULL, do_thread_2, (void *) i);
		}
	}

	for(i = 0; i < THREAD_NUM; i++)
	{
		pthread_join(thr_id[i], NULL);
	}


	return 0;
}

void *do_thread_1(void *data_in)
{
	int my_id;
	my_id = (int) data_in;	

	printf("Thread %d:\n", my_id);	
	int a;
	assign(&a, 10);
	printf("a = %d\n", a);	

	pthread_exit(NULL);
}


void *do_thread_2(void *data_in)
{
	int my_id;
	my_id = (int) data_in;

	printf("Thread %d:\n", my_id);	
	int *b;
	b = malloc(sizeof(int));
	assign(b, 20);
	printf("*b = %d\n", *b);		
	free(b);
	
	pthread_exit(NULL);
}

void assign(int *ptr_in, int data_in)
{
	*ptr_in = data_in;
}

