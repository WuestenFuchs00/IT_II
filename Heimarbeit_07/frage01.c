/**
 * Heimarbeit 07
 *
 * Frage 1
 *
 * Für eine verfahrenstechnische Anlage soll ein vollständiges C-Programm zur Regelung entworfen werden, 
 * das sowohl die Temperatur, als auch den Füllstand eines Behälters innerhalb eines bestimmten Intervalls 
 * hält. Hierfür soll ein Zweipunktregler verwendet werden. Dieser stellt ein Stellsignal auf AN oder AUS 
 * (bzw. 1 oder 0), wenn ein bestimmter Minimalwert bzw. Maximalwert unter-/überschritten wurde.
 * Der zu regelnde Behälter ist auf folgender Grafik dargestellt. Das Regelungsprogramm soll das 
 * Zuflussventil, sowie die Heizspirale regeln. Der manuelle Abfluss dient zum Ablassen der Flüssigkeit, 
 * um z.B. Proben zu entnehmen.
 *
 *   << Behälter.JPG >>
 *
 * Hinweise:
 *
 *  o Schreiben Sie zunächst eine Funktion für den Zweipunktregler, welche bei Überschreiten eines 
 *    Maximalwertes das Ausgangssignal auf 0 setzt, bzw. bei Unterschreiten eines Minimalwertes das 
 *    Ausgangssignal auf 1
 *  o Die Temperatur soll zwischen 85.1 und 85.5 Grad Celsius gehalten werden
 *  o Der Füllstand soll zwischen 525.0 und 550.0 ccm gehalten werden
 *  o Befindet sich der Ist-Wert im Soll-Bereich, soll Befüllen und Aufheizen deaktiviert sein
 *  o Die Maximal- und Minimalwerte sollen fest definiert sein
 *  o Das Programm soll so lange laufen, bis der Benutzer es beendet
 *  o Da keine Sensoren für die Istwerte in Moodle simuliert werden können, werden die Istwerte über 
 *    die Eingabe eingelesen.
 *  o In jedem Durchlauf sollen die Istwerte eingelesen werden und anschließend entschieden und 
 *    ausgegeben werden, ob aufgeheizt/befüllt aktiviert ist oder nicht
 *
 * Zum Beispiel:
 *
 * +---------+--------------------------------------------------------------------------------------+
 * | Eingabe | Result                                                                               |
 * +---------+--------------------------------------------------------------------------------------+
 * | 35.5    | Aktuelle Temperatur:                                                                 |
 * | 548     | Aktueller Fuellstand:                                                                |          
 * | 1       | Aufheizen aktiviert!                                                                 |      
 * | 85.8    | Befuellen deaktiviert!                                                               |
 * | 520.1   | Programm weiter laufen lassen? [0]Nein [1]Ja                                         |      
 * | 0       | Aktuelle Temperatur:                                                                 |
 * |         | Aktueller Fuellstand:                                                                |
 * |         | Aufheizen deaktiviert!                                                               |
 * |         | Behaelter wird befuellt!                                                             |
 * |         | Programm weiter laufen lassen? [0]Nein [1]Ja                                         |
 * +---------+--------------------------------------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -lm -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 *
 * Option -lm wird verwendet, um die <math.h> Bibliothek von C einzubinden.
 */
#include <stdio.h>

#define MIN_TEMPERATUR 85.1
#define MAX_TEMPERATUR 85.5
#define MIN_FUELLSTAND 525.0
#define MAX_FUELLSTAND 550.0

//Funktion fuer den Zweipunktregler
void zweitpunktregler (float fTemperatur, float fFuellstand, int *iAufheizen, int *iBefuellen) {
	*iAufheizen = ( fTemperatur < MIN_TEMPERATUR ) ? 1 : ( fTemperatur > MAX_TEMPERATUR ) ? 0 : 0;
	*iBefuellen = ( fFuellstand < MIN_FUELLSTAND ) ? 1 : ( fFuellstand > MAX_FUELLSTAND ) ? 0 : 0;
}
  
//main-Funktion
int main(){
     
    //Variablendeklaration
	float fTemperatur, fFuellstand;
	int iAufheizen = 0, iBefuellen = 0;
	int iEnd = 0;
      
    //Schleife um Programm so lange auszuführen wie Benutzer es wuenscht
    do {
        //Einlesen der aktuellen Werte
        printf("Aktuelle Temperatur:");
        if ( scanf("%f", &fTemperatur) == 0 ) {
			printf("\nUngueltige Eingabe!");
			return 1;
		}
         
        printf("\nAktueller Fuellstand:");
        if ( scanf("%f", &fFuellstand) == 0 ) {
			printf("\nUngueltige Eingabe!");
			return 1;
		}
      
        //Funktionsaufruf um Stellsignale zu bestimmen
		zweitpunktregler(fTemperatur, fFuellstand, &iAufheizen, &iBefuellen);		
      
        //Ausgabe der Stellsignale (Fallunterscheidung)
        if ( !iAufheizen )    
            printf("\nAufheizen deaktiviert!");
		else 
            printf("\nAufheizen aktiviert!");

		if ( !iBefuellen )
            printf("\nBefuellen deaktiviert!");
		else
            printf("\nBehaelter wird befuellt!");
      
        //Abbruchabfrage
        printf("\nProgramm weiter laufen lassen? [0]Nein [1]Ja\n");
        scanf("%i", &iEnd);
	} while ( iEnd );
	
    return 0;
}