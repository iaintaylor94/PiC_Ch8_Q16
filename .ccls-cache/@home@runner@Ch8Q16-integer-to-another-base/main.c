// Program to convert a positive integer to another base

#include <stdio.h>
#include <stdbool.h>

// Declare Functions
void getNumber (void);
void getBase (void);
void convertNumber (void);
void displayConvertedNumber (void);

// Declare Global variables
int gConvertedNumber [64];
long int gNumberToConvert;
long int gNumberToConvertStatic;
int gBase;
int gDigit = 0;



int main(void) {

  do {
    getNumber();

    if (gNumberToConvertStatic == 0) {
      break;
    }

    getBase();
    
    convertNumber ();
    displayConvertedNumber ();
  } while (true);
  
  return 0;
}



// Define Functions
void getNumber (void) {
  printf ("Number to convert? ");
  scanf ("%ld", &gNumberToConvert);
  gNumberToConvertStatic = gNumberToConvert;
}

void getBase (void) {
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