/**
 * Zentral�bung 07
 *
 * Frage 3
 *
 * Schreiben Sie ein vollst�ndiges C-Programm, welches einen Text einliest, nach einem vom Nutzer 
 * eingegebenen Wort durchsucht und dieses durch ein neues Wort ersetzt.
 *
 * Hinweise:
 *
 *   o Initialisieren Sie f�r den Text einen String mit 70 Zeichen und f�r das gesuchte und neue Wort 
 *     jeweils einen String mit 19 Zeichen
 *   o Lesen Sie den Text mit fgets und die einzelenen W�rter mit scanf ein
 *   o Suchen Sie den Text nach dem gew�nschten Wort ab und ersetzen Sie dieses mit einem neuen Wort 
 *     gleicher L�nge
 *   o Die W�rter werden nur ausgetauscht, falls sie die gleiche L�nge haben, anderenfalls wird eine 
 *     Fehlermeldung ausgegeben.
 *
 * Zum Beispiel:
 *
 * +-------------------+-------------------------------------------------------------+
 * | Eingabe           | Result                                                      |
 * +-------------------+-------------------------------------------------------------+
 * | IT ist voll bloed | Bitte geben Sie einen Text ein:                             |
 * | bloed             | Bitte geben Sie das Wort an, das Sie ueberschreiben wollen: |
 * | super             | Wie heisst das neue Wort?                                   |
 * |                   |                                                             |
 * |                   | Der Text heisst jetzt:                                      |
 * |                   | IT ist voll super                                           |
 * +-------------------+-------------------------------------------------------------+
 *
 * Wichtige Funktionen  aus <string.h>
 *
 * +----------------------------------------+------------------------------------------------------+
 * | Funktion                               | Bedeutung                                            |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strchr(const char* s, int ch);   | Sucht im String s nach dem Zeichen ch (ASCII code)   |
 * |                                        | und gibt die Position des ersten Auftretens zur�ck,  |
 * |                                        | sonst NULL.                                          |
 * +----------------------------------------+------------------------------------------------------+
 * | uint strlen(const char* s1);           | Gibt die L�nge von s1 ohne String-Ende '\0' Zeichen  |
 * |                                        | zur�ck.                                              |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strncat(char* s1,                | H�ngt s2 an das Ende von s1 an. H�ngt maximal n      |
 * |               const char* s2, uint n); | Zeichen an.                                          |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strncpy(char* s1,                | Kopiert n Zeichen aus dem String s2 in den String s1 |
 * |               const char* s2, uint n); |                                                      |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strstr(const char* s1,           | Sucht in s1 nach einem Teilstring s2. Liefert die    |
 * |              const char* s2);          | Position von s2 in s1 zur�ck.                        |
 * +----------------------------------------+------------------------------------------------------+
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
#include <string.h>
 
int main()
{
    //Variablendeklaration
    char text[71];
    char* parser = NULL;
    char wort[20];
    char neu[20];
    int i = 0;
 
    //Eingabe des Strings
    printf("Bitte geben Sie einen Text ein:");
    if(fgets(text, sizeof(text), stdin) == 0)
    {
        printf("\nFehler!");
        return 1;
    }
 
    //Auszubesserendes Wort
    printf("\nBitte geben Sie das Wort an, das Sie ueberschreiben wollen:");
    scanf("%s", wort);
 
    //neuer String
    printf("\nWie heisst das neue Wort?");
    scanf("%s", neu);
 
    //Beide Strings m�ssen gleich lang sein!
    if(strlen(wort) == strlen(neu))
    {
        //String durchsuchen
        parser = strstr(text, wort);
 
        //Ueberschreiben der Zeichen
        for(i = 0; i < (int)strlen(wort); i++)
        {
            *parser = neu[i];
            parser++;
       }
        printf("\n\nDer Text heisst jetzt:\n%s", text);
    }
 
    //sonst
    else
    {
        printf("\nWoerter muessen gleich lang sein!");
        return 1;
    }
 
    return 0;
}
