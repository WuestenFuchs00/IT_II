/**
 * Heimarbeit 08
 *
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm, welches dem Nutzer die Fakultät einer gewünschten Zahl 
 * ausgibt.
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
#define MAX 20

//Definiton des Structs
typedef struct {
	char bezeichnung[21];
	unsigned int baujahr;
} FAHRZEUG;
  
//Ausgabefunktion
Ausgabe(FAHRZEUG *pFahrzeug, int iAnzahl) {
	for ( int i = 0; i < iAnzahl )
	printf("\nBezeichnung: ", );
    printf("\nBaujahr: ", );
}
 
//Tauschfunktion

  
//Sortierfunktion
void Sortieren(FAHRZEUG *pFahrzeug, int iAnzahl) {
	int iMin = 0;
	for ( int i = 0; i < iAnzahl-1; i++ ) {
		for ( int j = i+1; j < iAnzahl; j++ ) {
			
		}
	}		
} 
  
//Beginn Hauptfunktion
int main()
{
    //Variablendeklaration
    int s = 0;
	int i = 0;
	FAHRZEUG fahrzeuge[MAX];
  
    //do-while-Schleife zum Speichern Daten
	do {
        printf ("Geben Sie die Fahrzeugdaten ein.");
         
        //Einlesen der Daten 
        printf("\nBitte geben Sie die Bezeichnung ein:");
        scanf("%20s", &fahrzeug[s].bezeichnung);
  
        printf("\nBitte geben Sie das Baujahr ein:");
        scanf("%u", &fahrzeug[s++].baujahr); 
		
        //Abfrage, ob weiteres Fahrzeug hinzugefügt werden soll 
        printf ("\nWollen Sie ein weiteres Fahrzeug hinzufuegen? (Ja=1/Nein=0)\n");
        scanf("%i", &i);
	} while ( s < MAX && i );
    //Ende do-while
  
    //Ausgabe der Fahrzeugdaten
    printf("\nFahrzeuge:");
  
    return 0;
}