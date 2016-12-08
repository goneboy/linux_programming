#include <stdio.h>
//#include "header.h"


int main(int argc, char *argv[])
{
	int n, arr[100];
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	input_array(arr, n);	
	output_array(arr, n);	


	return 0;
}
