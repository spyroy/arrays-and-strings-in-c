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

//prints the wanted line
void printline(char line[], char* str)
{
	int i = 0;
	int j=0;
	int h = 0;	
	char word [LINE][WORD];
	for(i = 0; i < my_getchar(line)-1; i++)
	{
		if(line [i] == ' ' || line [i] == '\0')
		{
			word[h][j] = '\0';	
			h++;
			j = 0;
		}
		else
		{
			word[h][j] = line[i];
			j++;
		}
	}
	
	for(i = 0;i <= h+1; i++)
	{
		if(similar(word[i],str,0) == 1||similar(word[i],str,1) == 1)
		{
			printf("%s",line);
			break;
		}
	}
	for(i=0; i < LINE; i++){
		for(j=0; j < WORD; j++){
			word[i][j] = '\0';
		}
	}
}

//not used after all
int checkline(char line[], char* str)
{
	char word[WORD]; 
	char* ptr = line;
	int i = 0;
	while (*ptr != ' ')
   	{	
		word[i] = *ptr;
		if(similar(word,str,0) == 1)
		{
			return 1;
		}
		word[0] = '\0';
    	}
    	return 0;
}

//prints every line that contains the given word
void print_lines(char* str)
{
	if ( stdin != NULL )
	{
 		char line[LINE]; 
		while (fgets(line, sizeof line, stdin) != NULL)
   		{
			printline(line,str);
    		}
    		fclose(stdin);
	}
	else
	{
   		//file doesn't exist or empty
	}
	

}

//prints every word that "similar" to the given word
void print_similar_words(char* str)
{
	if ( stdin != NULL )
	{
 		char word[WORD]; 
		while (fscanf(stdin, " %s",word) == 1)
   		{
			if(similar(word,str,1) == 1||similar(word,str,0) == 1)
			{
				printf("%s\n",word);
			}
			word[0] = '\0';
    		}
    		fclose(stdin);
	}
	else
	{
   		//file doesn't exist or empty
	}
}
		
