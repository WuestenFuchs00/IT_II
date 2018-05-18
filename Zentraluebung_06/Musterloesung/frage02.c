/**
 * Zentralübung 06
 *
 * Frage 2
 *
 * Die Firma ISA GmbH möchte eine Datenbank für ihre Kaffeebohnen anlegen. Diese soll das Gewicht 
 * der Bohnensorte und deren Stärke (schwach oder stark) beinhalten.
 *
 * Hinweise:
 *   o Definieren Sie die maximale Array Größe als "2" mit einem Präprozessorbefehl
 *   o Definieren Sie sich einen Datentyp enum STAERKE mit den Elementen "STARK" und "SCHWACH"
 *   o Definieren Sie sich einen Strukturdatentyp BOHNE mit den Elementen
        o Stärke der Bohnensorte (Enum STAERKE)
        o Gewicht der Bohnensorte (float)
 *   o Lesen Sie vom Benutzer nun die benötigten Daten ein. Es sollen so lange Daten eingelesen 
 *     werden bis die maximale Array Größe erreicht ist.
 *   o Für das Einlesen der Stärke werden sie eine Hilfsvariable benötigen, welche Sie anschließend 
 *     wieder mit ihrem Struct referenzieren müssen.
 *   o Geben Sie zum Schluss die eingelesenen Daten wieder aus.
 *   o Für die Ausgabe der Bohnenstärke müssen sie eine Fallunterscheidung zwischen Schwach und Stark 
 *     implementieren. Falls der Benutzer etwas anderes als einen dieser Fälle eingegeben hat, soll
 *     seine Eingabe ausgegeben werden
 *
 * Zum Beispiel:
 *
 * +---------+---------------------------------------------------------------+
 * | Eingabe | Result                                                        |
 * +---------+---------------------------------------------------------------+
 * | 12.456  | Bitte geben Sie das Gewicht der 1. Bohnensorte ein:           |
 * | 1       | Bitte geben Sie die Staerke der 1. Bohnensorte ein [0,1]:     |
 * | 785.45  | Bitte geben Sie das Gewicht der 2. Bohnensorte ein:           |
 * | 0       | Bitte geben Sie die Staerke der 2. Bohnensorte ein [0,1]:     |
 * |         |                                                               |
 * |         | Gewicht / Staerke                                             |
 * |         | 12.46 / Stark                                                 |
 * |         | 785.45 / Schwach                                              |
 * +---------+---------------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */

//Praeprozessoranweisungen
#include <stdio.h>
#define MAX 2
 
//Aufzaehlungsdatentyp fuer Staerke
typedef enum {
    SCHWACH,
    STARK
} STAERKE;
 
//Strukturdatentyp fuer Bohnen
typedef struct {
    STAERKE staerke;
    float fGewicht;
} BOHNE;
 
//Hauptfunktion
int main() {
    //Variablendeklaration
    BOHNE ABohnen[MAX];
    int i = 0;

    int iHilf = 0;
 
    //Einlesen
    for(i = 0; i < MAX; i++)
    {
        printf("Bitte geben Sie das Gewicht der %i. Bohnensorte ein:", i + 1);
        scanf("%f", &ABohnen[i].fGewicht);
 
        printf("\nBitte geben Sie die Staerke der %i. Bohnensorte ein [0,1]:\n", i + 1);
        scanf("%i", &iHilf);
 
        ABohnen[i].staerke = iHilf;
    }
 
    //Ausgeben
    printf("\nGewicht / Staerke");
    for(i = 0; i < MAX; i++)
    {
        printf("\n%.2f", ABohnen[i].fGewicht);
 
        if(ABohnen[i].staerke == SCHWACH)
        {
            printf(" / Schwach");
        }
        else if(ABohnen[i].staerke == STARK)
        {
            printf(" / Stark");
        }
        else
        {
            printf("%i", ABohnen[i].staerke);
        }
    }
 
    return 0;
}