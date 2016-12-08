#include <stdio.h>
#include "header.h"

int main(int argc, char *argv[])
{
	int arr[100], n;
	printf("Enter n: ");
	scanf("%d", &n);

	array_input(arr, n);
	array_output(arr, n);

	return 0;
}

void array_input(int *array_in, int data_in)
{
	int i;
	for(i = 0; i < data_in; i++)
	{
		printf("arr[%d] = ", i);
		scanf("%d", &array_in[i]);
	}
}


void array_output(int *array_in, int data_in)
{
	int i;
	printf("\n------------------------\n");
	for(i = 0; i < data_in; i++)
	{
		printf("arr[%d] = %d\n", i, array_in[i]);
	}
}
