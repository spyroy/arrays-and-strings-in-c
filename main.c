#include <stdio.h>
#include "isort.h"
#include "findtxt.h"
#define size 50
#define LINE 256

//main function
int main(int argc, char **argv)
{
	//not necessary, only for testing
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
	//end testing


	//the main for isorted
	int k;
	int num;
	int user[size] = {0};
	int* user_ptr = user;
	printf("please insert 50 numbers separated with space/enter: ");
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
	printf("all numbers are now sorted!\n");

	//main for findtxt
	char s[] = "i love cats\nbut also like dogs\tand most of all\nfishes";
	int a;
	for(a = 0; a < sizeof(s); a++)
	{
		printf("%c",s[a]);
	}
	printf("\n");
	int chars = my_getchar(s);
	int lines = my_getline(s);
	int words = my_getword(s); 
	printf("%d \n", chars);	
	printf("%d \n", lines);
	printf("%d \n", words);
	char s1[] = "cat";
	char s2[] = "cat";
	char* s1ptr = s1;
	char* s2ptr = s2;
	printf("%d \n", substring(s2ptr,s1ptr));
	printf("%d \n", similar(s2ptr,s1ptr,0));	
	char s3[] = "cat";
	print_lines(s3);
}
