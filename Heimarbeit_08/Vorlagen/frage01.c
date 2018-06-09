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