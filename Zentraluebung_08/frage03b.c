/**
 * Zentralübung 08
 *
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm, welches dem Nutzer die Fakultät einer gewünschten Zahl 
 * ausgibt.
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

unsigned long int fakultaet (int iZahl)
{
     if ( iZahl > 1 ) {
        printf(" %i *", iZahl);
        return iZahl * fakultaet(iZahl-1);
     } 
     else {
        printf(" %i", iZahl);
        return 1;
     }       
}
  
int main()
{
    int iZahl;
    unsigned long int iErg;
    
    printf("Bitte geben Sie eine Zahl ein:\n");
  
    if(scanf("%i", &iZahl) == 0)
    {
        printf("Ungueltige Eingabe!");
        return 1;
    }
    printf("%i! = ", iZahl);
  
    iErg = ( iZahl == 0 ) ? 1 : fakultaet(iZahl);
    
    printf("\n\nDie Fakultaet von %i ist: %lu.", iZahl, iErg);
  
    return 0;
}
