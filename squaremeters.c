/********************************************************************************
 * Filename: squaremeters.c
 * Description: A Program that can be used to calculate the interior 
 *              area of a home.
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 01/03/2022
********************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define true 1
#define false 0

/********************************************************************************
 * Gets the type of surface that the user wants to add
 *
 * returns: choice
********************************************************************************/
int get_type_of_new_volume() {
  bool has_user_chosen = false;
  int choice;

  // Wait for the user to make a choice
  while(!has_user_chosen) {
    printf("What type of area do you want to add? [0] Quit the program, [1] Rectangle, [2] Custom: ");
    fflush(stdin);
    scanf("%d", &choice);

    // See if the choice is one that is correct
    if(choice == 0 || choice == 1 || choice == 2) {
      has_user_chosen = true;
    }
    else {
      printf("Invalid choice.\n");
    }
  }
  return choice;
}


/********************************************************************************
 * Computes the square meterage for a rectangular surface
 *
 * returns: surface area of the rectangle
********************************************************************************/
int compute_rectangular_surface() {
  float base, height, surface;
  bool has_correct_dimensions = false;

  // Wait for the user to make a choice
  while(!has_correct_dimensions) {
    printf("Enter the dimensions of the rectangole in BASExHEIGHT format: ");
    scanf("%fx%f", &base, &height);

    // See if the choice is one that is correct
    if(base > 0.0 && height > 0.0) {
      has_correct_dimensions = true;
    }
    else {
      printf("Base and height have to be greater than 0. \n");
    }
  }

  // Do the calculation
  surface = base * height;

  // Print a report
  printf("Adding surface: Rectangular %fm x %fm of %fm2\n", base, height, surface);

  return surface;
}

/********************************************************************************
 * Computes the square meterage for a custom surface
 *
 * returns: surface area of the custom surface
********************************************************************************/
int compute_custom_surface() {
  float surface;
  // Ask the user the surface
  printf("Enter the surface area: ");
  scanf("%f", &surface);

  // Print a report
  printf("Adding surface: Custom of %fm2\n", surface);

  return surface;
}




int main() {
  int type;
  float total = 0;

  // Ask the user an indefinite amount of times what surface 
  // the user wants to add
  while(true) {
    // Get the type of surface
    type = get_type_of_new_volume();

    if(type == 0) {
      // If we want to quit, quit
      break;
    } else if(type == 1) {
      // Add rectangular surface to the total
      total = total + compute_rectangular_surface();
    } else if(type == 2) {
      // Add custom surface to the total
      total = total + compute_custom_surface();
    }
  }
  
  // Print final result
  printf("Total area: %fm2\n", total);

  return 0;
}

