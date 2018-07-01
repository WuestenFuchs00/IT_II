/**
 * Zentralübung 12
 *
 * Frage 1
 *
 * Im folgendem wird ein Stapelspeicher implementiert. Bei einem Stapelspeicher können Elemente nur auf 
 * dem Stapel gelegt und auch nur von oben wieder entnommen werden. Dies wird auch als Last-In-First-Out-
 * Prinzip (LIFO) bezeichnet.
 *
 * Dazu werden zwei Aktionen integriert:
 *   o Push: Neues Element oben auf dem Stapel legen
 *   o Pop: Oberstes Element vom Stapel herunternehmen
 *
 * Das Prinzip kann graphisch folgendermaßen interpretiert werden:
 *
 *   << Statisch1.JPG >>
 *
 * Bei dieser Variante, sollen Sie einen statischen Stapelspeicher implementieren. Dabei wird der Stapel 
 * als Array mit fester Länge repräsentiert. Orientieren Sie sich an folgendem Nassi-Shneiderman-Diagramm:
 *
 *   << statisch2.JPG >>
 *
 * +---------------+-------------------------------------------------------------------+
 * | Eingabe       | Result                                                            |
 * +---------------+-------------------------------------------------------------------+
 * | 1             | Neuer Eintrag (1) oder beenden (0)?                               |
 * | IT ist cool   | Zu speichernden Text eingeben: Neue Groesse 68 byte.              |
 * | 0             | Neuer Eintrag (1) oder beenden (0)?                               |
 * |               | Eintrag gefunden mit Text: IT ist cool                            |
 * |               | Neue Groesse 68 byte.                                             |
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
 
typedef struct LISTENEINTRAG{
    char szText[TEXTSIZE];
} LISTENEINTRAG;
 
typedef struct {
    LISTENEINTRAG eintrag[3];
    int index;
    int iGroesse;
} LISTE;
 
void push(LISTE* Liste, char szText[TEXTSIZE])
{
    // ->szText
	strcpy((Liste->eintrag+Liste->index)->szText, szText);
	Liste->index++;
	Liste->iGroesse = sizeof(*Liste);
    printf("Neue Groesse %i byte.\n", Liste->iGroesse);
}
 
void pop(LISTE* Liste)
{
    Liste->index--;
	printf("Eintrag gefunden mit Text: %s", (Liste->eintrag+Liste->index)->szText);
	strcpy((Liste->eintrag+Liste->index)->szText, "");
    Liste->iGroesse = sizeof(*Liste);
    printf("Neue Groesse %i byte.\n\n", Liste->iGroesse);
}
 
int main()
{
    LISTE Liste;
    Liste.iGroesse = sizeof(Liste);
    Liste.index = 0;
 
    char puffer[TEXTSIZE];
    char* c = NULL;
    int iWeiter = 0;
 
    do
    {
        printf("Neuer Eintrag (1) oder beenden (0)?\n");
        scanf("%i\n", &iWeiter);
        if ( iWeiter )
        {
            printf("Zu speichernden Text eingeben: "); 
            c = fgets(puffer, TEXTSIZE, stdin);
            if (c == NULL) {
                return 1;
            }            
            push(&Liste, puffer);
        }
    } while ( iWeiter );
 
    do
    {
        pop(&Liste);
    } while ( Liste.index > 0 );
 
    return 0;
}
