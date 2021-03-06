/**
 * Heimarbeit 08
 *
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm, das vom Benutzer Fahrzeuge mit den dazugehörigen Baujahren 
 * einliest und anschließend die Eingaben nach den Baujahren sortiert wieder ausgibt.
 *
 * Der Benutzer kann solange Fahrzeuge einlesen bis er den Vorgang abbricht oder der Speicherplatz belegt 
 * ist. Sehen Sie die Eingabe von 20 Fahrzeugen vor. Nach der Eingabe der Daten eines Fahrzeuges wird gefragt, 
 * ob ein weiteres eingelesen werden soll. Die Ausgabe der Fahrzeuge soll nach dem Baujahr sortiert stattfinden.
 * Hierbei soll mit den ältesten Modellen begonnen werden.
 *
 * Hinweise:
 * 
 *   o Die Bezeichnung soll als String mit 20 Stellen initialisiert werden.
 *   o Das Baujahr soll als Integerzahl gespeichert werden.
 *   o Sehen Sie für alle Variablen eine korrekte Initialisierung vor.
 *   o Die Ausgabe, das Tauschen und Sortieren sollen als externe Funktion realisiert werden.
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
void Ausgabe(FAHRZEUG *pFahrzeug, int iAnzahl) {
    for ( int i = 0; i < iAnzahl; i++ ) {
	printf("\nBezeichnung: %s", pFahrzeug->bezeichnung);
	printf("\nBaujahr: %u", pFahrzeug->baujahr);
	pFahrzeug += 1;
    }
}
 
//Tauschfunktion
void Tauschen(FAHRZEUG fahrzeuge[], int i, int iMin) {
    FAHRZEUG tmp = fahrzeuge[i];
    fahrzeuge[i] = fahrzeuge[iMin];
    fahrzeuge[iMin] = tmp;
}
  
//Sortierfunktion: Selection sort
void Sortieren(FAHRZEUG fahrzeuge[], int iAnzahl) {
    int iMin = 0;
    
    for ( int i = 0; i < iAnzahl-1; i++ ) {
        iMin = i;
        for ( int j = i+1; j < iAnzahl; j++ ) {
            if ( fahrzeuge[j].baujahr < fahrzeuge[iMin].baujahr ) {
                iMin = j;
            }
        }
        Tauschen(fahrzeuge, i, iMin);
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
        scanf("%20s", fahrzeuge[s].bezeichnung);
  
        printf("\nBitte geben Sie das Baujahr ein:");
        scanf("%u", &fahrzeuge[s++].baujahr); 
		
        //Abfrage, ob weiteres Fahrzeug hinzugefügt werden soll 
        printf ("\nWollen Sie ein weiteres Fahrzeug hinzufuegen? (Ja=1/Nein=0)\n");
        scanf("%i", &i);
    } while ( s < MAX && i );
    //Ende do-while
  
    //Ausgabe der Fahrzeugdaten
    printf("\nFahrzeuge:");
    
    Sortieren(fahrzeuge, s);
    Ausgabe(fahrzeuge, s);
    
    return 0;
}
