/********************************************************************************
 * Filename: inefficientprimes.c
 * Description: A program that implements a very inefficient algorithm to 
 *              compute prime numbers
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 26/02/2022
********************************************************************************/
#include <stdio.h>
#include <limits.h>

#define true 1
#define false 0

/********************************************************************************
 * Asks the user for input and handles retries in case of errors
 *
 * message: the number to check
 *
 * returns: the number 
********************************************************************************/
double read_int(char *message) {
  int done = 0, result;

  printf("%s", message);


  while(done != 1) {
    done = scanf(" %d", &result);
    if(!done) {
      printf("Invalid input. %s", message);
    }
    // Flush any unexpected characters
    while (getchar() != '\n');
  }

  return result;
}

int main() {
  int amount, input, biggest = INT_MIN;

  amount = read_int("Enter the amount of numbers to compare: ");

  for(; amount > 0; amount--) {
    input = read_int("Enter a number: ");
    if(input > biggest) biggest = input;
  }

  printf("The biggest number is: %d", biggest);
  return 0;
}
