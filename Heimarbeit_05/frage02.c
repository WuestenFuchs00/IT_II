/**
 * Heimarbeit 05
 *
 * Frage 2
 *
 * Ausgangssituation:
 *
 * An einem Motorenprüfstand soll die Drehmoment-Motorleistung-Drehzahl-Kennlinie ermittelt werden. 
 * Schreiben Sie hierzu ein C-Programm in den folgenden Teilschritten.
 *
 * << Motorpruefstand.JPG >>
 *
 * Das Programm wird Schritt für Schritt erstellt. Ihr Code wird in eine im Hintergrund laufende 
 * Main-Funktion eingebettet. 
 *
 * Folgende Variablen sind bereits initialisiert:
 *
 *   int i = 0;
 *   int iMerk = 0;
 *   int iEnd = 0;
 *
 * Aufgabe (Frage 2): 
 *
 * Lesen Sie zunächst die Messreihen, bestehend aus Drehzahl, Drehmoment und Leistung in einem 
 * mehrdimensionalem Array mit 3 Zeilen und 6 Spalten ein. Initialisieren Sie hierfür zuvor den
 * Array fMeasure, welcher maximal 6 Messreihen speichern kann. Informieren Sie den Nutzer, 
 * sollte er eine siebte Messreihe eingeben wollen. Speichern Sie dafür die Anzahl der bereits 
 * eingelesenen Datensätze in iMerk.
 *
 * Zum Beispiel:
 *
 * +---------+------------------------------------------------------------+
 * | Eingabe | Result                                                     |
 * +---------+------------------------------------------------------------+
 * | 1587.12 | Bitte die 1te Drehzahl in U/min eingeben:                  |
 * | 80.87   | Bitte das 1te Drehmoment in Nm eingeben:                   |
 * | 20.123  | Bitte die 1te Leistung in kW eingeben:                     |
 * | 0       | Ist ein weiterer Messwert notwendig? ja (1) nein (0)       |
 * +---------+------------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -lm -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
#include <stdio.h> 

int main () {
	//Variablendeklaration
	int i = 0;
	int iMerk = 0;
	int iEnd = 0; // überflüssig	
	float fMeasure[3][6]; //Initialisierung von Array
	
	//Schleife zur Eingabe der Messwerte
	do {
		//Kontrolle, ob die Obergrenze des Arrays erreicht ist
		if ( iMerk == 6 ) {
			printf("Der maximale Speicherplatz fuer Messergebnisse ist erreicht.");
			break;
		}   
		
		//Benutzereingabe der Messwerte
		printf("Bitte die %ite Drehzahl in U/min eingeben:\n", iMerk+1);
		scanf("%f", &fMeasure[0][iMerk]);
 
		printf("Bitte das %ite Drehmoment in Nm eingeben:\n", iMerk+1);
		scanf("%f", &fMeasure[1][iMerk]);
 
		printf("Bitte die %ite Leistung in kW eingeben:\n", iMerk+1);
		scanf("%f", &fMeasure[2][iMerk]);
 
		iMerk += 1;
		
		//Nachfragen, ob weitere Drehzahl eingelesen werden soll
		printf("Ist ein weiterer Messwert notwendig? ja (1) nein (0)\n");
		scanf("%i", &i);
	} while ( i );
	
	// iEnd ist ueberfluessig. Workaround um iEnd zumindest compiler-clean zu verwenden.
	iEnd += iMerk;
	
	return 0;
}
/*
 * Jede Messreihe (bestehend aus Drehzahl, Drehmoment, Leistung) ist eine Spalte 
 * des 3x6-Arrays, d.h. jede Messreihe ist ein 3-dim. Vektor in einer 3x6-Matrix.
 *
 *                     j-te Spalte
 *                    __          __     __ __
 *                   |              |   |     |
 *                   | Drehzahl j   |   | 0 j |
 *                   |              |   |     |
 *  j-te Messreihe = | Drehmoment j | = | 1 j |
 *                   |              |   |     |
 *                   | Leistung j   |   | 2 j |
 *                   |__          __|   |__ __|
 *
 * j = Index der Spalten, 0 <= j <= 5
 *
 *  __                                                                                     __
 * |                                                                                         |
 * | Drehzahl-0     Drehzahl-1     Drehzahl-2     Drehzahl-3     Drehzahl-4     Drehzahl-5   |
 * |                                                                                         |
 * | Drehmoment-0   Drehmoment-1   Drehmoment-2   Drehmoment-3   Drehmoment-4   Drehmoment-5 |
 * |                                                                                         |
 * | Leistung-0     Leistung-1     Leistung-2     Leistung-3     Leistung-4     Leistung-5   |                                                                                    |
 * |__                                                                                     __|
 *
 */