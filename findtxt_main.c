#include <stdio.h>
#include "findtxt.h"
#define LINE 256
#define WORD 30
#define LINES 250

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
			print_lines(str);
			break;
		case 'b':
			print_similar_words(str);
			break;
	}
}
