/**
 * Zentralübung 06
 *
 * Frage 1
 *
 * Schreiben Sie ein C-Programm, welches es erlaubt fünf Kaffeebohnensorten dem Gewicht nach
 * aufsteigend (also leichteste Bohne zuerst) zu sortieren. Hierfür soll der sog. Selection-Sort-
 * Algorithmus implementiert werden, welcher in folgendem Flussdiagramm beschrieben ist:
 *
 * << Flussdiagramm.JPG >>
 *
 * Zum weiteren Verständnis der Wirkungsweise des Selection-Sort-Algorithmus, ist im Folgenden 
 * ein Beispiel für eine einfache Zahlenreihe durchgeführt. Die unterstrichenen Plätze sind 
 * endgültig und die Zahlen verbleiben an der Stelle:
 *
 * Ausgangszustand:
 * 3 9 2 7 1   (i=0) Startwert für min ist 3, Vergleich mit allen rechtsseitigen Zahlen 
 *                   => min = 1 => Tausche 3 und 1
 *
 * Sortiervorgänge:
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
 *   o Verwenden Sie für die Kaffeebohnen ein Array der Größe 5.
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
#define MAX 5 // 5 Bohnensorten

int main () {

    //Variablendeklaration
    float bohnen[MAX];
    float tmp = 0;
    float *pZeiger = bohnen;
    int iMin = 0;  
 
    //Einlesen der fünf Sorten 
    for ( int i = 0; i < MAX; i++ ) {
        if ( scanf("%f", pZeiger+i) == 0 ) {
            printf("\nUngueltige Eingabe!");
            return 1;
        }
    }
    
    //Sortieren
    for ( int i = 0; i < MAX-1; i++ ) {
        iMin = i;
        for ( int j = i+1; j < MAX; j++ ) {
            if ( *(pZeiger+j) < *(pZeiger+iMin) )
                iMin = j;
        } 
        //Tauschen
        tmp = *(pZeiger+i);
        *(pZeiger+i) = *(pZeiger+iMin);
        *(pZeiger+iMin) = tmp;
    }
 
    //Ausgeben
    for ( int i = 0; i < MAX; i++ ) {
        printf("%.2f\n", *(pZeiger+i));
    }
    
    return 0;
}
