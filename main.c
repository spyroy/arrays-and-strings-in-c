#include <stdio.h>
#include "Ex3_.h"

//main function
int main(int argc, char **argv)
{
	int arr[5] = {1,2,3,4,5};
	shift_element(arr, 3);
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("%d,",arr[i]);
	}
	printf("\n");
	int arr2[6] = {10,7,11,54,2,1};
	insertion_sort(arr2,5);
	int j;
	for(j = 0; j < 6; j++)
	{
		printf("%d,",arr2[j]);
	}
	printf("\n");
}
