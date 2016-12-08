#include "header.h"

void input_array(int *array_in, int n_in)
{
	int i;
	for(i = 0; i < n_in; i++)
	{
		printf("arr[%d] = ", i);
		scanf("%d", &array_in[i]);
	}
}
