/********************************************************************************
 * Filename: liebnizpi.c
 * Description: A program that approximates pi with the liebniz series 
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 10/03/2022
********************************************************************************/
#include <stdio.h>
#include <limits.h>

int main() {
  double pi = 0;
  int i; // Loop Counter

  for(i = 1; i <= INT_MAX; i += 4) {
    // Do +4/n
    pi += 4 / (double) i;
    // do -4/n+2
    pi -= 4 / (double)(i + 2);

    // Print result as we go
    printf("%.51f\n", pi);
  }

  return 0;
}
