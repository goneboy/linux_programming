#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void child_process(void);
void parent_process(void);

int main(int argc, char *argv[])
{
	pid_t my_process;
	int child_status;

	my_process = fork();

	switch(my_process)
	{
		//fork() successfully, we're child process
		case 0:
		{
			child_process();
			break;
		}

		case -1:
		{
			printf("Can't create child process\n");
			break;
		}
		
		//fork() successfully, we're parent process
		default:
		{
			parent_process();

			//Wait for child process ending
			printf("Wait for child process ending\n");
			wait(&child_status);
			printf("Done\n");
			printf("PID of parent: %d, PID of child: %d\n", getpid(), my_process);
			break;
		}
	}	

	return 0;
}

void child_process(void)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("Hello child process\n");
		sleep(1);
	}
	
	return;
}

void parent_process(void)
{
	int i;
//	for(i = 0; i < 5; i++)
//	{
//		printf("Hello parent process\n");
//		//sleep(1);
//	}
	
	printf("Hello parent process\n");

	//sleep(1);
	return;
}