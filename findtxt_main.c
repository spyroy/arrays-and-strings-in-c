#include <stdio.h>
#include "findtxt.h"
#define LINE 256
#define WORD 30

//main function to findtxt
int main(int argc, char **argv)
{
	char choice;
	char str[WORD];
	fscanf(stdin, "%s",str);
	scanf(" %c", &choice);
	
	switch(choice)
	{
		case 'a':
			printf("all lines that contains the word: %s, will be printed..\n",str);
			print_lines(str);
			break;
		case 'b':
			printf("all words that similar to the word: %s will be printed..",str);
			print_similar_words(str);
			break;
	}
}
