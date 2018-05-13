/**
 * Zentralübung 2
 *
 * Frage 1
 *
 * Entwerfen Sie mithilfe des eben erlernten Scanf-Befehls ein Programm, das zwei ganze Zahlen einliest 
 * und diese addiert. 
 *
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Geben Sie die erste Zahl ein:
 *   Geben Sie die zweite Zahl ein:
 *   Die Summe beider Zahlen betraegt:
 *
 * Zum Beispiel:
 *
 * +---------+--------------------------------------+
 * | Eingabe | Result                               |
 * +---------+--------------------------------------+
 * | 7       | Geben Sie die erste Zahl ein:        |
 * | 15      | Geben Sie die zweite Zahl ein:       |
 * |         | Die Summe beider Zahlen betraegt: 22 |
 * +---------+--------------------------------------+
 */
#include <stdio.h>
 
int main()
{
    //Variablendeklaration
    int iZahl1 = 0;
    int iZahl2 = 0;
    int iSumme = 0;

    //Einlesen der Werte
    printf("Geben Sie die erste Zahl ein:");
    scanf("%d", &iZahl1);
 
    printf("\nGeben Sie die zweite Zahl ein:");
    scanf("%d", &iZahl2);
 
    //Addition der Zahlen
    iSumme = iZahl1 + iZahl2;
 
    //Ausgabe in der Konsole
    printf("\nDie Summe beider Zahlen betraegt: %d", iSumme);
 
    return 0;
}
