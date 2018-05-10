/**
 * Zentralübung 3
 *
 * Frage 1
 *
 * Ausgangssituation:
 * 
 * Der abgebildete Heizungsregler in einem Auto soll mit Hilfe einer Switch-Case-Struktur
 * programmiert werden.
 *
 * Aufgabe:
 *
 * Implementieren Sie ein C-Programm, welches 
 *   o mittels switch-case Struktur die Aktoren für den "oberen Lüfter", die "Fußheizung" und 
 *     die "Frontscheibenheizung" im entsprechenden Zustand auf "1" schaltet
 *   o eine Fehlermeldung ausgibt und alle Aktoren auf "0" setzt, sollte der Benutzer den Schalter
 *     auf eine unzulässige Position drehen 
 *
 * Hinweise und Tipps:
 *   o In der gezeigten Grafik (Heizungsregler) befindet sich der Schalter auf Schalterstellung 2
 * 
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Schalterstellung:
 *
 *   Aktivierte Luefter in aktueller Schalterstellung _:
 *   Oberer Luefter:
 *   Fussheizung:
 *   Frontscheibenheizung:
 *
 * Zum Beispiel:
 *
 *  +----------+-------------------------------------------------------+
 *  | Eingabe  | Result                                                |
 *  +----------+-------------------------------------------------------+
 *  | 0        | Schalterstellung:                                     |
 *  |          |                                                       |
 *  |          | Aktivierte Luefter in aktueller Schalterstellung 0:   |
 *  |          | Oberer Luefter: 1                                     |
 *  |          | Fussheizung: 0                                        |
 *  |          | Frontscheibenheizung: 0                               |
 *  +----------+-------------------------------------------------------+
 */
#include<stdio.h>
 
int main()
{
    //Variablendeklaration
    int iSchalterstellung = 0;
    int iOben = 0;
    int iFuss = 0;
    int iFront = 0;

    //Schalterstellung einlesen
    printf("Schalterstellung:\n");
    scanf("%i", &iSchalterstellung);
 
    //switch-case zum Setzen der Aktoren
    switch(iSchalterstellung)
    {
        case 0:
            iOben = 1;
            iFuss = 0;
            iFront = 0;
            break;
        case 1:
            iOben = 1;
            iFuss = 1;
            iFront = 0;
            break;
        case 2:
            iOben = 0;
            iFuss = 1;
            iFront = 0;
            break;
        case 3:
            iOben = 0;
            iFuss = 1;
            iFront = 1;
        break;
        default:
            printf("Fehler bei der Schalterstellung!\n");
            iOben = 0;
            iFuss = 0;
            iFront = 0;
        break;
    }
 
    //Ausgabe der Zustaende der Aktoren
    printf("\nAktivierte Luefter in aktueller Schalterstellung %i:\n", iSchalterstellung);
    printf("Oberer Luefter: %i\nFussheizung: %i\nFrontscheibenheizung: %i", iOben, iFuss, iFront);
 
    return 0;
}