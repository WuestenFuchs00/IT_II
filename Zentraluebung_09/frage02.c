/**
 * Zentralübung 09
 *
 * Frage 2
 *
 * Schreiben Sie ein vollständiges C-Programm, welches eine komplette Additionsgleichung (a+b; a,b<10) einliest, 
 * diese dann anschließend in ihre Einzelteile zerlegt und sie löst. Bei Eingaben, die nicht der gezeigten
 * Additionsgleichung folgen, soll eine Fehlermeldung "falsche Eingabe" ausgegeben werden.
 *
 * Hinweise:
 *
 *   o Verwenden Sie geeignete Funktion aus der <string.h> um die Position des '+' im String zu ermitteln
 *   o Zahlen sind in der ASCII Tabelle um den Wert 48 nach rechts verschoben. Beachten Sie dies bei der Auswertung 
 *     der Gleichung.
 *   o Arbeiten Sie nur mit Integern.
 *
 * Zum Beispiel:
 *
 * +---------+----------------------------------------------+
 * | Eingabe | Result                                       |
 * +---------+----------------------------------------------+
 * | 5+4     | Bitte geben Sie eine Additionsgleichung ein: |
 * |         | Ergebnis: 5 + 4 = 9                          |
 * +---------+----------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
//Includes
#include <stdio.h>
#include <string.h>

int main () {

    //Variablendeklaration
    char gleichung[11];
    char *p = NULL;
    int sum = 0;
 
    //Einlesen der Gleichung
    printf("Bitte geben Sie eine Additionsgleichung ein:");
    if ( fgets(gleichung, 11, stdin) == 0 )
    {
        printf("Falsche Eingabe!");
        return 1;
    }
    
    
    //Zerlegen der Gleichung und Berechnung des Ergebnisses
    p = strchr(gleichung, '+');
        
    if ( p == NULL ) {
        printf("\nFalsche Eingabe!");
        return 1;
    } else {
        if ( (p-1) == NULL || (*(p-1) < 48 || *(p-1) > 57) || (p+1) == NULL || (*(p+1) < 48 || *(p+1) > 57) ) {
            printf("\nFalsche Eingabe!");
            return 1;
        }
    }
    
    sum = (*(p-1)-48) + (*(p+1)-48);
    
    //Ausgabe des Ergebnisses
    printf("\nErgebnis: %c + %c = %i", *(p-1), *(p+1), sum);

    return 0;
}
