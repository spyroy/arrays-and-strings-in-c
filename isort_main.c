#include <stdio.h>
#include "isort.h"
#define size 50

//main function to isort
int main(int argc, char **argv)
{
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
	for(l = 0; l < size-1; l++)
	{
		printf("%d,",user[l]);
	}
	printf("%d \n",user[l]);
}
