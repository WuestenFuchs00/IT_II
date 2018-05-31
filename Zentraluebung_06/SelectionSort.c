/**
 * Selection Sort
 *
 * Compile:
 *     gcc -Wall -std=gnu99 -pedantic <Quelldatei.c> -o <Programm>
 */
#include <stdio.h>

/*
 * Behandle den Fall, in dem ungueltiger Wert eingegeben wurde.
 * Bricht das Programm ab, falls Eingabe ungueltig ist. 
 */
int behandleUngueltigeEingabe () {
	printf("\nUngueltige Eingabe!");
	return 1;
}

/*
 * Gibt die eingelesenen Zahlen auf dem Bildschirm aus.
 * @params
 *   arr[] : Array der eingelesenen Zahlen
 *   len   : Laenge des Array (= Anzahl der Zahlen)
 */
void ausgebeZahlen (int array[], int len) {
	for ( int i = 0; i < len-1; i++ ) {
		printf("%i, ", array[i]);
	}
	printf("%i\n", array[len-1]);
}

/*
 * Hauptfunktion
 */
int main () {
	
	int iAnzahl; // Anzahl der zu sortierenden Zahlen
	
	printf("/==================\\");
	printf("\n|                  |");
	printf("\n|  Selection Sort  | Es wid aufsteigend sortiert.");
	printf("\n|                  |");
	printf("\n\\==================/");
	
	printf("\n");
	printf("\nAnzahl der zu sortierenden Zahlen: ");
	if ( scanf("%i", &iAnzahl) == 0 || iAnzahl <= 0 ) behandleUngueltigeEingabe();
	
	int arrZahlen[iAnzahl]; // Deklaration: Array der zu sortierenden Zahlen
	int iMin; // Counter der kleinsten Zahl im Array
	int iCounter = 0; // Zaehler
	
	// Einlesen und Speichern der Zahlen in Array
	do {		
		printf("%i.Zahl: ", iCounter+1);
		//if ( scanf("%i", &arrZahlen[iCounter]) == 0 || arrZahlen[iCounter] < 0 )
		if ( scanf("%i", ((int *)arrZahlen) + iCounter) == 0 || arrZahlen[iCounter] < 0 ) {
			printf(">> %i", arrZahlen[iCounter]);
			return behandleUngueltigeEingabe();
		}
		iCounter += 1;
	} while ( iCounter < iAnzahl );
	
	printf("\nUnsortiert: ");
	ausgebeZahlen(arrZahlen, iAnzahl);
	
	// Selection Sort
	for ( int i = 0, tmp = 0; i < iAnzahl-1; i++ ) {
		iMin = i;
		for ( int j = i+1; j < iAnzahl; j++ ) {
			if ( arrZahlen[j] < arrZahlen[iMin] ) { // Suche die kleinste Zahl, aktualisiere iMin
				iMin = j;
			}
		}
		// Vertausche arrZahlen[i] und arrZahlen[iMin]
		tmp = arrZahlen[i];
		arrZahlen[i] = arrZahlen[iMin];
		arrZahlen[iMin] = tmp;
	}
	
	printf("\nSortiert:   ");
	ausgebeZahlen(arrZahlen, iAnzahl);
	
	return 0;
}