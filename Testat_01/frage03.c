/**
 * Testat 1
 *
 * Frage 3
 *
 * Entwerfen Sie einen C-Code, der folgende Aufgaben erledigt:
 *
 * 1. Zun�chst zwei Zahlen und eine Teilerzahl einlesen
 * 2. Falls die zweite Zahl kleiner oder gleich der ersten Zahl ist: Fehlermeldung ausgeben 
 *    (Ung�ltige Reihenfolge!).
 * 3. Bei g�ltiger Eingabe: Alle Zahlen zwischen der ersten und der zweiten Zahl einzeln durchgehen
 *    und �berpr�fen, ob sie durch den Teiler nicht teilbar sind. Wenn ja, dann diese Zahl ausgeben.
 * 4. Am Ende die Anzahl an nicht teilbaren Zahlen ausgeben.
 *
 * Es werden nur ganze Zahlen verwendet.
 * Benutzen Sie f�r die Eingabe�berpr�fung eine do-while-Schleife und f�r die Teiler�berpr�fung
 * eine for-Schleife.
 *
 * Die Ausgabe soll folgenderma�en aussehen:
 *
 */
#include <stdio.h>

int main () {
	
	//Variablendeklaration
	int iFalsch = 1, iAnzahl = 0;
	int iZahl1, iZahl2, iTeiler;
	
	//Schleife zur �berpr�fung der Eingabe
	do {
		//1. Benutzereingaben
		printf("Geben Sie die erste Zahl ein:");
		scanf("%i", &iZahl1);
	
		printf("\nGeben Sie die zweite Zahl ein:");
		scanf("%i", &iZahl2);
	
		printf("\nGeben Sie den Teiler ein:");
		scanf("%i", &iTeiler);
	
		//2. Ung�ltige Eingabe
		if ( iZahl2 <= iZahl1 ) {
			printf("\nUngueltige Reihenfolge!\n");
		}
		else {
            iFalsch = 0;			
			//3. Schleife zur Teiler�berpr�fung
			for ( int j = iZahl1; j <= iZahl2; j++ ) {
				if ( j % iTeiler ) {
					iAnzahl += 1;
					printf("\nDie Zahl %i ist nicht durch %i teilbar.", j, iTeiler);
				}
			}			
			//4. Ausgabe der Anzahl der Nichtteiler
			printf("\nEs existieren %i Zahlen, die nicht durch Ihren Teiler teilbar sind.", iAnzahl);
		}
	} while ( iFalsch );
	//Ende der Eingaben�berpr�fungsschleife
	
	return 0;
}