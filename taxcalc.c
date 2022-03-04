/********************************************************************************
 * Filename: taxcalc.c
 * Description: A program that calculates an arbitrary amount of tax added to 
 *              an arbitrary price
 * Author: Sergio Carmine <me@sergiocarmi.net>
 * Created: 04/03/2022
********************************************************************************/
#include <stdio.h>

#define true 1
#define false 0

/********************************************************************************
 * Calculate price with tax
 *
 * returns: price with tax
********************************************************************************/
float calc_price_with_tax(float price, float tax_percent) {
  return price + price * tax_percent / 100 ;
}

int main() {
  float price, tax_percent;

  // Enter data
  printf("Enter the price: ");
  scanf("%f", &price);
  printf("Enter the tax %: ");
  scanf("%f", &tax_percent);

  // Print result
  printf("The price with tax is: %.2f", calc_price_with_tax(price, tax_percent));

  return 0;
}
