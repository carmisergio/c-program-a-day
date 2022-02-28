/********************************************************************************
 * Filename: random.c
 * Description: A Program that runs a random program in the same directory.
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 28/02/2022
********************************************************************************/
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0

int main() {
  // Define data structures to contain the info
  DIR *d;
  struct dirent *dir;
  char file_names[999][255];
  int number_of_files = 0;
  char executable_path[300] = "./";

  // Open the current directory
  d = opendir(".");

  // If the dir opening was succesful
  if(d) {
    // Read each dir
    while((dir = readdir(d)) != NULL) {
      // Don't include this program in the count
      if(strcmp(dir->d_name, "random") && strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")) {
        // Save name of file in array
        strcpy(file_names[number_of_files], dir->d_name);

        // Keep track of amount of files found
        number_of_files++;
      }
    }
    // Close directory
    closedir(d);

    // Select a random program to run
    srand(time(0));
    int random_index = rand() % number_of_files;
    
    
    // Create the executable path
    strcat(executable_path, file_names[random_index]);

    printf("#### RUNNING PROGRAM: %s ####\n", executable_path); 
    fflush(stdout);

    // Execute the selected program
    system(executable_path);

  }
  return 0;
}
