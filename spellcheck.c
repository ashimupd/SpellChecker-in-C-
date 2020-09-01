/*This is a simple spell-checker in c*/
#include <stdio.h>
#include "readfromdict.h"/*read_dict() and compare() is used from this module*/

int main()
{
  read_dict(); /*function called to load dictionary into an array*/
  compare(); /*function called to get the input from user and compare it with the words of dictionary*/
}            /*This function also calls the helper method display to display the found results*/

  
