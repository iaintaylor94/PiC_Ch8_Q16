// Program to convert a positive integer to another base

#include <stdio.h>

// Declare Functions
void getNumberAndBase (void);
void convertNumber (void);
void displayConvertedNumber (void);

// Declare Global variables
int gConvertedNumber [64];
long int gNumberToConvert;
int gBase;
int gDigit = 0;



int main(void) {

  getNumberAndBase();
  convertNumber ();
  displayConvertedNumber ();
  
  return 0;
}



// Define Functions
void getNumberAndBase (void) {
  // Get number
  printf ("Number to convert? ");
  scanf ("%ld", &gNumberToConvert);

  // Get base
  do {
  printf ("Base? ");
  scanf ("%d", &gBase);
    if (gBase < 2 || gBase > 16) {
      printf ("Bad base - must be between 2 and 16\n"); 
    }
  } while (gBase < 2 || gBase > 16);
}

void convertNumber (void) {
  do {
    gConvertedNumber [gDigit] = gNumberToConvert % gBase;
    gDigit++;
    gNumberToConvert /= gBase;
  } 
  while (gNumberToConvert != 0);
}

void displayConvertedNumber (void) {
  const char baseDigits [16] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
  };

  int nextDigit;

  // Print converted number
  printf ("Converted number = ");
  for (--gDigit; gDigit >= 0; gDigit--) {
    nextDigit = gConvertedNumber[gDigit];
    printf ("%c", baseDigits[nextDigit]);
  }
  printf ("\n");
}