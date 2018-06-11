/**
 * Zentralübung 09
 *
 * Frage 3
 *
 * Schreiben Sie ein vollständiges C-Programm, welches mit Hilfe zweier Pointer einzelne Einträge einer Matrix A 
 * ausgeben und mit Werten aus B überschreiben kann.
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

int main() {

    //Variablendeklaration
    char A[3][3] = {{'a', 'd', 'b'},
                    {'h', 'r', 'k'},
                    {'A', 'F', 'l'}};    
     
    char B[9] = {'e', 'G', 'J', 's', 'y', 'n', 'p', 'Q', 'W'};

    char *pA = A[0]; // &A[0][0];
    char *pB = &B[8];
    int i, j, iStellen;
   
    //Solange der Nutzer bearbeiten will
    do {     
        //Eingabe der Stellen A
        printf("Um wie viele Stellen soll der A-Pointer weiterspringen?");
        scanf("%i", &iStellen);
        
        //Ausgabe des Wertes
        pA += iStellen;
        printf("\nWert an ausgewaehlter Stelle: %c", *pA);
         
        //Wert ueberschreiben?
        printf("\nWollen Sie den Wert ueberschreiben? (1) ja (0) nein");
        scanf("%i", &i);
        
        if ( i ) {
            *pA = *(pB--);
        }
         
        //weiteres Mal bearbeiten?
        printf("\nMatrix nochmal bearbeiten? (1) ja (0) nein\n");
        scanf("%i", &i);
    } while ( i );
 
    //Ausgabe der Matrix
    pA = A[0]; // &A[0][0];
    
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%c ", *(pA++));    
        }
        printf("\n");
    }
    
    return 0;
}
