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
    char bezeichnung[MAX+1];
    unsigned int baujahr;
} FAHRZEUG; 
  
  
//Ausgabefunktion
void Ausgabe(FAHRZEUG *p, int iAnzahl) {       
    for ( int i = 0; i < iAnzahl; i++ ) {
        printf("\nBezeichnung: %s", p->bezeichnung);
        printf("\nBaujahr: %u", (p++)->baujahr);
    }
}

 
//Tauschfunktion
void Tauschen(FAHRZEUG *a, FAHRZEUG *b) {
    FAHRZEUG tmp = *a;
    *a = *b;
    *b = tmp;    
}

  
//Sortierfunktion: Selection Sort
void Sortieren(FAHRZEUG *p, int iAnzahl) {
    int i, j, iMin = 0;
    
    for ( i = 0; i < iAnzahl-1; i++ ) {
        iMin = i;
        for ( j = i+1; j < iAnzahl; j++ ) {
            if ( (p+j)->baujahr < (p+iMin)->baujahr ) {
                iMin = j;
            }
        }
        Tauschen(p+i, p+iMin);
    }
}
  
//Beginn Hauptfunktion
int main()
{
    //Variablendeklaration
    FAHRZEUG fahrzeuge[MAX];
    FAHRZEUG *p = fahrzeuge;
    int s = 0, i;
  
  
    //do-while-Schleife zum Speichern Daten
    do {
        printf ("Geben Sie die Fahrzeugdaten ein.");
        
        //Einlesen der Daten 
        printf("\nBitte geben Sie die Bezeichnung ein:");
        scanf("%20s", p->bezeichnung);
  
        printf("\nBitte geben Sie das Baujahr ein:");
        scanf("%u", &(p->baujahr));
        
        ++s;
        ++p;
        
        //Abfrage, ob weiteres Fahrzeug hinzugefügt werden soll 
        printf ("\nWollen Sie ein weiteres Fahrzeug hinzufuegen? (Ja=1/Nein=0)\n");
        scanf("%i", &i);
    } while ( i && s < MAX );
    //Ende do-while 
  
    //Ausgabe der Fahrzeugdaten
    Sortieren(fahrzeuge, s); 
    p = fahrzeuge;
    printf("\nFahrzeuge:");  
    Ausgabe(p, s);
    
    return 0;
}
