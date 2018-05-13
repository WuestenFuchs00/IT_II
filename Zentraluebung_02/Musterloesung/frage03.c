/**
 * Zentralübung 2
 *
 * Frage 3
 *
 * Ausgangssituation:
 *
 * Für einen Kurzstrecken-Flug soll die durchschnittliche Flughöhe ermittelt werden. Hierfür werden 
 * während des Fluges drei Messwerte erhoben, welche anschließend arithmetisch gemittelt werden. 
 * Da dem Flugzeug nur ein extrem kleines Steuergerät zur Verfügung steht, soll das Programm möglichst 
 * wenig Rechenkapazität beanspruchen. Aus diesem Grund werden nur ganzzahlige Werte für die Flughöhe 
 * ermittelt. Für weitere Berechnungen auf dem Steuergerät soll die gemittelte Flughöhe auf drei 
 * Nachkommastellen genau ausgegeben werden. Für die Anzeige auf dem Display des Flugzeuges genügt 
 * der ganzzahlige Wert.
 *
 * Aufgabe:
 *
 * Schreiben Sie ein C-Programm, dass diese drei Messwerte einliest, arithmetisch mittelt und wie 
 * gewünscht ausgibt.
 *
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Bitte geben Sie den ersten Messwert ein:
 *   Bitte geben Sie den zweiten Messwert ein:
 *   Bitte geben Sie den dritten Messwert ein:
 *   Die durchschnittliche Flughoehe betraegt:
 *   Die durchschnittliche int-Flughoehe betraegt:
 *
 * Zum Beispiel:
 *
 * +---------+-----------------------------------------------------+
 * | Eingabe | Result                                              |
 * +---------+-----------------------------------------------------+
 * | 4567    | Bitte geben Sie den ersten Messwert ein:            |
 * | 7894    | Bitte geben Sie den zweiten Messwert ein:           |
 * | 1587    | Bitte geben Sie den dritten Messwert ein:           |
 * |         | Die durchschnittliche Flughoehe betraegt: 4682.667  |
 * |         | Die durchschnittliche int-Flughoehe betraegt: 4682  |
 * +---------+-----------------------------------------------------+
 */
#include <stdio.h>
 
int main()
{
    //Variablendeklaration
    int iMesswert1 = 0;
    int iMesswert2 = 0;
    int iMesswert3 = 0;
    int iMittel = 0;
    float fMittel = 0;

    //Einlesen der Messwerte
    printf("Bitte geben Sie den ersten Messwert ein:");
    scanf("%i", &iMesswert1);
 
    printf("\nBitte geben Sie den zweiten Messwert ein:");
    scanf("%i", &iMesswert2);
 
    printf("\nBitte geben Sie den dritten Messwert ein:");
    scanf("%i", &iMesswert3);
 
    //Berechnung des float-Mittelwerts
    //int-Messwerte werden implizit zu floats gecastet
    fMittel = (iMesswert1 + iMesswert2 + iMesswert3) / 3.0;
 
    //Ausgabe
    printf("\nDie durchschnittliche Flughoehe betraegt: %.3f", fMittel);
 
    //Expliziter Typecast von float zu int
    iMittel = (int) fMittel;
 
    //Ausgabe
    printf("\nDie durchschnittliche int-Flughoehe betraegt: %i", iMittel);
 
    return 0;
}
