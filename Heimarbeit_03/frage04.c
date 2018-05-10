/**
 * Heimarbeit 03
 * Frage 3,4
 *
 * Ausgangssituation:
 * 
 * Sie wurden von einer Raumfahrtbehörde beauftragt, ein Programm zu schreiben, welches anhand von
 * Schubkraft und Ausströmgeschwindigkeit der Gase aus den Triebwerken den gesamten Massenstrom
 * berechnet. Das Programm muss dabei zum einen sehr genau und auch effizient arbeiten, da die
 * Rechenkapazität sehr begrenzt ist. 
 *
 *   Fs = m° * v 	          
 * 
 * wobei Fs : Schubkraft
 *       m° : Massenstrom
 *
 * Dieses Programm wird Schritt für Schritt erstellt. 
 * 
 * Folgende Initialisierung der Variablen ist bereits durchgeführt:
 *
 * \\Variablendeklaration
 *   double dSchubkraft = 0;
 *   float fGeschwindigkeit = 0;
 *   double dMassenstrom = 0;
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
  
  // Variablendeklaration
  double dSchubkraft = 0;
  float fGeschwindigkeit = 0;
  double dMassenstrom = 0;

  /* 
   * Frage 3, Aufgabe:
   * Lesen Sie die benötigten Variablen ein und prüfen Sie nach jeder Eingabe, ob der Einlesevorgang
   * erfolgreich war.
   */
   
  //Einlesen der Schubkraft
  printf("Bitte geben Sie die zu erreichende Schubkraft in kN ein:\n");
  //Pruefen, ob Einlesen erfolgreich
  if( scanf(" %lf", &dSchubkraft) <= 0 ) {
    printf("Ungueltige Eingabe!\n");
    return 1;
  }
   
  //Einlesen der Ausstroemgeschwindigkeit
  printf("Bitte geben Sie die Ausstroemgeschwindigkeit der Brenngase in km/s ein:\n");
  //Pruefen, ob Einlesen erfolgreich
  if( scanf(" %f", &fGeschwindigkeit) <= 0 ) {
    printf("Ungueltige Eingabe!\n");
    return 1;
  }
  
  /*
   * Frage 4, Aufgabe:
   * Berechnen Sie den gesamten Massenstrom.
   */
  dMassenstrom = dSchubkraft / fGeschwindigkeit;
  
  return 0;
}
