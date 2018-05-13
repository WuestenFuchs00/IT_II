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
  
   
int main() 
{ 
    //Variablendeklaration 
    int y = 0; 
    int x = 0; 

    float fObereGrenze = 0; 
    float fUntereGrenze = 0; 

    double dSchritt = 0; 
    double dx = 0;
    double dErg = 0;
    double dVal = 0;
   
    // Werte für Skala 
    float fSchrittweiteY = 5;
  
    //doppelte Genauigkeit für beteiligte Operanden wichtig 
    printf("^");
  
    //FOR-Schleife in y-Richtung (von +15 bis -15) 
    for(y = 15; y >= -15; y--)
    { 
        printf("\n|"); 
        //FOR-Schleife in x-Richtung (von 0 bis 70) 
        for(x = 0; x <= 70; x++) 
        { 
            dVal = (sin(0.2 * x) * pow(0.2 * x, 3)) / sqrt(0.2 * 7* x);
    
  
            //Wert der Funktion liegt im Intervall 
            if(dVal > (y - 1) * fSchrittweiteY && dVal < y * fSchrittweiteY) 
            { 
                printf("*");
            }
    
  
            //X-Achse zeichnen 
            else if(y == 0) 
            { 
                if(x <= 69) 
                { 
                    printf("-"); 
                }
                if(x == 69) 
                { 
                    printf(">"); 
                } 
            } 
            else
            { 
                printf(" "); 
            } 
        } 
    } 
    printf("\n\n"); 
   
    //Eingaben 
    printf("Bitte geben Sie die untere Grenze des Integrals ein:"); 
    scanf("%f", &fUntereGrenze); 
   
    printf("\nBitte geben Sie die obere Grenze des Integrals ein:"); 
    scanf("%f", &fObereGrenze);
    
    printf("\nBitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein:"); 
    scanf("%lf", &dx); //lf format string beachten
    
    x = fUntereGrenze; 
   
    for(dSchritt = fUntereGrenze; dSchritt <= fObereGrenze; dSchritt += dx) 
    { 
        dErg += (sin(dSchritt) * pow(dSchritt, 3)) / sqrt(dSchritt * 7) * dx; 
    }
    
    //Ausgabe des Ergebnisses 
    printf("\nDie Integration hat den Wert %lf", dErg); 
    return 0; 
}

