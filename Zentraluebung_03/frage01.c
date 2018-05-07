/**
 * Zentral�bung 3
 *
 * Frage 1
 *
 * Ausgangssituation:
 * 
 * Das Programm zur Steuerung einer Ampel an einer Kreuzung von zwei Stra�en, Stra�e A kreuzt Stra�e B
 * (siehe Bild Apel.JPG), soll um einen intelligenten Umschaltmechanismus erweitert werden. Zugrunde
 * gelegt wird dabei der Quotient der Verkehrsdichte beider Stra�en (Quotient = Dichte A/Dichte B).
 *
 * Aufgabe:
 *
 * Implementieren Sie ein C-Programm, welches 
 *   o Bei einer Verkehrsdichte von mehr als 200 Fahrzeugen pro Stunde auf einer der beiden Stra�en
 *     soll die Dauer der Gr�n-Phase von Stra�e A mit Verkehrsdichtenquotienten und Stra�e B mit dem
 *     inversen Verkehrsdichtenquotienten multipliziert werden.
 *   o Sofern der erste Fall nicht zutrifft und die Verkehrsdichte der Stra�en jeweils unter 50
 *     Fahrzeuge pro Stunde f�llt, soll die Dauer der Gr�n-Phase der jeweiligen Stra�e auf 50%
 *     reduziert werden.
 *   o Die Startwerte f�r die Gr�nphasenwerte sind f�r Stra�e A=50, f�r Stra�e B=75
 *
 * Die Ausgabe wie folgt aussehen:
 *
 *   o Bitte geben Sie die Verkehrsdichte von Strasse A ein:
 *   o Bitte geben Sie die Verkehrsdichte von Strasse B ein:
 *   o Die Gruenphase fuer Strasse A betraegt:
 *   o Die Gruenphase fuer Strasse B betraegt:
 *
 * Zum Beispiel:
 *
 *  +----------+-------------------------------------------------------+
 *  | Eingabe  | Result                                                |
 *  +----------+-------------------------------------------------------+
 *  | 220      | Bitte geben Sie die Verkehrsdichte von Strasse A ein: |
 *  | 150      | Bitte geben Sie die Verkehrsdichte von Strasse B ein: |
 *  |          | Die Gruenphase fuer Strasse A betraegt: 73.33         |
 *  |          | Die Gruenphase fuer Strasse B betraegt: 51.14         |
 *  +----------+-------------------------------------------------------+
 */
#include <stdio.h>

int main () {
  //Variablendeklaration
  int iVDichteA, iVDichteB;
  float fQuotient;
  float fGruenA = 50, fGruenB = 75;
 
  printf("Bitte geben Sie die Verkehrsdichte von Strasse A ein:");
  if ( scanf(" %i", &iVDichteA) == 0 ) {
	printf("\nUngueltige Eingabe!");
	return 1;
  }
 
  printf("\nBitte geben Sie die Verkehrsdichte von Strasse B ein:");
  if ( scanf(" %i", &iVDichteB) == 0 ) {
	printf("\nUngueltige Eingabe!");
	return 1;
  }
 
  //Berechnung des Verkehrsdichtenquotienten
  if ( iVDichteB == 0 ) {
	printf("\nDivision durch Null !");
	return 1;
  }
  fQuotient = (float) iVDichteA / iVDichteB;
  
  //Gr�nphasen Berechnung
  if ( iVDichteA > 200 || iVDichteB > 200 ) {
	fGruenA *= fQuotient;
	fGruenB /= fQuotient;
  } else {
	  if ( iVDichteA < 50 ) fGruenA *= .5;
	  if ( iVDichteB < 50 ) fGruenB *= .5;
  }
 
  printf("\nDie Gruenphase fuer Strasse A betraegt: %.2f", fGruenA);
  printf("\nDie Gruenphase fuer Strasse B betraegt: %.2f", fGruenB);
  
  return 0;
}