#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int return_value;
	return_value = system("ps");

	return return_value;
}
