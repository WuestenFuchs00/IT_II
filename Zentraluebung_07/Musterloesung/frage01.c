/**
 * Zentralübung 07
 *
 * Frage 1
 *
 * Gegeben ist folgendes Array:
 *
 * +----------+---+---+---+---+---+
 * | iArray = | 1 | 2 | 3 | 4 | 5 |
 * +----------+---+---+---+---+---+
 *
 * Implementieren Sie nun ein vollständiges C-Programm, welches mit Hilfe von Zeigern zwei vom Nutzer 
 * gewählte Arrayelemente vertauscht und anschließend alle Arraywerte um 1 erhöht, bis eine 4 im Array 
 * auftaucht.
 *
 * Hinweise:
 *   o Beachten Sie, dass die Parameter als eine Zahl eingegeben wurden und überlegen Sie sich einen 
 *     passenden Vorgang, die beiden Stellen zu "trennen", um die Zeiger dementsprechend zu belegen
 *   o Geben Sie die Arrayinhalte vor und nach dem Tauschen aus
 *   o Geben Sie auch diejenigen Inhalte aus, die um 1 erhöht wurden
 *
 * Zum Beispiel:
 *
 * +---------+---------------------------------------------------------------------------+
 * | Eingabe | Result                                                                    |
 * +---------+---------------------------------------------------------------------------+
 * | 24      | Der aktuelle Array-Inhalt ist:                                            |
 * | 69.12   | 12345                                                                     |
 * | 15.78   | Welche beiden Stellen möchten Sie vertauschen?                            |
 * | 55.17   | Inhalte des Arrays: 1.Stelle: 3, 2.Stelle: 5                              |
 * | 23.54   | Adressen der Stellen: 1.Stelle: 0x7ffe6bec05f8, 2.Stelle: 0x7ffe6bec0600  |
 * |         | Der aktuelle Array-Inhalt ist:                                            |
 * |         | 12543                                                                     |
 * |         | Die veraenderten Array-Inhalte (mit erhoehten Werten) sind:               |
 * |         | 236                                                                       |
 * +---------+---------------------------------------------------------------------------+
 *
 * BEACHTEN SIE! Die (Vorab)Prüfen-Funktion kann hier aufgrund der Ausgabe der Adressen NICHT funktionieren.
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
    //Variablendeklaration
    int iArray[5] = {1, 2, 3, 4, 5};
    int i = 0;
    int iStellen = 0;
    int* pi = NULL;
    int* pi1 = NULL;
    int* pi2 = NULL;
    int iTemp = 0;
 
    //Array VOR Tausch
    printf("Der aktuelle Array-Inhalt ist:\n");
    for(i = 0; i <= 4; i++)
    {
        printf("%i", *(iArray + i));
    }
 
    printf("\nWelche beiden Stellen moechten Sie vertauschen?");
    scanf("%i", &iStellen);
 
    //Zeiger auf Arraystellen setzen
    pi1 = &iArray[iStellen / 10];
    pi2 = &iArray[iStellen % 10];
 
    //Ausgeben
    printf("\nInhalte des Arrays: 1.Stelle: %i, 2.Stelle: %i", *pi1, *pi2);
    printf("\nAdressen der Stellen: 1.Stelle: %p, 2.Stelle: %p", (void*)pi1, (void*)pi2);
 
    //Vertauschen
    iTemp = *pi2;
    *pi2 = *pi1;
    *pi1 = iTemp;
 
    //Ausgabe NACH Tausch
    printf("\nDer aktuelle Array-Inhalt ist:\n");
    for(i = 0; i <= 4; i++)
    {
        printf("%i", *(iArray + i));
    }
 
    //Schleife, um den Wert der Arrayelemente um 1 zu erhöhen bis 4 auftaucht
    pi = &iArray[0];
    printf("\nDie veraenderten Array-Inhalte (mit erhoehten Werten) sind:\n");
    while(*pi != 4)
    {
        ++(*pi);
        printf("%i", *(pi++));
    }
 
    return 0;
}
