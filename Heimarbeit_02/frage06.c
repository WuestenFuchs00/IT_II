/**
 * Heimarbeit 02
 * Fragen 6
 *
 * Compile:
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 *
 * Verändern Sie genau eine Zeile des Codes (aus Frage 5), damit die Ausgabe eine zweistellige
 * Gleitkommazahl (d.h. zwei Nachkommastellen) anzeigt.
 * 
 * Hinweis:
 * Kopieren Sie die entsprechende Zeile Code aus dem obenstehenden Programm in das Antwortfeld 
 * und passen Sie diese entsprechend an.
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
	
	//printf("\nDas Ergebnis des Bruches lautet: %i", iZaehler/iNenner);
	printf("\nDas Ergebnis des Bruches lautet: %.2f", (float) iZaehler / iNenner);
	
	return 0;
}