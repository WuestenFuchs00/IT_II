/**
 * Zentralübung 07
 *
 * Frage 3
 *
 * Schreiben Sie ein vollständiges C-Programm, welches einen Text einliest, nach einem vom Nutzer 
 * eingegebenen Wort durchsucht und dieses durch ein neues Wort ersetzt.
 *
 * Hinweise:
 *
 *   o Initialisieren Sie für den Text einen String mit 70 Zeichen und für das gesuchte und neue Wort 
 *     jeweils einen String mit 19 Zeichen
 *   o Lesen Sie den Text mit fgets und die einzelenen Wörter mit scanf ein
 *   o Suchen Sie den Text nach dem gewünschten Wort ab und ersetzen Sie dieses mit einem neuen Wort 
 *     gleicher Länge
 *   o Die Wörter werden nur ausgetauscht, falls sie die gleiche Länge haben, anderenfalls wird eine 
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
 * |                                        | und gibt die Position des ersten Auftretens zurück,  |
 * |                                        | sonst NULL.                                          |
 * +----------------------------------------+------------------------------------------------------+
 * | uint strlen(const char* s1);           | Gibt die Länge von s1 ohne String-Ende '\0' Zeichen  |
 * |                                        | zurück.                                              |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strncat(char* s1,                | Hängt s2 an das Ende von s1 an. Hängt maximal n      |
 * |               const char* s2, uint n); | Zeichen an.                                          |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strncpy(char* s1,                | Kopiert n Zeichen aus dem String s2 in den String s1 |
 * |               const char* s2, uint n); |                                                      |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strstr(const char* s1,           | Sucht in s1 nach einem Teilstring s2. Liefert die    |
 * |              const char* s2);          | Position von s2 in s1 zurück.                        |
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
//Einbinden benoetigter Bibliotheken
#include <stdio.h>
#include <string.h>
 
int main(){
 
    //Variableninitialisierung
	char text[71]; // 70 Zeichen und Endzeichen '\0'
	char wort[20]; // 19 Zeichen und Endzeichen '\0'
	char neu[20];
	char *pWort = NULL;
 
    //Eingabe des Strings
    printf("Bitte geben Sie einen Text ein:");
    if( ( fgets(text, 71, stdin) ) == 0 ){
        printf("\nFehler!");
        return 1;
    }
 
    //Auszubesserendes Wort
    printf("\nBitte geben Sie das Wort an, das Sie ueberschreiben wollen:");
    scanf("%19s", wort);
 
    //String durchsuchen
	pWort = strstr(text, wort);
 
    //neuer String
    printf("\nWie heisst das neue Wort?");
    scanf("%19s", neu);
	
    //bei gleichen Stringlaengen
    if ( pWort != NULL && (strlen(wort) == strlen(neu)) ) { 
        //Ueberschreiben der Zeichen
        for( int i = 0; i < 19; i++ ) {
			*(pWort++) = neu[i]; // ++ wird immer nach * ausgewertet
        } 
        printf("\n\nDer Text heisst jetzt:\n%s", text);
    } 
    //sonst
    else{
        printf("\nWoerter muessen gleich lang sein!");
        return 1;
    }
 
    return 0;
}
