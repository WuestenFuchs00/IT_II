/**
 * Heimarbeit 11
 *
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm, welches eine Personendatenbank anlegt und Namen, sowie 
 * Geburtsjahr abspeichert. 
 * Die Datenbank soll so lange erweitert werden, wie der Nutzer dies möchte. Danach soll die komplette 
 * Datenbank ausgegeben werden.
 *
 * Hinweise:
 *   o Benutzen Sie eine verkettete Liste 
 *   o Definieren Sie sich hierfür die Datentypen
 *       o Person mit Name und Geburtsjahr
 *       o Listenelement (KNOTEN) mit einer Variable vom Typ Person und Zeiger auf nächstes Listenelement
 *       o Listenkopf (LISTE) mit Anzahl Listeneinträge und Zeiger auf erstes Listenelement
 *   o Erstellen Sie eine Funktion, die ein neues Element erstellt und es an erster Stelle einfügt
 *
 * Zum Beispiel:
 *
 * +------------+--------------------------------------+
 * | Eingabe    | Result                               |
 * +------------+--------------------------------------+
 * | 1          | [0] Ausgabe [1] Hinzufuegen          |
 * | Spreiter   | Was moechten Sie tun?                |
 * | 1992       |                                      |
 * | 1          | Bitte geben Sie den Namen ein:       |
 * | Glaese     | Bitte geben Sie das Geburtsjahr ein: |
 * | 1993       | [0] Ausgabe [1] Hinzufuegen          |
 * | 0          | Was moechten Sie tun?                |
 * |            |                                      |
 * |            | Bitte geben Sie den Namen ein:       |
 * |            | Bitte geben Sie das Geburtsjahr ein: |
 * |            | [0] Ausgabe [1] Hinzufuegen          |
 * |            | Was moechten Sie tun?                |
 * |            |                                      |
 * |            | Person: 1                            |
 * |            | Name: Glaese                         |
 * |            | Geburstjahr: 1993                    | 
 * |            |                                      |
 * |            | Person: 2                            |
 * |            | Name: Spreiter                       |
 * |            | Geburstjahr: 1992                    | 
 * +---------------------------------------------------+
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
#include <stdlib.h>
#include <string.h>
#define STRSIZE 80


//Nutzdaten Definition
typedef struct
{
    char name[STRSIZE];
    int geburtsjahr;
}PERSON;

//Listenelement Definition
typedef struct KNOTEN
{
    PERSON person;
    struct KNOTEN * naechster;
}KNOTEN;

//Listenkopf Definition
typedef struct
{
    KNOTEN * erster;
    int iAnzahl;
}LISTE;

//Funktion zum Einfügen eines Elementes an erster Stelle
void insertfront (LISTE *Liste)
{
    // Speicherplatz fuer Listenelement (Knoten) reservieren
    KNOTEN * pKnoten = (KNOTEN *) malloc(sizeof(KNOTEN));
    
    // Benutzereingaben in neues Listenelement speichern
    printf("\n\nBitte geben Sie den Namen ein:");
    if(scanf ("%s", pKnoten->person.name) == 0)
    {
        printf("\nFalsche Eingabe!");
    }
    printf("\nBitte geben Sie das Geburtsjahr ein:");
    if(scanf("%i", &(pKnoten->person.geburtsjahr)) == 0)
    {
        printf("\nFalsche Eingabe!");
    }
    
    // Erstes Element der Liste als Naechster von neuem Element setzen
    pKnoten->naechster = Liste->erster;
    // Neues Element als erstes Element der Liste und Anzahl der Elemente erhohen
    Liste->erster = pKnoten;
    
    Liste->iAnzahl++;

    printf("\n");
}


int main()
{
    //Variableninitialisierung
    int i;
    KNOTEN *pTemp = NULL;
    
    LISTE Liste;
    Liste.erster = NULL;
    Liste.iAnzahl = 0;
    
    //Schleife zum Einlesen
    do
    {
        printf("[0] Ausgabe [1] Hinzufuegen");
        printf("\nWas moechten Sie tun?");
        if (scanf("%i", &i) == 0 || i < 0 || i > 1)
        {
            printf("\nFalsche Eingabe!");
            return 1;
        }
        
        if ( i )
        {
            // Element am Anfang der Liste einfuegen
            insertfront(&Liste);
        }
        
    } while( i );

    //Ausgabe der Liste
    i = 1;
    pTemp = Liste.erster;
    while(pTemp != 0)
    {
        printf("\n\nPerson: %i \nName: %s \nGeburstjahr: %i", i++, pTemp->person.name, pTemp->person.geburtsjahr);
        pTemp = pTemp->naechster;
    }
    
    return 0;
}

