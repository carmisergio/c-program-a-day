/********************************************************************************
 * Filename: inefficientprimes.c
 * Description: A program that implements a very inefficient algorithm to 
 *              compute prime numbers
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 26/02/2022
********************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define true 1
#define false 0

/********************************************************************************
 * Asks the user how many primes he wants to generate and returns it
 *
 * returns: amount of primes to print
********************************************************************************/
int get_amount() {
  int amount;

  // Print a prompt and get the user's response
  printf("How many primes do you want to compute? ");
  scanf("%d", &amount);

  return amount;
}

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

/********************************************************************************
 * Finds the next prime from a determined starting point
 * 
 * position: where to start searching
 *
 * returns: the prime it has found
********************************************************************************/
int get_next_prime(int position) {
  // Try every number until one is prime
  while(!is_prime(position)) {
    position++;
  }

  // Return the found prime
  return position;
}

/********************************************************************************
 * Generates a defined number of primes
 *
 * amount: amount of primes to print
********************************************************************************/
void compute_primes(int amount) {
  int prime, position = 2;

  // Find [amount] number of primes
  for(; amount > 0; amount--) {
    // Find the next prime and print it
    prime = get_next_prime(position);
    printf("%d\n", prime);

    // The next starting point is the prime we just found plus one
    position = prime + 1;
  }
}

int main() {
  int amount;

  // Get number of primes the user wants to generate
  amount = get_amount();

  // Compute those primes
  compute_primes(amount);


  return 0;
}
