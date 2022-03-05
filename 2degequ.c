/********************************************************************************
 * Filename: 2degequ.c
 * Description: A program that calculates the approximate numerical result
 *              to a second degree equation expressed in normal form.
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 05/03/2022
********************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define true 1
#define false 0

/********************************************************************************
 * Asks the user for input and handles retries in case of errors
 *
 * message: the number to check
 *
 * returns: the number 
********************************************************************************/
double read_double(char *message) {
  int done = 0;
  double result;

  printf("%s", message);


  while(done != 1) {
    done = scanf(" %lf", &result);
    if(!done) {
      printf("Invalid input. %s", message);
    }
    // Flush any unexpected characters
    while (getchar() != '\n');
  }

  return result;
}

/********************************************************************************
 * Prints the result of a given pure equation
 *
 * a: the a term
 * c: the c term
********************************************************************************/
double solve_pure(double a, double c) {
  double x;
  // The if statements check if the equation is possible by seeing 
  // if a and b are of the same sign
  if(a > 0) {
    if(c > 0) {
      // If the equation is impossible, we inform the user
      printf("[ The equation has no possible solutions in R ]\n");
    }
    else {
      // If the equation is possible, we solve it and print the result
      x =  sqrt((0 - c) / a);
      printf("[ Result: x1 = %lf; x2 = %lf ]\n", x, 0 - x);
    }
  }
  else {
      if(c > 0) {
      // If the equation is possible, we solve it and print the result
      x =  sqrt((0 - c) / a);
      printf("[ Result: x1 = %lf; x2 = %lf ]\n", x, 0 - x);
    }
    else {
      // If the equation is impossible, we inform the user
      printf("[ The equation has no possible solutions in R ]\n");
    }

  }
}

/********************************************************************************
 * Solves a complete equation by selecting the reduced or general formula
 *
 * a: the a term
 * b: the b term
 * c: the c term
********************************************************************************/
double solve_spurious(double a, double b) {
  // Solve the equation and print its results
  printf("[ Result: x1 = %lf; x2 = 0 ]\n", 0 - b / a);
}

/********************************************************************************
 * Prints the result of a given complete equation that can be solved with the
 * reduced formula
 *
 * a: the a term
 * b: the b term
 * c: the c term
********************************************************************************/
double solve_reduced(double a, double b, double c) {
  double x1, x2;
  // Calculate discriminant
  double disc = pow(b / 2, 2) - a * c;

  // Print discriminant
  printf("Discriminant: %lf\n", disc);

  // Check various discriminants
  if(disc < 0) {
    printf("[ The equation has no possible solutions in R ]\n");
  } else if(disc == 0) {
    // Calculate the results and print them
    x1 = (b / 2) / a;
    x2 = x1;
    printf("[ Result: x1 = %lf; x2 = %lf ]\n", x1, x2);
  } else {
    // Calculate the results and print them
    x1 = (0 - b / 2 + sqrt(disc)) / a;
    x2 = (0 - b / 2 - sqrt(disc)) / a;
    printf("[ Result: x1 = %lf; x2 = %lf ]\n", x1, x2);
  }
}

/********************************************************************************
 * Prints the result of a given complete equation that can be solved with the
 * general formula
 *
 * a: the a term
 * b: the b term
 * c: the c term
********************************************************************************/
double solve_general(double a, double b, double c) {
  double x1, x2;
  // Calculate discriminant
  double disc = pow(b, 2) - 4 * a * c;

  // Print discriminant
  printf("Discriminant: %lf\n", disc);

  // Check various discriminants
  if(disc < 0) {
    printf("[ The equation has no possible solutions in R ]\n");
  } else if(disc == 0) {
    // Calculate the results and print them
    x1 = (0 - b) / 2 * a;
    x2 = x1;
    printf("[ Result: x1 = %lf; x2 = %lf ]\n", x1, x2);
  } else {
    // Calculate the results and print them
    x1 = (0 - b + sqrt(disc)) / 2 * a;
    x2 = (0 - b - sqrt(disc)) / 2 * a;
    printf("[ Result: x1 = %lf; x2 = %lf ]\n", x1, x2);
  }
}

/********************************************************************************
 * Prints the result of a given pure equation
 *
 * a: the a term
 * c: the c term
********************************************************************************/
double solve_complete(double a, double b, double c) {
  // Check to see if we can use the reduced formula
  if(fmod(b, 2) == 0) {
    // Solve with reduced formula
    solve_reduced(a, b, c);
  }
  else {
    // Solve with general formula
    solve_general(a, b, c);
  }
}

int main() {
  double a, b, c;

  // Print welcome message
  printf("Second degree equation solver v1.0 - Sergio Carmine\n");

  // Get equation input
  printf("The equation being expressed as ax^2 + bx + c\n");
  a = read_double("Enter a: ");
  b = read_double("Enter b: ");
  c = read_double("Enter c: ");


  // Exit if equation is not of second degree
  if(a == 0) {
    printf("Not a second degree equation: a must be greater than 0!\n");
    return 1;
  }

  // Check for type of equation
  if(b == 0) {
    if(c == 0) {
      // Print activity message
      printf("Solving monomial equation: %lfx^2 = 0\n", a);
      printf("[ Result: x1 = 0; x2 = 0 ]\n");
    } else {
      // Print activity message
      printf("Solving pure equation: %lfx^2 (+/-) %lf = 0\n", a, c);
      solve_pure(a, c);
    }
  }
  else {
    if(c == 0) {
      // Print activity message
      printf("Solving spurious equation: %lfx^2 (+/-) %lfx = 0\n", a, b);
      solve_spurious(a, b);
    } else {
      // Print activity message
      printf("Solving complete equation: %lfx^2 (+/-) %lfx (+/-) %lf = 0\n", a, b, c);
      solve_complete(a, b, c);
    }
  }

  return 0;
}
