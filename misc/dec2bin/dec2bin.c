/**
 * dec2bin.c
 *
 * Convert a not-negative decimal number to binary number.
 */
#include <stdio.h>

/*
 * Calculates the power a^b
 */
double potenz(double a, int b) { /* a^b */
	return ( b == 0 ) ? 1 : ( b == 1 ) ? a : ( b > 1 ) ? a * potenz(a,b-1) : /* b < 0 */ 1/potenz(a,-b);
}

/*
 * Converts a decimal number, that is not negative, to the corresponding binary number.
 */
double dec2bin(int * d) {
	double b = 0;
	int i = 0;
	
	do {
		if ( (*d)%2 > 0 )
			b += ((*d)%2) * potenz(10,i);
		i += 1;
		*d /= 2;
	} while ( *d );
	
	return b;
}

/*
 * Main program
 */
int main (void) {
	int iDec;
	
	printf("\nDezimal Zahl: ");
	if ( scanf("%d", &iDec) == 0 ) {
		printf("\nUngueltige Eingabe!");
		return 1;
	}
	if ( iDec < 0 ) {
		printf("\nBitte KEINE negative Zahl.");
		return 1;
	}	
	printf("Binaere Zahl: %.0lf", dec2bin(&iDec));
	
	return 0;
}