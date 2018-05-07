/**
 * Zentralübung 3
 *
 * Frage 1
 *
 * Ausgangssituation:
 * 
 * Der abgebildete Heizungsregler in einem Auto soll mit Hilfe einer Switch-Case-Struktur
 * programmiert werden.
 *
 * Aufgabe:
 *
 * Implementieren Sie ein C-Programm, welches 
 *   o mittels switch-case Struktur die Aktoren für den "oberen Lüfter", die "Fußheizung" und 
 *     die "Frontscheibenheizung" im entsprechenden Zustand auf "1" schaltet
 *     inversen Verkehrsdichtenquotienten multipliziert werden.
 *   o eine Fehlermeldung ausgibt und alle Aktoren auf "0" setzt, sollte der Benutzer den Schalter
 *     auf eine unzulässige Position drehen 
 *
 * Hinweise und Tipps:
 *   o In der gezeigten Grafik (Heizungsregler) befindet sich der Schalter auf Schalterstellung 2
 * 
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Schalterstellung:
 *
 *   Aktivierte Luefter in aktueller Schalterstellung _:
 *   Oberer Luefter:
 *   Fussheizung:
 *   Frontscheibenheizung:
 *
 * Zum Beispiel:
 *
 *  +----------+-------------------------------------------------------+
 *  | Eingabe  | Result                                                |
 *  +----------+-------------------------------------------------------+
 *  | 0        | Schalterstellung:                                     |
 *  |          |                                                       |
 *  |          | Aktivierte Luefter in aktueller Schalterstellung 0:   |
 *  |          | Oberer Luefter: 1                                     |
 *  |          | Fussheizung: 0                                        |
 *  |          | Frontscheibenheizung: 0                               |
 *  +----------+-------------------------------------------------------+
 */
#include <stdio.h>

int main () {
  //Variablendeklaration
  int iVDichteA, iVDichteB;
  float fQuotient;
  float fGruenA = 50, fGruenB = 75;
 
  printf("Bitte geben Sie die Verkehrsdichte von Strasse A ein:");
  scanf(" %i", &iVDichteA);
 
  printf("\nBitte geben Sie die Verkehrsdichte von Strasse B ein:");
  scanf(" %i", &iVDichteB);
 
  //Berechnung des Verkehrsdichtenquotienten
  fQuotient = (float) iVDichteA / iVDichteB;
  
  //Grünphasen Berechnung
  if ( iVDichteA > 200 || iVDichteB > 200 ) {
	fGruenA *= fQuotient;
	fGruenB /= fQuotient;
  } else if ( iVDichteA < 50 && iVDichteB < 50 ) {
	fGruenA *= .5;
	fGruenB *= .5;
  }
 
  printf("\nDie Gruenphase fuer Strasse A betraegt: %.2f", fGruenA);
  printf("\nDie Gruenphase fuer Strasse B betraegt: %.2f", fGruenB);
  
  return 0;
}