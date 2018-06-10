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
 
  
//Ausgabefunktion
       
        printf("\nBezeichnung: ", );
        printf("\nBaujahr: ", );
 
//Tauschfunktion
 
  
//Sortierfunktion
 
  
//Beginn Hauptfunktion
int main()
{
    //Variablendeklaration
 
    int s=0;
  
  
    //do-while-Schleife zum Speichern Daten
 
        printf ("Geben Sie die Fahrzeugdaten ein.");
         
        //Einlesen der Daten
 
        printf("\nBitte geben Sie die Bezeichnung ein:");
        scanf(¦);
  
        printf("\nBitte geben Sie das Baujahr ein:");
        scanf(¦);
 
  
        //Abfrage, ob weiteres Fahrzeug hinzugefügt werden soll 
        printf ("\nWollen Sie ein weiteres Fahrzeug hinzufuegen? (Ja=1/Nein=0)\n");
        scanf(¦);
  
    //Ende do-while
 
 
  
    //Ausgabe der Fahrzeugdaten
    printf("\nFahrzeuge:");
  
    return 0;
}
