/********************************************************************************
 * Filename: isprime.c
 * Description: A simple program that reads a number from the arguments and 
 *              returns 0 if the number is prime, 1 if it isn't
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 06/03/2022
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define true 1
#define false 0

/********************************************************************************
 * Returns true if the given number is prime
 *
 * number: the number to check
 *
 * returns: true if number is prime
********************************************************************************/
bool is_prime(int number) {
  // Loop over every number smaller than the half of the given number
  for(int divisor = number / 2; divisor > 1; divisor = divisor - 1) {
    // If we have found a divisor, the number is not prime
    if(number % divisor == 0) {
      return false;
    };
  }

  // Yay! the number is prime
  return true;
}

int main(int argc,  char *argv[]) {
  int input_number;
  
  // If we have an argument
  if(argc > 1) {
    // Get number from argument
    input_number = atoi(argv[1]);
    // Check if prime
    if(is_prime(input_number)) return 0;
  }
  return 1;
}
