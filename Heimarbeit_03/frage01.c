/**
 * Heimarbeit 03
 * Frage 1:
 *
 * Ausgangssituation:
 *
 * Einer Unterwasserexpedition stehen mehrere Uboote verschiedener Größe zur Verfügung. Auf diesen
 * befinden sich Herstellerangaben über die Oberfläche und die maximal zulässige Kraft, die auf 
 * diese wirken darf. Da das Expeditionsteam - um neue Unterwasserwelten zu entdecken - möglichst 
 * tief tauchen möchte, will es das Uboot auswählen, welches am tiefsten tauchen kann.
 *
 * Dieses Programm wird Schritt für Schritt erstellt. 
 *
 * Folgende Initialisierung der Variablen ist bereits durchgeführt:
 *
 * // Deklaration der Variablen
 *	float fmax = 0; 	
 *	float fOflaeche = 0; 	
 *	float fTiefe = 0;  	
 *	float fDruck = 0; 	
 *	float fbar = 0;
 *
 * Aufgabe:
 * Lesen Sie die Oberfläche des Ubootes in m^2 (Quadratmeter) sowie die maximal darauf wirkende Kraft 
 * in kN ein. Prüfen Sie, ob der Einlesevorgang erfolgreich war. Sollte der Einlesevorgang 
 * fehlgeschlagen sein, soll "Einlesevorgang gescheitert!" ausgegeben werden.
 *
 * Hinweise und Tipps:
 *  o Achten Sie auf die Anzahl der geforderten Nachkommastellen
 *  o Überlegen Sie, welche Information in der "Einlesevariable" gespeichert wird und wie Sie diese 
 *    nutzen können, um zu prüfen ob die beiden Werte eingelesen wurden
 *
 * Zum Beispiel:
 *
 * +-------------+------------------------------------------------------------------------+
 * | Eingabe     | Result                                                                 |
 * +-------------+------------------------------------------------------------------------+
 * | 60.5        | Bitte geben Sie die Oberflaeche in Quadratmetern ein:                  |
 * | 9000        | Bitte geben Sie die maximal auf die Flaeche wirkende Kraft in kN ein:  |
 * +-------------+------------------------------------------------------------------------+
 * | 60.5        | Bitte geben Sie die Oberflaeche in Quadratmetern ein:                  |
 * | neuntausend | Bitte geben Sie die maximal auf die Flaeche wirkende Kraft in kN ein:  |
 * |             | Einlesevorgang gescheitert!                                            |
 * +-------------+------------------------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=c90 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
#include <stdio.h>

int main () {
  
  // Deklaration der Variablen
  float fmax = 0; 	
  float fOflaeche = 0; 	
  float fTiefe = 0;  	
  float fDruck = 0; 	
  float fbar = 0;

  // Einlesen der Variablen
  printf("Bitte geben Sie die Oberflaeche in Quadratmetern ein:");
  scanf("%f", &fOflaeche);
        
  printf("\nBitte geben Sie die maximal auf die Flaeche wirkende Kraft in kN ein:");
  scanf("%f", &fmax);
   
  //Pruefen, ob zwei floats korrekt eingelesen wurden
 
  printf("\nEinlesevorgang gescheitert!");
  return 1; //Rückgabewert 1 bricht das Programm ab

  return 0;
}
