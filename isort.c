#include <stdio.h>
#include "isort.h"
#define num_elements 50

//function to move all elements after specific pointer one step.
void shift_element(int* arr, int i)
{
	int j;
	for(j = 0; j < i; j++)
	{
		*(arr+i-j) = *(arr+i-j-1);
	}
}

//insertion sort
void insertion_sort(int *arr, int len)
{
	int tmp;
	arr++;
	int i,j;
	for(i = 1; i < len; i++)
	{
		for(j = i; j > 0; j--)
		{
			if(*(arr) < *(arr-j))
			{
				tmp = *(arr);
				shift_element(arr-j,j);
				*(arr-j) = tmp;
			}
		}
		arr++;
	}
}
			
