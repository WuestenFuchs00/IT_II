/**
 * Heimarbeit 04
 * Frage 2
 *
 * Schreiben Sie ein vollständiges C-Programm, das vom Benutzer eine Zahl einliest, alle Primzahlen bis zu einschließlich dieser Zahl 
 * bestimmt und ausgibt.
 *
 * Hinweise:
 *
 *   o Fangen Sie den Fall ab, dass jemand eine Zahl größer als 1000 oder kleiner als 1 eingibt
 *   o Um die Abarbeitung einer Schleife zu beenden, können Sie den von "switch-case" bekannten Befehl break; verwenden
 *   o Zur Hilfe ist folgender Programmablaufplan gegeben:
 *
 *       << Primzahlen.JPG >>
 *
 * Zum Beispiel:
 *
 * +---------+------------------------------------------------------+
 * | Eingabe | Result                                               |
 * +---------+------------------------------------------------------+
 * | 8       | Bitte geben Sie eine Zahl zwischen 1 und 1000 ein,   |
 * |         | bis zu der Sie alle Primzahlen ausrechnen wollen:    |
 * |         |                                                      |
 * |         | 2 ist eine Primzahl                                  |
 * |         | 3 ist eine Primzahl                                  |
 * |         | 5 ist eine Primzahl                                  |
 * |         | 7 ist eine Primzahl                                  |
 * +---------+------------------------------------------------------+
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

int main () {
  
  //Variablendeklaration
  int iZahl; // Obere Grenze
  
  //Benutzereingabe der Zahl, solange keine gueltige Zahl eingegeben wurde
  do {
    printf("Bitte geben Sie eine Zahl zwischen 1 und 1000 ein, bis zu der Sie alle Primzahlen ausrechnen wollen:\n");
    if ( scanf("%i", &iZahl) == 0 ) {
      printf("\nUngueltige Eingabe!");
      return 1;
    }
  } while ( iZahl < 1 || iZahl > 1000 );
   
   
  //Schleife fuer Primzahlkandidaten
  for ( int k = 2; k <= iZahl; k++ ) {
    //Schleife fuer moegliche Teiler
    for ( int j = 2; j <= k; j++ ) {
        //Ausgabe falls Zahl Primzahl
        if ( j == k ) printf("\n%i ist eine Primzahl", k);
        else if ( k % j == 0 ) break;
    }
  }
  
  return 0;
}
