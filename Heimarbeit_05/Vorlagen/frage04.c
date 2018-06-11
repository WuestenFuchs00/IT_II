/**
 * Heimarbeit 05
 *
 * Frage 4
 *
 * Aufgabe:
 *
 * Schreiben Sie ein vollständiges C-Programm, das vom Benutzer zwei 3x3-Matrizen einliest, 
 * anschließend die Matrizenmultiplikation durchführt und dann das Ergebnis ausgibt.
 *
 * Zum Beispiel:
 *
 * +---------+-----------------------------+
 * | Eingabe | Result                      |
 * +---------+-----------------------------+
 * | 1       | Matrizenmultiplikation:     |
 * | 2       |                             |
 * | 3       | a b c     A B C             |
 * | 4       | d e f  *  D E F    =        |
 * | 5       | g h i     G H I             |
 * | 6       |                             |
 * | 7       |                             |
 * | 8       | Bitte geben Sie a ein:      |
 * | 9       | Bitte geben Sie b ein:      |
 * | 10      | Bitte geben Sie c ein:      |
 * | 11      |                             |
 * | 12      | Bitte geben Sie d ein:      |
 * | 13      | Bitte geben Sie e ein:      |
 * | 14      | Bitte geben Sie f ein:      |
 * | 15      |                             |
 * | 16      | Bitte geben Sie g ein:      |
 * | 17      | Bitte geben Sie h ein:      |
 * | 18      | Bitte geben Sie i ein:      |
 * |         |                             |
 * |         |                             |
 * |         |                             |
 * |         | Bitte geben Sie A ein:      |
 * |         | Bitte geben Sie B ein:      |
 * |         | Bitte geben Sie C ein:      |
 * |         |                             |
 * |         | Bitte geben Sie D ein:      |
 * |         | Bitte geben Sie E ein:      |
 * |         | Bitte geben Sie F ein:      |
 * |         |                             |
 * |         | Bitte geben Sie G ein:      |
 * |         | Bitte geben Sie H ein:      |
 * |         | Bitte geben Sie I ein:      |
 * |         |                             |
 * |         | Das Ergebnis ist:           |
 * |         |                             |
 * |         |  84 90 96                   |
 * |         |  201 216 231                |
 * |         |  318 342 366                |
 * +---------+-----------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -lm -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
//Variablendeklaration
 
 
//Prelabel
printf("Matrizenmultiplikation:\n\n");
printf("a b c     A B C\nd e f  *  D E F    =\ng h i     G H I\n\n");
 
//Eingabe 1. Matrix
 
        printf("\nBitte geben Sie %c ein: ", 'a'+j+3*i);
        scanf();
 
    //neue Zeile nach dem Einlesen einer Zeile
    printf("\n");
 
    //zwei neue Zeilen nach dem Einlesen der ersten Matrix
    printf("\n\n");
 
//Eingabe 2. Matrix
 
        printf("\nBitte geben Sie %c ein: ", 'A'+j+3*i);
        scanf();
        
    //zwei neue Zeilen nach dem Einlesen der ersten Matrix
    printf("\n");
 
 
//Berechnung der Matrizenmultiplikation
 
 
//Ausgabe des Ergebnisses
printf("\nDas Ergebnis ist:\n\n");
for (i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        printf(" %", );
    }
    printf("\n");
}
