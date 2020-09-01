/*This module is responsible to get the input from the user*/
#include <stdio.h>
#define MAXLINE 10000 /* maximum input line size */
#define YES 1
#define NO 0
char * get_line();

static char line[MAXLINE];/*An array where the line is stored*/

char * get_line() /*gets a line from the user, stores it in array, and makes the entire line a string*/
{
  char c;
  int i;
  printf("Enter a sentence and I'll check the spellings, might take some time:");
  for(i = 0 ; i < MAXLINE - 1 && (c = getchar()) != EOF && c!= '\n' ; ++i)
    {
     line[i] = c;
    }
     ++i;
   line[i] = '\0';
	return (line);
}


  

  

