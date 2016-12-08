#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int sig_num_in)
{
	printf("Signal to stop program: %d has been received\n" , sig_num_in);
	exit(sig_num_in);	
}

int main(int argc, char *argv[])
{
	int a = 0;
	signal(SIGINT, signal_handler);
	
	while(1)
	{
		printf("%d\n", a++);
		usleep(100000);
	}

	return 0;
}

