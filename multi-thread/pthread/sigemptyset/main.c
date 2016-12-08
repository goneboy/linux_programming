#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void print(sigset_t set, int sig_num)
{
	printf("Set %8.8lx, signal %d  is ", set, sig_num);

	if(sigismember(&set, sig_num))
	{
		printf("a member\n");
	}
	else
	{
		printf("not a member\n");
	}
}

int main(int argc, char *argv[])
{
	sigset_t my_set;
	
	sigemptyset(&my_set);
	print(my_set, SIGINT);

	sigfillset(&my_set);
    	print(my_set, SIGINT);

	sigdelset(&my_set, SIGINT);
	print(my_set, SIGINT);

	sigaddset(&my_set, SIGINT);
	print(my_set, SIGINT);

	return EXIT_SUCCESS;	
}
