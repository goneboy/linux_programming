#include "header.h"

void output_array(int *array_in, int n_in)
{
	int i;
	for(i = 0; i < n_in; i++)
	{
		printf("arr[%d] = %d\n", i, array_in[i]);
	}
}
