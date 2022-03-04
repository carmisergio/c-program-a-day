/********************************************************************************
 * Filename: belubasay.c
 * Description: A Program that prints a beluba that says something stooopid.
 *              Improved with custom text from either argument or stdin;
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 03/03/2022
********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define true 1
#define false 0

/********************************************************************************
 * Prints the beluba
********************************************************************************/
int print_beluba(char *string) {
  printf("##################################################################\n");
  printf("#  ____________________________________________________________  #\n");
  printf("# /                                                            \\ #\n");
  printf("# |%s| #\n", string);
  printf("# \\____________________________________________________________/ #\n");
  printf("#                          |     /                               #\n");
  printf("#                          |    /                                #\n");
  printf("#                          |   /                                 #\n");
  printf("#                          |  /                                  #\n");
  printf("#                          | /                                   #\n");
  printf("#                 _______  |/                                    #\n");
  printf("#                /       \\                                       #\n");
  printf("#               /  O   O  \\                                      #\n");
  printf("#              |     I     |                                     #\n");
  printf("#               \\  \\___/  /                                      #\n");
  printf("#                \\_______/                                       #\n");
  printf("#                   _I_                                          #\n");
  printf("#                  / I \\                                         #\n");
  printf("#                 /  I  \\                                        #\n");
  printf("#                /   I   \\                                       #\n");
  printf("#               M    I    M                                      #\n");
  printf("#                   _I_                                          #\n");
  printf("#                  /   \\                                         #\n");
  printf("#                 /     \\                                        #\n");
  printf("#                /       \\                                       #\n");
  printf("#               d        d                                       #\n");
  printf("#                                                                #\n");
  printf("##################################################################\n");
}


int main(int argc, char *argv[]) {
  char string[999], padded_string[80] = {""};
  int string_length;
  int left_pad, right_pad;
  
  // See if we have arguments
  if(argc > 1) {
    // Run with custom string
    strcpy(string, argv[1]);
  }
  else {
    // Run with default string
    strcpy(string, "Pezzo di meddaaa!");
  }

  // Get string length
  string_length = strlen(string);

  // If the string is shorter than what we can show, pad it
  if(string_length < 60) {
    
    // Compute padding
    left_pad = (60 - strlen(string)) / 2;
    right_pad = left_pad;
    // Add one to the right padding if the thing is not even
    int thingy = string_length % 2;
    printf("modulo: %d, length: %d\n", thingy, string_length);
    if(string_length % 2 != 0) right_pad++;
    
    // Pad left
    for(; left_pad > 0; left_pad--) {
      strcat(padded_string, " ");
    }
    strcat(padded_string, string);
    // Pad right
    for(; right_pad > 0; right_pad--) {
      strcat(padded_string, " ");
    }

  } else if(string_length > 60) {
    // If the string is longer than what we can show, slice off some
    strncpy(padded_string,&string[0],57);
    strcat(padded_string, "...");

  } else {
    // If the string is the correct length, just copy it
    strcpy(padded_string, string);
  }


  // Print the figure 
  print_beluba(padded_string);

  return 0;
}
