/**
 * Zentralübung 4
 *
 * Frage 1
 *
 * Schreiben ein C-Programm, dass den Wert einer Integration numerisch annähert.
 * Folgende Funktion soll integriert werden: 
 *
 *   y = ( sin(x)* x^3 ) / sqrt(7*x)
 *
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Bitte geben Sie die untere Grenze des Integrals ein:
 *   Bitte geben Sie die obere Grenze des Integrals ein:
 *   Bitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein:
 *   Die Integration hat den Wert  
 *
 * Hinweise und Tipps:
 *
 *   o Beachten Sie, dass für einige Rechenoperationen die Bibliothek <math.h> eingebunden werden muss
 *       o a^b -> pow(a,b)
 *       o sqrt(a) -> sqrt(a)
 *  o Um die Genauigkeit der Rechnung überprüfen zu können, benötigen Sie möglichst viele Nachkommastellen
 *  o Realisieren Sie die Berechnung des Integrals einmal mittels einer WHILE-Schleife und einmal mittels 
 *    einer FOR-Schleife
 *  o Der Nutzer des Programmes soll die Integrationsgrenzen und die Schrittweite, also die Genauigkeit 
 *    der Annäherung bestimmen können
 *  o Die zu integrierende Formel muss direkt in den Code geschrieben werden
 *
 * Zum Beispiel:
 *
 *  +----------+---------------------------------------------------------------------+
 *  | Eingabe  | Result                                                              |
 *  +----------+---------------------------------------------------------------------+
 *  | 2        | Bitte geben Sie die untere Grenze des Integrals ein:                |
 *  | 3        | Bitte geben Sie die obere Grenze des Integrals ein:                 |
 *  | 0.001    | Bitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein: |
 *  |          | Die Integration hat den Wert 1.951739                               |
 *  +----------+---------------------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -lm -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 *
 *    -lm : wird benötigt, um <math.h> einzubinden. Sonst gibts "Reference-Error" bzw. Verweisfehler.
 *
 */
#include <stdio.h>
#include <math.h> //Einbinden von mathematischen Funktionen (z.B. sin(x), oder pow(x, y))
 
int main()
{
    //Variablendeklaration
    float fUntereGrenze = 0;
    float fObereGrenze = 0;
    float fDx = 0;
    double fX = 0;
    double fY = 0;
    double fErg = 0;

    //Eingaben
    printf("Bitte geben Sie die untere Grenze des Integrals ein:");
    scanf("%f", &fUntereGrenze);
 
    printf("\nBitte geben Sie die obere Grenze des Integrals ein:");
    scanf("%f", &fObereGrenze);
 
    printf("\nBitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein:");
    scanf("%f", &fDx);
 
    //WHILE-Schleife
    fX = fUntereGrenze;
    while(fX <= fObereGrenze)
    {
        //Formel y=
        fY = (sin(fX) * pow(fX, 3)) / sqrt(fX * 7);
 
        //Ergebnis = Flaeche unter der Kurve -> Wert von y*dx
        fErg += fY * fDx;
 
        //Erhöhung der Laufvariable um die Schrittweite
        fX += fDx;
    }
 
    //Ausgabe in der Konsole
    printf("\nDie Integration hat den Wert %lf", fErg);
    return 0;
}
