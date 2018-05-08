/**
 * Numerische Berechnung des Integrals der Funktion
 *
 *   y = ( sin(x)* x^3 ) / sqrt(7*x)
 *
 */
#include <stdio.h>
#include <math.h>

int main () {
	
	int a = 2, b = 3; // Untere und obere Grenze
	double iErg = 0.0, i;
	
	float fDx = 0.001;
	double dDx = 0.001;
	
	for ( i = a; i <= b; i = i + fDx ) {
		iErg += sin(i) * pow(i,3) / sqrt(7*i)  * fDx;
	}
	
	printf("Wert des Integrals: %lf\n", iErg);
	
	printf("\nZahl %f ist float  : %i", fDx, fDx == 0.001); // 0 = false, 1 = true
	printf("\nZahl %lf ist double : %i", dDx, dDx == 0.001);
	
	return 0;
}