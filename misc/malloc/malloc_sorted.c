/**
 * Arbeiten mit dynamischem Speicher. Verwendung von malloc und free in <stdlib.h>.
 *
 *     ptr = (TYP *) malloc(iAnzahl * sizeof(TYP))
 *     free(ptr)
 */
#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE=0, TRUE=1 } BOOL;

/*
 *
 */
BOOL SelectionSort (int *piFeld, int iAnzahl) {
	if ( piFeld == NULL || iAnzahl <= 0 )
		return FALSE;
	
	int i, j, iTemp, iMin;	
	for ( i = 0; i < iAnzahl-1; i++ ) {
		iMin = i;
		for ( j = i+1; j < iAnzahl; j++ ) {
			if ( piFeld[j] < piFeld[iMin] ) {
				iMin = j;
			}
		}
		// Tauschen
		iTemp = piFeld[i];
		piFeld[i] = piFeld[iMin];
		piFeld[iMin] = iTemp;
 	}
	return TRUE;
}

/*
 *
 */
int main () {
	int iAnzahl, i, *piZahlenFeld;
	BOOL bSortSuccess = FALSE;
	
	//printf("Wie viele Zahlen wollen Sie eingeben? ");
	fprintf(stdout, "Wie viele Zahlen wollen Sie eingeben? ");
	
	//if ( scanf("%i", &iAnzahl) == 0 ) {
	if ( fscanf(stdin, "%i", &iAnzahl) == 0 || iAnzahl < 0 ) {
		printf("\n Ungueltige Eingabe!");
		return 1;
	}
	
	// Speicherplatz alloziieren bzw.reservieren
	piZahlenFeld = (int *) malloc(iAnzahl * sizeof(int));	
	
	for ( i = 0; i < iAnzahl; i++ ) {
		printf("\n Bitte geben Sie die %i-Zahl ein ", i+1);
		//scanf("%i", &piZahlenFeld[i]);
		//scanf("%i", piZahlenFeld+i);
		fscanf(stdin, "%i", piZahlenFeld+i);
	}
	
	//printf("\n Ihre Eingaben");
	fprintf(stdout, "\n Ihre Eingaben");
	
	for ( i = 0; i < iAnzahl; i++ ) {
		//printf("\n Zahl %3i: %i", i+1, *(piZahlenFeld+i));
		printf("\n Zahl %3i: %i", i+1, piZahlenFeld[i]);
	}
	
	// Feld sortieren (Selection Sort)
	fprintf(stdout, "\n\n Sortiertes Feld");
	
	//bSortSuccess = SelectionSort(piZahlenFeld, iAnzahl);
	bSortSuccess = SelectionSort(&piZahlenFeld[0], iAnzahl);
	
	if ( bSortSuccess ) {
		for ( i = 0; i < iAnzahl; i++ ) {
			printf("\n Zahl %3i: %i", i+1, *(piZahlenFeld + i));
		}
	} else {
		printf("\n Sortieren war nicht erfolreich.");
	}
	
	// Speicherplatz freigeben
	free(piZahlenFeld);
	
	return 0;
}