/**
 * Zentralübung 08
 *
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm, welches die Endgeschwindigkeit einer Rakete anhand seiner Start- und
 * Endmasse berechnet. Die Endgeschwindigkeit kann mit Hilfe der Raketengrundgleichung berechnet werden:
 *
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
#include <stdio.h>
  
//Funktion zum Berechnen der Potenzen (wird für Logarithmus gebraucht!)
double Potenz(double x, int n) {
    return ( n == 0 ) ? 1 : ( n == 1 ) ? x : x * Potenz(x, n-1);
}
 
//Funktion fuer die Taylor-Reihe der Logarithmusfunktion
double Ln(double x, int n) {
    double sum = 0;
    for ( int i = 1; i <= n; i++ )
        sum += Potenz(x-1, i) * Potenz(-1, i+1) / i;
    return sum;
} 
  
//Hauptfunktion
int main()
{
     //Variablendeklaration, Aussstoßgeschwindigkeit = 4200 m/s!
     double vG = 4200;
     double m0, mEnd, vEnd = 0;
     int n;
     
    //Eingaben
    printf("Bitte geben Sie die Startmasse ein:");
    scanf("%lf", &m0);
     
    printf("\nBitte geben Sie die Endmasse ein:");
    scanf("%lf", &mEnd);
     
    printf("\nGewuenschte Genauigkeit der Taylorreihe?");
    scanf("%i", &n);
  
    //Berechnung mit Funktionsaufruf
    vEnd = vG * Ln(m0/mEnd, n);
 
    printf("\n\nDie Endgeschwindigkeit betraegt %.2f m/s", vEnd);
    return 0;
}
