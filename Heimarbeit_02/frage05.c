/**
 * Heimarbeit 02
 * Fragen 5
 *
 * Compile:
 *    gcc -Wall -std=c90 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 *
 * Ausgangssituation:
 *
 * Gegeben ist der folgende Code:
 */
#include <stdio.h>

int main () {
	
	int iZaehler = 0;
	int iNenner = 0;
	
	printf("Geben Sie den Zaehler ein: ");
	scanf("%i", &iZaehler);
	
	printf("%i", iZaehler);
	
	printf("\nGeben Sie den Nenner ein: ");
	scanf("%i", &iNenner);
	
	printf("%i", iNenner);
	
	printf("\nDas Ergebnis des Bruches lautet: %i", iZaehler/iNenner);
	
	return 0;
	
	/*
	 * Aufgabe: 
	 *   Beurteilen Sie den gegebenen Code und führen Sie seine Funktion aus.
	 *   Welche Ausgabe erhalten Sie, wenn folgende Eingabe getätigt wird:
	 *
	 *     8
	 *     3
	 *
	 *   Antwort: 
	 *     Das Ergebnis des Bruches lautet: 2 
	 */
}