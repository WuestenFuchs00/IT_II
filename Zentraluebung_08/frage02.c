/**
 * Zentralübung 08
 *
 * Frage 2
 *
 * Schreiben Sie ein vollständiges C-Programm, welches einen definierten und initialisierten Array (siehe Codeschnipsel)
 * sortiert. Die Einträge des Arrays sind ausschließlich Integerzahlen. Der Array soll vor und nach der Sortierung
 * ausgegeben werden. Die Einträge müssen aufsteigend von der kleinsten zur größten Zahl ausgegeben werden.
 *
 * Hinweise:
 * 
 *   o Verwenden Sie zur Sortierung zwei Funktionen (call-by-reference)
 *   o Programmieren Sie ebenfall eine Call-by-Reference-Funktion zum Ausgeben des Arrays
 *   o Rufen Sie die Funktionen dann in der main-Funktion auf
 *
 * Zum Beispiel:
 *
 * Result:
 * Die Reihe lautet: 3 15 2 65 5
 * Die sortierte Reihe lautet: 2 3 5 15 65
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
#include <stdio.h>
   
//Funktion Tauschen
void Tauschen(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

    
//Funktion Sortieren
void Sortieren(int *p, int k) {
    int iMin = 0;
    for ( int i = 0; i < k-1; i++ ) {
        iMin = i;
        for ( int j = i+1; j < k; j++ ) {
            if ( *(p+j) < *(p+iMin) )
                iMin = j;
        }
        Tauschen(p+i, p+iMin);
    }
} 
  
//Funktion Ausgabe
void Ausgabe(int *p, int k) {
    for ( int i = 0; i < k; i++ ) {
        printf(" %i", *(p+i));
    }
}
   
    
int main()
{  
    int iReihe[] = {3, 15, 2, 65, 5};
     
    printf("Die Reihe lautet:");
    //Funktionsaufruf zur Ausgabe der Reihe
    Ausgabe(iReihe, 5);
    
    //Funktionsaufruf zum Sortieren der Reihe
    Sortieren(iReihe, 5);
    
    printf("\nDie sortierte Reihe lautet:");
    //Funktionsaufruf zur Ausgabe der Reihe
    Ausgabe(iReihe, 5);
      
    return 0;
}
