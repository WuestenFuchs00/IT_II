/**
 * Zentral�bung 3
 *
 * Frage 1
 *
 * Ausgangssituation:
 * 
 * Das Programm zur Steuerung einer Ampel an einer Kreuzung von zwei Stra�en, Stra�e A kreuzt Stra�e B
 * (siehe Bild Apel.JPG), soll um einen intelligenten Umschaltmechanismus erweitert werden. Zugrunde
 * gelegt wird dabei der Quotient der Verkehrsdichte beider Stra�en (Quotient = Dichte A/Dichte B).
 *
 * Aufgabe:
 *
 * Implementieren Sie ein C-Programm, welches 
 *   o Bei einer Verkehrsdichte von mehr als 200 Fahrzeugen pro Stunde auf einer der beiden Stra�en
 *     soll die Dauer der Gr�n-Phase von Stra�e A mit Verkehrsdichtenquotienten und Stra�e B mit dem
 *     inversen Verkehrsdichtenquotienten multipliziert werden.
 *   o Sofern der erste Fall nicht zutrifft und die Verkehrsdichte der Stra�en jeweils unter 50
 *     Fahrzeuge pro Stunde f�llt, soll die Dauer der Gr�n-Phase der jeweiligen Stra�e auf 50%
 *     reduziert werden.
 *   o Die Startwerte f�r die Gr�nphasenwerte sind f�r Stra�e A=50, f�r Stra�e B=75
 *
 * Die Ausgabe wie folgt aussehen:
 *
 *   o Bitte geben Sie die Verkehrsdichte von Strasse A ein:
 *   o Bitte geben Sie die Verkehrsdichte von Strasse B ein:
 *   o Die Gruenphase fuer Strasse A betraegt:
 *   o Die Gruenphase fuer Strasse B betraegt:
 *
 * Zum Beispiel:
 *
 *  +----------+-------------------------------------------------------+
 *  | Eingabe  | Result                                                |
 *  +----------+-------------------------------------------------------+
 *  | 220      | Bitte geben Sie die Verkehrsdichte von Strasse A ein: |
 *  | 150      | Bitte geben Sie die Verkehrsdichte von Strasse B ein: |
 *  |          | Die Gruenphase fuer Strasse A betraegt: 73.33         |
 *  |          | Die Gruenphase fuer Strasse B betraegt: 51.14         |
 *  +----------+-------------------------------------------------------+
 */
#include <stdio.h>
 
int main()
{
    //Variablendeklaration
    float fDauerA = 50;
    float fDauerB = 75;
    float fDichteA = 0;
    float fDichteB = 0;
    float fDichteQ = 0;

    //Eingabe der Verkehrsdichten
    printf("Bitte geben Sie die Verkehrsdichte von Strasse A ein:");
    scanf("%f", &fDichteA);
 
    printf("\nBitte geben Sie die Verkehrsdichte von Strasse B ein:");
    scanf("%f", &fDichteB);
 
    //Berechnung des Verkehrsdichtenquotienten
    fDichteQ = fDichteA / fDichteB;
 
    //Berechnung der Gr�nphasen
    if(fDichteA > 200 || fDichteB > 200)
    {
        fDauerA *= fDichteQ;
        fDauerB *= 1 / fDichteQ;
    }
    else
    {
        if(fDichteA < 50)
        {
            fDauerA *= 0.5;
        }
        if(fDichteB < 50)
        {
            fDauerB *= 0.5;
        }
    }
 
    printf("\nDie Gruenphase fuer Strasse A betraegt: %.2f", fDauerA);
    printf("\nDie Gruenphase fuer Strasse B betraegt: %.2f", fDauerB);
 
    return 0;
}