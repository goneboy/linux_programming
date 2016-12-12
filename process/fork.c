#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t child_pid; //pid_t <-> int	
	
	printf("The main process ID is %d\n", (int) getpid());
	
	child_pid = fork();
	
	if(child_pid != 0)
	{
		printf("[Parent process] Hello, I'm Parent. My process ID is %d\n", (int) getpid());	
		printf("[Parent process] The child process ID is %d\n", (int) child_pid);
	}
	else
	{
		printf("[Child process] Hello, I'm Child. My process ID is %d\n", (int) getpid());
	}

	return 0;
}
