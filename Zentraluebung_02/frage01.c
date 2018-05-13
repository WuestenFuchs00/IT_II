/**
 * Zentralübung 2
 *
 * Frage 1
 *
 * Entwerfen Sie mithilfe des eben erlernten Scanf-Befehls ein Programm, das zwei ganze Zahlen einliest 
 * und diese addiert. 
 *
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Geben Sie die erste Zahl ein:
 *   Geben Sie die zweite Zahl ein:
 *   Die Summe beider Zahlen betraegt:
 *
 * Zum Beispiel:
 *
 * +---------+--------------------------------------+
 * | Eingabe | Result                               |
 * +---------+--------------------------------------+
 * | 7       | Geben Sie die erste Zahl ein:        |
 * | 15      | Geben Sie die zweite Zahl ein:       |
 * |         | Die Summe beider Zahlen betraegt: 22 |
 * +---------+--------------------------------------+
 */
#include <stdio.h>

int main () {

  //Variablendeklaration
  int iZahl, iSumme; 
 
  //Einlesen der Sensorwerte
  printf("Geben Sie die erste Zahl ein:");
  if ( scanf("%i", &iZahl) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
 
  iSumme = iZahl;
  
  printf("\nGeben Sie die zweite Zahl ein:");
  if ( scanf("%i", &iZahl) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }

  //Addition der Zahlen  
  iSumme += iZahl;
  
  //Ausgabe in der Konsole
  printf("\nDie Summe beider Zahlen betraegt: %i", iSumme);

  return 0;
}
