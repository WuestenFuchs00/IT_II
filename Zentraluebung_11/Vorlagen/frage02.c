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