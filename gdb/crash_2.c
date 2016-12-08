#include <stdio.h>


void assign(int *, int);
void ex_func();

int main(int argc, char *argv[])
{
	int a;
	assign(&a, 10);
	printf("a = %d\n", a);			

	ex_func();

	return 0;
}


void ex_func(void)
{
	int *b;
	assign(b, 10);
	printf("*b = %d\n", *b);
}


void assign(int *ptr_in, int data_in)
{
	*ptr_in = data_in;
}
