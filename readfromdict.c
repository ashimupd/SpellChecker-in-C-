/*This module reads the content of a dictionary in a 2d array and checks to find the correct spelling*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ldistance.h" /*we use distance(char *a , char *b) from this module*/
#include "getline.h"/*we use get_line() from this module */

#define ROW 100000 /*Assumption is made that there is < 100000 words in a dictionary*/
#define COL 1000 /*Assumption is made, each of these words are  < 1000 in length*/

void read_dict();
void compare();
void display(int c , int d);

char words[ROW][COL]; /*We assume there are 100000 words of length 100*/
static int dict_words = 0; /*No of words in the dictionary is static to limit its visibility to other modules*/

void read_dict()
{
  int i = 0;
  FILE *f;
  f = fopen("/usr/share/dict/cracklib-small" , "r");

  if (f != NULL)
    {
      while (fgets(words[i] , COL , f) != NULL ) /*takes in a line from dictionary and stores it in an array inside an array*/
	{
	 words[i][strlen(words[i]) - 1] = '\0';
	  i++;
	  dict_words++; /*counting words in the dictionary*/
	}
      
	fclose(f) ; /*closing the file after reading*/
    }
  
   else
    {
      printf("Error Opening file");
      exit(-1);
    }
}
  
void compare()
{
   char * line;
   line = get_line(); /* gets a line from the user. A call to get_line() of getline module*/
   char * delim = " \t\n,!."; /*delimiter characters*/
   char * token = strtok(line , delim); /*c-string to store the individual tokens from the user input line*/
   
   unsigned int dist[ROW]; /*an array that holds the distance of a single token from all the words in the dictionary*/
    
   int i = 0; /*loop variables*/
   int j = 0;
   
   int location; /*location holds the location of the closet word in the dictionary array*/
    
    while (token != NULL)
      {
        for (i = 0 ; i < dict_words - 1 ; i++)
	  {
	    dist[i] = distance(words[i] , token); /*Saving distance results in an array*/
	  }

	/*Finding minimum distance*/
	
	int minimum = dist[0]; /*minimum is the minimum distance*/
	 for(j = 1 ; j < dict_words - 1  ; j++)
	   {
	     if (minimum > dist[j])
	     {
	       minimum = dist[j];
	       location = j; /*location is the location of the minimum distance word in the array of dictionary words*/
	     }
	   }
	 
	 display(minimum , location);/*A call to a display function to print the word*/
	 token = strtok(NULL , delim);/*After a word from the input is dealth with, next word is fetched*/ 
      }
}


void display(int minimum , int location) /*Every time a correct word is found in the dictornary, display is called*/
 {
  if (minimum > 0)
     {
       printf("*%s* ", words[location]);
     }
  else
     {
       printf("%s ",  words[location]);
     }
 }


     
     
	   
			
 
