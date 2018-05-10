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
  // Variablendeklaration
  int iSchalterstellung = 0,
      iObererLuefter = 0, 
	  iFussheizung = 0, 
	  iFrontscheibenheizung = 0;
  
  // Einlesevorgang der Schalterstellung
  printf("Schalterstellung:\n");
  if ( scanf(" %i", &iSchalterstellung) == 0 ) {
	printf("\nUngueltige Schalterstellung!");
	return 1;
  }
  
  // switch-case zum Setzen der Aktoren (siehe Grafik Heizungsregler)
  switch ( iSchalterstellung )  {
	//Schalterstellung 0 : Nur oberer Lüfter
    case 0:
	  iObererLuefter = 1;
      break;	
    //Schalterstellung 1 : Oberer Lüfter und Fussheizung
    case 1:
	  iObererLuefter = iFussheizung = 1;
      break;  
    //Schalterstellung 2 : Nur Fussheizung
    case 2:
	  iFussheizung = 1;
      break;
    //Schalterstellung 3
    case 3:
	  iFrontscheibenheizung = iFussheizung = 1;
      break;  
    //sonst
    default:
      printf("Fehler bei der Schalterstellung!\n");
	  break;
  }
  
  // Ausgabe der Zustaende der Aktoren
  printf("\nAktivierte Luefter in aktueller Schalterstellung %i:\n", iSchalterstellung);
  printf("Oberer Luefter: %i\nFussheizung: %i\nFrontscheibenheizung: %i", iObererLuefter, iFussheizung, iFrontscheibenheizung);
  
  return 0;
}