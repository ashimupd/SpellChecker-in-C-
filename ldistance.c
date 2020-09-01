#include <stdio.h>
#include <string.h>
#define MAX_WORD_SIZE 1000 /*Max WORD SIZE */
#define MIN(x,y) ((x)<(y))? (x):(y) /* A preprocessor macro */

unsigned int distance (const char *a , const char *b); /* Function prototype */

/* Calculate the Levenstein distance between two words a and b. */

unsigned int distance (const char *a , const char *b)
{
  unsigned int a_len = strlen(a);
  unsigned int b_len = strlen(b);

  /* base case when one of the strings is empty.*/
  if ( a_len == 0 )
    {
      return b_len;
    }
 
  if ( b_len == 0 )
    {
      return a_len;
    }

  /* The recursive case. Construct new strings representing the head of each string,
     by truncating the last char of the strings.*/
  char a_head[ MAX_WORD_SIZE] , b_head[ MAX_WORD_SIZE];
  strcpy( a_head , a);
  strcpy( b_head , b);

  /* Truncate the string length by 1. */
  a_head[a_len -1 ] = '\0';
  b_head[b_len -1 ] = '\0';

  int head_dist;
  /* Calculate the distance between the heads. */
  if ( a[a_len -1] == b[b_len -1])
    {
      head_dist = distance(a_head, b_head);
    }
  else
    {
      head_dist = 1 + distance(a_head, b_head);
    }
  
  /* Calculate the distance between each string and the head of other.*/
  int ahead2b_dist = 1 + distance( a_head, b);
  int bhead2a_dist = 1 + distance( a, b_head);

  /* The Levenstein distance is the minimum of these three quantities.*/
  return MIN( head_dist, MIN( ahead2b_dist, bhead2a_dist));
}
