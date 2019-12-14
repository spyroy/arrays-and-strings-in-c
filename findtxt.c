#include <stdio.h>
#include "findtxt.h"
#define LINE 256
#define WORD 30

//returns number of characters in a text
int my_getchar(char c[])
{
	int chars = 0;
	int i;
	{
		for (i = 0; c[i] != '\0'; ++i)
		{
			chars ++;
		}
	}
	return chars;
}

//returns number of lines in a text
int my_getline(char s[])
{
	int lines = 1;
	int i;
	{
		for (i = 0; s[i] != '\0'; ++i)
		{
			if(s[i] == '\n')
			{
				lines ++;
			}
		}
	}
	if(lines > LINE)
	{
		lines  = -1;
	}
	return lines;
}

//returns number of words in a text
int my_getword(char w[])
{
	int words = 1;
	int i;
	{
		for (i = 0; w[i] != '\0'; ++i)
		{
			if(w[i] == '\n' || w[i] == '\t' || w[i] == ' ')
			{
				words ++;
			}
		}
	}
	if(words > WORD)
	{
		words  = -1;
	}
	return words;
}

int sizeofstr(char* str)
{
	int counter = 0;
	while(*str != '\0')
	{
		counter ++;
		str++;
	}
	return counter;
}

//returns if a word is a substring of another word
int substring(char* str1, char* str2)
{
	int s1 =0;
	s1 = sizeofstr(str1); 
    	int s2=0;
	s2 = sizeofstr(str2);
	if(s2 > s1)
	{
		return 0;
	}
	int i; 
	int count = 0;
	int index = 0;
   	for (i = 0; i < s2; i++) 
	{ 
       	 	int j; 
       		for (j = index; j < s1; j++)
		{ 
            		if (*(str1+j) == *(str2+i))
			{ 
				count++;
				index++;
                		break;
			}
			index ++;
  		}
        	if (count == s2) 
            		return 1; 
    	} 
  
    	return 0; 
}

//returns if a word is "similar" to another
int similar(char* s, char* t, int n)
{
	if(substring(s,t) == 0)
	{
		return 0;
	}
	if((sizeofstr(s) - sizeofstr(t)) == n)
	{
		return 1;
	}
	return 0;
}
		
