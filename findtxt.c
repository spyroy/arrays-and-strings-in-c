#include <stdio.h>
#include "findtxt.h"
#define LINE 256

int my_getline(char s[])
{
	int counter = 0;
	int i;
	{
		for (i = 0; s[i] != '\0'; ++i)
		{
			counter ++;
		}
	}
	if(counter > LINE)
	{
		counter  = -1;
	}
	return counter;
}
	
