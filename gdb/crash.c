#include <stdio.h>

int divide(int, int);

int main(int argc, char *argv[])
{
	int x = 3, y =0, c;
	
	c = divide(x, y);	

	return 0;
}

int divide(int a, int b)
{
	int tmp;
	tmp = a / b;
	return tmp;
}
