#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void print_hello();

int main(int argc, char *argv[])
{
	sleep(15);
	print_hello();
	sleep(15);
	print_hello();
	sleep(15);
	print_hello();
	sleep(15);
	print_hello();	
	sleep(15);
	print_hello();
	return 0;
}

void print_hello()
{
	printf("hello world\n");
}
