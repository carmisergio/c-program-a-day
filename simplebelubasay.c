/********************************************************************************
 * Filename: belubasay.c
 * Description: A Program that prints a beluba that says something stooopid.
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 02/03/2022
********************************************************************************/
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

/********************************************************************************
 * Prints the beluba
********************************************************************************/
int print_beluba() {
  printf(" ____________________________________________________________\n");
  printf("/                                                            \\\n");
  printf("|                      Pezzo di medda!                       |\n");
  printf("\\____________________________________________________________/\n");
  printf("                         |     /\n");
  printf("                         |    / \n");
  printf("                         |   / \n");
  printf("                         |  /  \n");
  printf("                         | /   \n");
  printf("                _______  |/\n");
  printf("               /       \\\n");
  printf("              /  O   O  \\\n");
  printf("             |     I     |\n");
  printf("              \\  \\___/  /\n");
  printf("               \\_______/\n");
  printf("                  _I_\n");
  printf("                 / I \\\n");
  printf("                /  I  \\\n");
  printf("               /   I   \\\n");
  printf("              M    I    M\n");
  printf("                  _I_\n");
  printf("                 /   \\\n");
  printf("                /     \\\n");
  printf("               /       \\\n");
  printf("              d        d\n");
  printf("\n");
}


int main() {
  // Print the beluba
  print_beluba();

  return 0;
}
