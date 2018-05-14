/**
 * Testat 1
 *
 * Frage 2
 *
 * Schreiben Sie ein C-Programm, das eine Maschine zum Verkauf von standardisierten Holzbrettern 
 * im Baumarkt simuliert.
 */
#include <stdio.h>

int main () {
	
	//Variablendekalration
	char cHolzsorte;
	float fMeter, fPreis = 0;
	
	//Ausgabe der verschiedenen Holzsorten und dazugehörigen Preisen
	printf("Waehlen Sie die gewünschte Holzsorte aus:\n(F) Fichte - 10,40 Euro/m   (K)");
	printf(" Kiefer - 8,90 Euro/m\n(L) Laerche - 12,10 Euro/m  (T) Tanne - 9,50 Euro/m");
	if ( scanf(" %c", &cHolzsorte) == 0 ) {
		printf("\nUngueltige Eingabe!");
		return 1;
	}
	
	//Fallunterscheidung
	switch ( cHolzsorte ) {
	  case 'F':
		printf("\nSie haben Fichte zum Preis von 10,40 Euro/m gewaehlt.");
		fPreis = 10.4;
		break;
	  case 'K':
		printf("\nSie haben Kiefer zum Preis von 8,90 Euro/m gewaehlt.");
		fPreis = 8.9;
		break;
	  case 'L':
		printf("\nSie haben Laerche zum Preis von 12,10 Euro/m gewaehlt.");
		fPreis = 12.1;
		break;
	  case 'T':
		printf("\nSie haben Tanne zum Preis von 9,50 Euro/m gewaehlt.");
		fPreis = 9.5;
		break;
	  default:
		printf("\nUngueltige Eingabe!");
		return 1;
	}
	
	//Nachfrage wieviel Meter der Kunde kaufen möchte
	printf("\nGeben Sie ein, wieviel Meter Sie kaufen moechten:");
	if ( scanf("%f", &fMeter) == 0 ) {
		printf("\nUngueltige Eingabe!");
		return 1;
	}
	
	//Berechnung und Ausgabe des Preises
	fPreis *= fMeter;
	printf("\nDer Preis betraegt %.2f Euro", fPreis);
	
	return 0;
}