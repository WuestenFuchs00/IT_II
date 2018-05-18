/**
 * Heimarbeit 05
 *
 * Frage 1
 *
 * Schreiben Sie ein vollst‰ndiges C-Programm, bei dem der erste Benutzer zuerst eine ganzzahlige 
 * Zahl zwischen 0 und 100 eingibt, welche der zweite anschlieﬂend erraten soll.
 * 
 * Hinweise:
 *  o Der zweite Spieler hat 6 Versuche
 *  o Zur Hilfe ist folgendes Nassi-Shneidermann-Diagramm gegeben
 *
 *  << Zahlenraten.JPG >>
 *
 * Zum Beispiel:
 *
 * +---------+------------------------------------------------------------+
 * | Eingabe | Result                                                     |
 * +---------+------------------------------------------------------------+
 * | 75      | Bitte geben Sie eine ganze Zahl zwischen 0 und 100 ein:    |
 * | 20      |                                                            |
 * | 60      | Ihr Tipp:                                                  |
 * | 80      | Zu klein! Verbleibende Versuche: 5                         |
 * | 75      | Ihr Tipp:                                                  |
 * |         | Zu klein! Verbleibende Versuche: 4                         |
 * |         | Ihr Tipp:                                                  |
 * |         | Zu hoch! Verbleibende Versuche: 3                          |
 * |         | Ihr Tipp:                                                  |
 * |         | Ihr Tipp war korrekt!                                      |
 * +---------+------------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -lm -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
#include <stdio.h>

int main () {
	
	//Variablendeklaration
	int iZahl, iTipp;
	int iVersuche = 6;
 
	//Einlesen der Zahl die vom zweiten Benutzer erraten werden soll
	do {
		printf("Bitte geben Sie eine ganze Zahl zwischen 0 und 100 ein:\n");
		if ( scanf("%i", &iZahl) == 0 ) {
			printf("\nUngueltige Eingabe!");
			return 1;
		}
	} while ( iZahl < 0 || iZahl > 100 );
 
	//Schleife zum Erraten der Zahl
	do {
		printf("\nIhr Tipp:");
		if ( scanf("%i", &iTipp) == 0 ) {
			printf("\nUngueltige Eingabe!");
			return 1;
		}		
		//Ausgabe bei falschen Tipps
		if ( iTipp < iZahl ) printf("\nZu klein! Verbleibende Versuche: %i", --iVersuche);
		else if ( iTipp > iZahl ) printf("\nZu hoch! Verbleibende Versuche: %i", --iVersuche);
	} while ( iTipp != iZahl && iVersuche > 0 );
 
	//Ausgabe Spielergebnis
	if ( iTipp == iZahl ) printf("\nIhr Tipp war korrekt!");
	else printf("\nZahl nicht erraten!");
	
	return 0;
}