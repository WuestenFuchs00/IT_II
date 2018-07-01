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
    strcpy((*(Liste->eintrag + Liste->index)).szText, szText);
    Liste->index++;
    printf("Neue Groesse %li byte.\n", sizeof(*Liste));
}
 
void pop(LISTE* Liste)
{
    Liste->index--;
    printf("Eintrag gefunden mit Text: %s", (*(Liste->eintrag + Liste->index)).szText);
    strcpy((*(Liste->eintrag + Liste->index)).szText, "");
    printf("Neue Groesse %li byte.\n\n", sizeof(*Liste));
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
        if (iWeiter)
        {
            printf("Zu speichernden Text eingeben: ");
            fflush(stdin);
            c = fgets(puffer, TEXTSIZE, stdin);
            if (c == NULL) {
                return 1;
            }
            push(&Liste, puffer);
        }
    } while (iWeiter);
 
    do
    {
        pop(&Liste);
    } while (Liste.index > 0);
 
    return 0;
}