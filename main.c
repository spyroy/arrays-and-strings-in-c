#include <stdio.h>
#include "Ex3_.h"
#define size 50

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
	int arr2[8] = {10,7,11,54,2,1,12,3};
	insertion_sort(arr2,8);
	int j;
	for(j = 0; j < 8; j++)
	{
		printf("%d,",arr2[j]);
	}
	printf("\n");

	int k;
	int num;
	int user[size] = {0};
	int* user_ptr = user;
	for(k = 0; k < size; k++)
	{
		scanf(" %d",&num);
		*user_ptr = num;
		user_ptr++;
	}
	insertion_sort(user,size); 
	int l;
	for(l = 0; l < size; l++)
	{
		printf("%d,",user[l]);
	}
	printf("\n");	
}
