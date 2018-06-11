/**
 * Zentralübung 09
 *
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm, welches 10 Noten vom Benutzer einliest und in einem Array abspeichert. 
 * Das Einlesen soll mit Hilfe einer for-Schleife realisiert werden. Anschließend soll mit Hilfe einer for-Schleife 
 * die schlechteste Note ermittelt und ausgegeben werden.
 *
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
#include<stdio.h>
#define MAX 10

int main()
{
    int i, iMax;
    int noten[MAX];
    
    for ( i = 0; i < MAX; i++ ) {
        printf("Geben Sie die %ite Note ein: \n", i+1);
        scanf("%i", noten+i);
    }
    
    iMax = 0;
    for ( i = 1; i < MAX; i++ ) {
        if ( noten[i] > noten[iMax] )
            iMax = i;
    }
    
    printf("Die schlechteste Note ist: %i \n", *(noten+iMax));    
    
    return 0;
}
