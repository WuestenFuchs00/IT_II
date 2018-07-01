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
    LISTENEINTRAG* neuesElement;
    neuesElement = (LISTENEINTRAG*) malloc(sizeof(LISTENEINTRAG));
    strcpy(neuesElement->szText, szText);
    neuesElement->naechster = pKopf->erster;
    pKopf->erster = neuesElement;
    pKopf->iGroesse += sizeof(LISTENEINTRAG);
    printf("Neue Groesse %i byte.\n", pKopf->iGroesse);
}
 
void pop(LISTENKOPF* pKopf)
{
    LISTENEINTRAG* temp = NULL;
    printf("Eintrag gefunden mit Text: %s", pKopf->erster->szText);
    if (pKopf->erster->naechster != NULL)
    {
        temp = pKopf->erster->naechster;
 
    }
 
    free(pKopf->erster);
    pKopf->erster = temp;
 
    pKopf->iGroesse -= sizeof(LISTENEINTRAG);
    printf("Neue Groesse %i byte.\n\n", pKopf->iGroesse);
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
        scanf("%i\n", &iWeiter);
        if (iWeiter)
        {
            printf("Zu speichernden Text eingeben: ");
            fflush(stdin);
            c = fgets(puffer, TEXTSIZE, stdin);
            if (c == NULL){
                return 1;
            }
            push(pKopf, puffer);
        }
    } while (iWeiter);
 
    do
    {
        pop(pKopf);
    } while (pKopf->erster != NULL);
}