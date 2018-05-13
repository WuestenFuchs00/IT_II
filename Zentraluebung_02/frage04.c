/**
 * Zentralübung 2
 *
 * Frage 4
 *
 * Ausgangssituation:
 *
 * Ein Fahrzeughersteller möchte seinen Spritsparmodus "Economy" mit dem Standardmodus vergleichen. Dafür 
 * sollen einige Messfahrten durchgeführt werden, für welche noch ein Auswerteprogramm benötigt wird. 
 *
 * Aufgabe: 
 *
 * Schreiben Sie ein C-Programm, welches folgende Funktionen beinhaltet:
 *
 *   o Einlesen der gefahrenen Kilometer, Stunden, der dabei verbrauchten Litern Sprit und des Fahrmodus
 *   o Berechnen Durchgschnittsgeschwindigkeit in km/h
 *   o Berechnen des Durchschnittsverbrauchs in l/100 km
 *   o Ausgabe des Fahrmodus, sowie der Ergebnisse
 *
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Bitte geben Sie die gefahrenen Kilometer ein:
 *   Bitte geben Sie die gefahrenen Stunden ein:
 *   Bitte geben Sie den Spritverbrauch in Litern ein:
 *   Bitte geben Sie ihren Fahrmodus an:
 *   Standard(S), Economy(E)
 *   Fahrmodus: 
 *   Durchschnittsgeschwindigkeit betraegt: 
 *   Durchschnittsverbrauch betraegt:
 *
 * Zum Beispiel:
 *
 * +---------+-----------------------------------------------------+
 * | Eingabe | Result                                              |
 * +---------+-----------------------------------------------------+
 * | 123.456 | Bitte geben Sie die gefahrenen Kilometer ein:       |
 * | 1.23    | Bitte geben Sie die gefahrenen Stunden ein:         |
 * | 6.158   | Bitte geben Sie den Spritverbrauch in Litern ein:   |
 * | E       | Bitte geben Sie ihren Fahrmodus an:                 |
 * |         | Standard(S), Economy(E)                             |
 * |         | Fahrmodus: E                                        |
 * |         | Durchschnittsgeschwindigkeit betraegt: 100.371 km/h |
 * |         | Durchschnittsverbrauch betraegt: 4.988 l/100km      |
 * +---------+-----------------------------------------------------+
 */
#include <stdio.h>

int main () {

  //Variablendeklarierung
  float fKm, fStunden, fVerbrauch;
  char cModus;
  
  float fDGeschwindigkeit = 0;
  float fDVerbrauch = 0;
 
  //Einlesen der Daten
 
  //Eingabe Kilometer
  printf ("Bitte geben Sie die gefahrenen Kilometer ein:");
  if ( scanf("%f", &fKm) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
  
  //Eingabe Stunden
  printf ("\nBitte geben Sie die gefahrenen Stunden ein:");
  if ( scanf("%f", &fStunden) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
 
  //Eingabe Verbrauch
  printf ("\nBitte geben Sie den Spritverbrauch in Litern ein:");
  if ( scanf("%f", &fVerbrauch) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
 
  //Eingabe des Fahrmodus
  printf("\nBitte geben Sie ihren Fahrmodus an:");
  printf("\nStandard(S), Economy(E)");
  if ( scanf(" %c", &cModus) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
 
  //Berechnung der Durchschnittsgescwhindigkeit in km/h
  fDGeschwindigkeit = fKm / fStunden;
 
  //Berechnung des Durchschnittsverbrauchs in l/100km
  fDVerbrauch = fVerbrauch / fKm * 100;
 
  //Ausgabe des Fahrmodus
  printf("\nFahrmodus: %c", cModus);
 
  //Ausgabe der Durschnittsgeschwindigkeit in km/h
  printf ("\nDurchschnittsgeschwindigkeit betraegt: %.3f km/h", fDGeschwindigkeit);
 
  //Ausgabe des Durchschnittsverbrauch auf l/100km
  printf ("\nDurchschnittsverbrauch betraegt: %.3f l/100km", fDVerbrauch);

  return 0;
}
