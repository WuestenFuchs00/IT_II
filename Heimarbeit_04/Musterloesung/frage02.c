/**
 * Heimarbeit 04
 * Frage 2
 *
 * Schreiben Sie ein vollständiges C-Programm, das vom Benutzer eine Zahl einliest, alle Primzahlen bis zu einschließlich dieser Zahl 
 * bestimmt und ausgibt.
 *
 * Hinweise:
 *
 *   o Fangen Sie den Fall ab, dass jemand eine Zahl größer als 1000 oder kleiner als 1 eingibt
 *   o Um die Abarbeitung einer Schleife zu beenden, können Sie den von "switch-case" bekannten Befehl break; verwenden
 *   o Zur Hilfe ist folgender Programmablaufplan gegeben:
 *
 *       << Primzahlen.JPG >>
 *
 * Zum Beispiel:
 *
 * +---------+------------------------------------------------------+
 * | Eingabe | Result                                               |
 * +---------+------------------------------------------------------+
 * | 8       | Bitte geben Sie eine Zahl zwischen 1 und 1000 ein,   |
 * |         | bis zu der Sie alle Primzahlen ausrechnen wollen:    |
 * |         |                                                      |
 * |         | 2 ist eine Primzahl                                  |
 * |         | 3 ist eine Primzahl                                  |
 * |         | 5 ist eine Primzahl                                  |
 * |         | 7 ist eine Primzahl                                  |
 * +---------+------------------------------------------------------+
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
    int iobergrenze = 0;
    int kandidat = 1;
    int teiler = 0;

    //Benutzereingabe der Zahl, solange keine gueltige Zahl eingegeben wurde
    do {
    printf("Bitte geben Sie eine Zahl zwischen 1 und 1000 ein, bis zu der Sie alle Primzahlen ausrechnen wollen:\n");
    scanf("%i", &iobergrenze);
    } while (iobergrenze>1000 || iobergrenze <=0);
  
    //Schleife fuer Primzahlkandidaten
    for (kandidat=2;kandidat<=iobergrenze;kandidat++)
    {
        //Schleife fuer moegliche Teiler
        for (teiler=2;teiler<=kandidat;teiler++)
        {
            //Ausgabe falls Zahl Primzahl
            if(teiler==kandidat)
            {
                printf("\n%d ist eine Primzahl", kandidat);
            }
            //Scheifenabbruch falls Zahl keine Primzahl
            else
            {
                if(kandidat%teiler == 0)
                {
                    break;
                }
            }
        }
    }
    return 0;
}
