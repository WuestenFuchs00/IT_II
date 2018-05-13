/**
 * Zentralübung 4
 *
 * Frage 3
 *
 * Schreiben Sie ein C-Programm, welches eine Funktion graphisch darstellt und dann das Integral 
 * mit den vom Nutzer bestimmten Grenzen und Schrittweite annähert.
 *
 * Die Ausgabe soll wie folgt aussehen:
 *
 *  *Graphik*
 *   o Bitte geben Sie die untere Grenze des Integrals ein:
 *   o Bitte geben Sie die obere Grenze des Integrals ein:
 *   o Bitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein:
 *   o Die Integration hat den Wert 
 *
 * Zum Beispiel:
 *
 * +---------+---------------------------------------------------------------------------------+
 * | Eingabe |                                                                                 |
 * +---------+---------------------------------------------------------------------------------+
 * | 2       | ^                                                                               |
 * | 3       | |                                                                               |
 * | 0.1     | |                                        ***                                    |
 * |         | |                                       *   *                                   |
 * |         | |                                      *                                        |
 * |         | |                                     *      *                   *              |
 * |         | |                                                                               |
 * |         | |                                    *                                          |
 * |         | |                                             *                                 |
 * |         | |                                   *                                           |
 * |         | |                                                                               |
 * |         | |                                  *           *                                |
 * |         | |                                                                               |
 * |         | |                                 *                                             |
 * |         | |                                                               *               |
 * |         | | ***************                *              *                               |
 * |         | |----------------***------------*-------------------------------------->        |
 * |         | |                   **         *                                                |
 * |         | |                     **      *                                                 |
 * |         | |                       **  **                   *                              |
 * |         | |                         **                                                    |
 * |         | |                                                                               |
 * |         | |                                                              *                |
 * |         | |                                                                               |
 * |         | |                                                 *                             |
 * |         | |                                                                               |
 * |         | |                                                                               |
 * |         | |                                                                               |
 * |         | |                                                                               |
 * |         | |                                                  *                            |
 * |         | |                                                             *                 |
 * |         | |                                                                               |
 * |         |                                                                                 |
 * |         | Bitte geben Sie die untere Grenze des Integrals ein:                            |
 * |         | Bitte geben Sie die obere Grenze des Integrals ein:                             |
 * |         | Bitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein:             |
 * |         | Die Integration hat den Wert 2.001251                                           |
 * +---------+---------------------------------------------------------------------------------+
 */
#include <stdio.h>
#include <math.h>

int main () {

  //Variablendeklaration
  //float fUntereGrenze, fObereGrenze;
  float fY = 0;
  //double fDx = 0; // Schrittweite (Genauigkeit)
  //double fErg; // Ergebnis des Integrals
 
  // Plotter
  for ( int i = 0; i <= 70; i++ ) {
    fY = (sin(0.2*i)*pow(0.2*i,3)/sqrt(0.2*i*7));
    printf("f(%i)=%lf\n", i, fY);
  }
  
  // x IN [0;+70], y IN [-15;+15] 
  printf("^");
  //FOR-Schleife
  for ( int j = 15; j >= -15; j-- ) { 
    printf("\n|");     
    //FOR-Schleife
    for ( int i = 0; i <= 70; i++ ) {
      //Funktion=(sin(0.2*i)*pow(0.2*i,3))/sqrt(0.2*i*7)
      fY = (int) (sin(0.2*i)*pow(0.2*i,3)/sqrt(0.2*i*7));
      fY /= 5;
      if ( fY == 4*j ) printf("*");
      else {
        if ( j == 0 ) {
          if ( i == 70 ) printf(">");
          else printf(" ");
        }
      }
    }
  }

  return 0;
}

