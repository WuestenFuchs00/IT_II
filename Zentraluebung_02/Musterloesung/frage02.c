/**
 * Zentralübung 2
 *
 * Frage 2
 *
 * Ausgangssituation:
 *
 * Es gibt 4 Sorten von Werkstücken: klein/groß bzw. Metall/Plastik. Die Sortiervorschrift ist in der 
 * untenstehenden Grafik (Anlage.JPG) gegeben. Die Gatter sind standardmäßig geoeffnet (entspricht 
 * Variablenwert 0).
 *
 * Zur Verfügung stehende Sensoren:
 *
 *  o Lichtschranke LS: Sensorwert 1, wenn kleines Werkstück durchläuft
 *  o Induktionssensor Ind: Sensorwert 1, wenn Werkstück aus Metall
 *  o Kunde A benötigt kleine Werkstücke aus Metall
 *  o Kunde B benötigt große Werkstücke aus Plastik
 *
 * Aufgabe:
 *
 * Implementieren Sie ein C-Programm, welches
 *
 *  o die Sensorwerte LS und Ind einlesen kann,
 *  o mittel boolscher Algebra die Gatter A und B steuert und
 *  o die Zustände der Gatter in der Konsole ausgibt (Variablenwert 1, wenn Gatter geschlossen)
 *
 * Bei gegebenen Sensorwerten soll die Ausgabe wie folgt aussehen:
 *
 *   Wert des Lichtsensors:
 *   Wert des Induktionssensors:
 *   GatterA:
 *   GatterB:
 *
 * Zum Beispiel:
 *
 * +---------+--------------------------------------+
 * | Eingabe | Result                               |
 * +---------+--------------------------------------+
 * | 0       | Wert des Lichtsensors:               |
 * | 0       | Wert des Induktionssensors:          |
 * |         | GatterA: 0                           |
 * |         | GatterB: 1                           |
 * +---------+--------------------------------------+
 */
#include <stdio.h>
 
int main()
{
    //Variablendeklaration
    int iLichtsensor = 0;
    int iInduktionssensor = 0;
    int iGatter1 = 0;
    int iGatter2 = 0;
 
    //Einlesen der Sensorwerte
    printf("Wert des Lichtsensors:");
    scanf("%d", &iLichtsensor);
 
    printf("\nWert des Induktionssensors:");
    scanf("%d", &iInduktionssensor);
 
    //Steuerung der Gatter mittels boolscher Algebra
    iGatter1 = iLichtsensor && iInduktionssensor;
    iGatter2 = !iLichtsensor && !iInduktionssensor;
 
    //Ausgabe der Zustaende in der Konsole
    printf("\nGatterA: %d", iGatter1);
    printf("\nGatterB: %d", iGatter2);
 
    return 0;
}
