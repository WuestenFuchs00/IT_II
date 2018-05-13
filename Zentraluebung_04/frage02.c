/**
 * Zentralübung 4
 *
 * Frage 2
 *
 * Schreiben Sie ein C-Programm, welches eine Zahl des ersten Spielers einliest und dann den zweiten
 * Spieler die Zahl erraten lässt.
 * Wenn der Nutzer eine falsche Zahl eingibt, soll das Programm dem Nutzer ausgeben, ob die zu 
 * erratene Zahl größer oder kleiner ist als die eingegebene Zahl.
 * Wenn der Nutzer die richtige Zahl eingibt, soll das Programm beendet werden.
 *
 * Zum Beispiel:
 *
 *  +----------+----------------------------------------------------------------------+
 *  | Eingabe  | Result                                                               |
 *  +----------+----------------------------------------------------------------------+
 *  | 8        | Bitte geben Sie eine Zahl ein, ohne dass Ihr Mitspieler diese sieht. |
 *  | 5        | Bitte raten Sie eine Zahl.                                           |
 *  | 12       | Die Zahl ist groesser!                                               |
 *  | 8        | Bitte raten Sie eine Zahl.                                           |
 *  |          | Die Zahl ist kleiner!                                                |
 *  |          | Bitte raten Sie eine Zahl.                                           |
 *  |          | 8 ist richtig!                                                       |
 *  +----------+----------------------------------------------------------------------+
 */
#include <stdio.h>

int main () {

  // Variablendeklaration
  int iZahl1, iZahl2;
 
  // Eingabe der zu erratenden Zahl
  printf("Bitte geben Sie eine Zahl ein, ohne dass Ihr Mitspieler diese sieht.");
  if ( scanf("%i", &iZahl1) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
  
  // Schleife zum Erraten der Zahl
  do {
    printf("\nBitte raten Sie eine Zahl.");
    if ( scanf("%i", &iZahl2) == 0 ) {
      printf("\nUngueltige Eingabe!");
      return 1;
    }
    if ( iZahl2 > iZahl1 ) printf("\nDie Zahl ist kleiner!");
    else if ( iZahl2 < iZahl1 ) printf("\nDie Zahl ist groesser!");
  } while ( iZahl2 != iZahl1 );
 
 
  // Ausgabe wenn Zahl erraten
  printf("\n%i ist richtig!", iZahl2);

  return 0;
}

