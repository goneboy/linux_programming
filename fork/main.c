#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	fprintf(stdout, "root process: %lu\n", (unsigned long) getpid());	
	fork();
	fork();

	fprintf(stdout, "pid: %lu\n", (unsigned long) getpid());
	return EXIT_SUCCESS;
}
