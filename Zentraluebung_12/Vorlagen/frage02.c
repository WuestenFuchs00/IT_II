/**
 * Zentralübung 12
 *
 * Frage 2
 *
 * Es soll wieder ein Stapelspeicher nach dem in der letzten Aufgabe erklärten Prinzip implementiert werden.
 * 
 * Bei dieser Variante, sollen Sie einen dynamischen Stapelspeicher implementieren. Dieser wird als 
 * verkettete Liste mit wechselnder Länge implementiert.
 *
 * Orientieren Sie sich an folgendem Nassi-Shneiderman-Diagramm:
 *
 *   << Dynamoscher.JPG >>
 *
 * +---------------+-------------------------------------------------------------------+
 * | Eingabe       | Result                                                            |
 * +---------------+-------------------------------------------------------------------+
 * | 1             | Neuer Eintrag (1) oder beenden (0)?                               |
 * | IT ist cool   | Zu speichernden Text eingeben: Neue Groesse 48 byte.              |
 * | 1             | Neuer Eintrag (1) oder beenden (0)?                               |
 * | TUM ist cool  | Zu speichernden Text eingeben: Neue Groesse 80 byte.              |
 * | 0             | Neuer Eintrag (1) oder beenden (0)?                               |
 * |               | Eintrag gefunden mit Text: TUM ist cool                           |
 * |               | Neue Groesse 48 byte.                                             |
 * |               |                                                                   |
 * |               | Eintrag gefunden mit Text: IT ist cool                            |
 * |               | Neue Groesse 16 byte.                                             |
 * +---------------+-------------------------------------------------------------------+
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
#define TEXTSIZE 20
 
typedef struct LISTENEINTRAG {
    struct LISTENEINTRAG* naechster;
    char szText[TEXTSIZE];
} LISTENEINTRAG;
 
typedef struct {
    LISTENEINTRAG* erster;
    int iGroesse;
} LISTENKOPF;
 
void push(LISTENKOPF* pKopf, char szText[])
{
    printf("Neue Groesse  byte.\n", );
}
 
void pop(LISTENKOPF* pKopf)
{
    printf("Eintrag gefunden mit Text: ", );
    
    printf("Neue Groesse  byte.\n\n", );
}
 
int main()
{
    LISTENKOPF Kopf;
    LISTENKOPF* pKopf = &Kopf;
    Kopf.erster = NULL;
    Kopf.iGroesse = sizeof(LISTENKOPF);
 
    char puffer[TEXTSIZE];
    char* c = NULL;
    int iWeiter = 0;

 
    do
    {
        printf("Neuer Eintrag (1) oder beenden (0)?\n");
        scanf("\n", );
        if ()
        {
            printf("Zu speichernden Text eingeben: ");
             
            c = fgets(puffer, TEXTSIZE, stdin);
            if (c == NULL){
                return 1;
            }
             
        }
    } while ();
 
    do
    {
         
    } while ();
}