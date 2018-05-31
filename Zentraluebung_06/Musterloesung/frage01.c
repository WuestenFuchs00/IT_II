/**
 * Zentral�bung 06
 *
 * Frage 1
 *
 * Schreiben Sie ein C-Programm, welches es erlaubt f�nf Kaffeebohnensorten dem Gewicht nach
 * aufsteigend (also leichteste Bohne zuerst) zu sortieren. Hierf�r soll der sog. Selection-Sort-
 * Algorithmus implementiert werden, welcher in folgendem Flussdiagramm beschrieben ist:
 *
 * << Flussdiagramm.JPG >>
 *
 * Zum weiteren Verst�ndnis der Wirkungsweise des Selection-Sort-Algorithmus, ist im Folgenden 
 * ein Beispiel f�r eine einfache Zahlenreihe durchgef�hrt. Die unterstrichenen Pl�tze sind 
 * endg�ltig und die Zahlen verbleiben an der Stelle:
 *
 * Ausgangszustand:
 * 3 9 2 7 1   (i=0) Startwert f�r min ist 3, Vergleich mit allen rechtsseitigen Zahlen 
 *                   => min = 1 => Tausche 3 und 1
 *
 * Sortiervorg�nge:
 * 1 9 2 7 3   (i=1) 9 ist neues min, Vergleiche 9 mit allen Rechtsseitigen => Tausche 9 und 2
 * -
 *
 * 1 2 9 7 3   (i=2) Vergleiche 9 mit allen Rechtsseitigen => Tausche 9 und 3
 * - -
 *
 * 1 2 3 7 9   (i=3) Vergleiche 7 mit allen Rechtsseitigen => 7 bleibt min, Selbsttausch
 * - - -
 *
 * Hinweise:
 *   o Verwenden Sie f�r die Kaffeebohnen ein Array der Gr��e 5.
 *   o Das Programm muss zuerst das Gewicht jeder Kaffeebohne einlesen. Am Ende werden diese 
 *     sortiert wieder ausgegeben.
 *   o Achten Sie auf die Anzahl der geforderten Nachkommastellen.
 *
 * Zum Beispiel:
 *
 * +---------+-----------+
 * | Eingabe | Result    |
 * +---------+-----------+
 * | 8.45    | 8.45      |
 * | 69.12   | 15.78     |
 * | 15.78   | 23.54     |
 * | 55.17   | 55.17     |
 * | 23.54   | 69.12     |
 * +---------+-----------+
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
 
int main()
{
    //Variablendeklarationen
    float fAGewicht[5];
    int i = 0;
    int j = 0;
    int iMin = 0;
    float fTemp = 0;
 
    //Einlesen der f�nf Sorten
    for(i = 0; i < 5; i++)
    {
        scanf("%f", &fAGewicht[i]);
    }
 
    //Sortieren
    for(i = 0; i < 4; i++)
    {
        iMin = i; //Array ist bis min sortiert
 
        for(j = i + 1; j < 5; j++)
        {
            if(fAGewicht[j] < fAGewicht[iMin])
            {
                iMin = j;
            }
        }
 
        //Tauschen
        fTemp = fAGewicht[i];
        fAGewicht[i] = fAGewicht[iMin];
        fAGewicht[iMin] = fTemp;
    }
    //Ausgeben
    for(i = 0; i < 5; i++)
    {
        printf("%.2f\n", fAGewicht[i]);
    }
 
    return 0;
}