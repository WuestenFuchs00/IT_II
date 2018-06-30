/**
 * Arbeiten mit dynamischem Speicher. Verwendung von malloc und free in <stdlib.h>.
 *
 *     ptr = (TYP *) malloc(iAnzahl * sizeof(TYP))
 *     free(ptr)
 */
#include <stdio.h>
#include <stdlib.h>

int main () {
	int iAnzahl, i, *piZahlenFeld;
	
	//printf("Wie viele Zahlen wollen Sie eingeben? ");
	fprintf(stdout, "Wie viele Zahlen wollen Sie eingeben? ");
	
	//if ( scanf("%i", &iAnzahl) == 0 ) {
	if ( fscanf(stdin, "%i", &iAnzahl) == 0 ) {
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
		//printf("\n Zahl %3i: %i", i+1, piZahlenFeld[i]);
		printf("\n Zahl %3i: %i", i+1, *(piZahlenFeld+i));
	}
	
	// Speicherplatz freigeben
	free(piZahlenFeld);
	
	return 0;
}