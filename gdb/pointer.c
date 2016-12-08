#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *ptr;
	ptr = (int *) malloc(10);
	free(ptr);
	ptr = NULL;
	
	memset(ptr, 0, sizeof(ptr));

	return 0;
}

