/********************************************************************************
 * Filename: excommunicado.c
 * Description: A Program that simulates sending a John Wick excommunicado.
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 27/02/2022
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define true 1
#define false 0

/********************************************************************************
 * Prints random sending message with random numbers
********************************************************************************/
int send_messages() {
  while(true) {
    /// Print string
    printf("]SENDING MESSAGE TO..... %03d-%03d-%04d\n]\n", rand() % 999, rand() % 999, rand() % 9999);
    // Sleep a random amount of time between 450 and 550 milliseconds
    sleep(1);
  }
}


int main() {
  // Start sending messages
  send_messages();

  return 0;
}
