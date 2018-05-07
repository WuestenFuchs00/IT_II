/**
 * Heimarbeit 03
 * Frage 5 (Alternative Lösung)
 *
 * Ausgangssituation:
 * 
 * Sie wurden beauftragt die Begrüßungsfunktion eines Smartphones so zu programmieren, dass es je nach
 * Geschlecht des Besitzers und der jeweiligen Tageszeit eine angepasste Begrüßungsformel ausgibt.
 *
 * Aufgabe:
 * 
 * Schreiben Sie ein vollständiges C-Programm, welches zuerst die Uhrzeit in vollen Stunden und danach
 * das Geschlecht des Benutzers erfragt ('w' für weiblich, 'm' für männlich). Anhand dieser Eingaben
 * soll es mit Hilfe von "if-else"-Strukturen entscheiden welche Begrüßungsformel ausgegeben werden
 * soll. Sollte die Uhrzeit nicht plausible sein, oder die Eingabe des Geschlechts nicht den
 * Auswahlmöglichkeiten entsprechen, soll eine Fehlermeldung ausgegeben werden. 
 *
 * Hinweise:
 *   o vor 10 Uhr soll "Guten Morgen Frau/Herr Amberg" ausgegeben werden
 *   o Zwischen 10 und 18 Uhr soll "Guten Tag Frau/Herr Amberg" ausgegeben werden
 *   o Für Uhrzeiten ab 18 Uhr soll "Guten Abend Frau/Herr Amberg" ausgegeben werden
 *
 * Zum Beispiel:
 * 
 * +---------+-------------------------------------------------------------+
 * | Eingabe | Result                                                      |
 * +---------+-------------------------------------------------------------+
 * | 9       | Bitte geben Sie die aktuelle Uhrzeit ein (volle Stunden):   |
 * | m       | Bitte waehlen Sie Ihr Geschlecht:                           |
 * |         | Fuer weiblich bitte [w] eingeben                            |
 * |         | Fuer maennlich bitte [m] eingeben                           |
 * |         |                                                             |
 * |         | Guten Morgen Herr Amberg                                    |
 * +---------+-------------------------------------------------------------+
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
#include <stdlib.h>
#include <string.h>

int main () {
  
  // Variableninitialisierung
  char sUhrzeit[30];
  char cGeschlecht = 0;
  char *sEndPtr; // pointer to the next character (in sUhrzeit) after the numerical value
                 // i.e. if sUhrzeiit is 9.55, then sEndPtr will be .55, length 3  
  long lUhrzeit = 0;      // strtol return value
  int iRetGeschlecht = 0; // scanf return value
  int iLen = 0;           // length of sEndPtr

  // Einlesen der Uhrzeit
  printf("Bitte geben Sie die aktuelle Uhrzeit ein (volle Stunden):\n");
  scanf(" %s", sUhrzeit);
  lUhrzeit = strtol(sUhrzeit, &sEndPtr, 10); 
  // if sUhrzeit is 9.55, then .55 will be stored in string which sEndPtr points to,
  // and 9 will be stored in lUhrzeit.
  iLen = strlen(sEndPtr);
  if ( lUhrzeit < 0 || iLen > 0 ) {
	printf("\nUngueltige Uhrzeit!");
	return 1;
  }
  
  //Einlesen des Geschlechts
  printf("\nBitte waehlen Sie Ihr Geschlecht:\n");
  printf("Fuer weiblich bitte [w] eingeben\n");
  printf("Fuer maennlich bitte [m] eingeben\n");
  iRetGeschlecht = scanf(" %c", &cGeschlecht);
  if ( iRetGeschlecht == 0 ) {
	printf("\nUngueltiges Geschlecht!");
	return 1;
  }
  
  /*If-Else-Konstrukt für Ausgabe*/
  // Eingegebene Zeit plausibel?
  if ( lUhrzeit <= 24 ) {
    //Ausgabe für Frau
    if ( cGeschlecht == 'w' ) {
      if ( lUhrzeit < 10 ) printf("\nGuten Morgen Frau Amberg");
      else if ( lUhrzeit >= 10 && lUhrzeit <= 18 ) printf("\nGuten Tag Frau Amberg");
      else printf("\nGuten Abend Frau Amberg");
    }
    //Ausgabe für Herr
    else if ( cGeschlecht == 'm' ) {
      if ( lUhrzeit < 10 ) printf("\nGuten Morgen Herr Amberg");
      else if ( lUhrzeit >= 10 && lUhrzeit <= 18 ) printf("\nGuten Tag Herr Amberg");
      else printf("\nGuten Abend Herr Amberg");
    }
	//Wenn weder Mann noch Frau
    else {
        printf("\nUngueltiges Geschlecht!");
    }
  }
  //Zeit nicht plausibel
  else {
    printf("\nUngueltige Uhrzeit!");
  }
  
  return 0;
}
