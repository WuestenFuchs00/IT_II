/**
 * Heimarbeit 05
 *
 * Frage 2,3
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
 *
 * Aufgabe (Frage 3):
 *
 * Berechnen Sie nun jeweils das arithmetische Mittel der (höchstens sechs) Messreihen und geben 
 * Sie die Ergebnisse in der geforderten Form aus.
 * 
 * Folgende Variablen und Arrays wurden zusätzlich zu denen in Teilaufgabe 2 bereits initialisiert.
 *   int j = 0;
 *   float fMeasure[3][6];
 *   float fAverage[3] = {0};
 *
 * Die Werte für fMeasure sind bereits erfolgreich eingelesen worden.
 *
 * Zum Beispiel:
 *
 * +----------+------------------------------------------------------------+
 * | Eingabe  | Result                                                     |
 * +----------+------------------------------------------------------------+
 * | 1587.12  | Bitte die 1te Drehzahl in U/min eingeben:                  |
 * | 80.87    | Bitte das 1te Drehmoment in Nm eingeben:                   |
 * | 20.123   | Bitte die 1te Leistung in kW eingeben:                     |
 * | 1        | Ist ein weiterer Messwert notwendig? ja (1) nein (0)       |
 * | 6000.789 | Bitte die 2te Drehzahl in U/min eingeben:                  |
 * | 190.488  | Bitte das 2te Drehmoment in Nm eingeben:                   |
 * | 320.222  | Bitte die 2te Leistung in kW eingeben:                     |
 * | 0        | Ist ein weiterer Messwert notwendig? ja (1) nein (0)       |
 * |          |                                                            |
 * |          | Die durchschnittliche Drehzahl betraegt: 3793.95 U/min     |
 * |          | Das durchschnittliche Drehmoment betraegt: 135.68 Nm       |
 * |          | Die durchschnittliche Leistung betraegt: 170.17 kW         |
 * +----------+------------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -lm -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
//Variablendeklaration

//Schleife zur Eingabe der Messwerte
 
    //Kontrolle, ob die Obergrenze des Arrays erreicht ist
 
        printf("Der maximale Speicherplatz fuer Messergebnisse ist erreicht.");
 
     
    //Benutzereingabe der Messwerte
    printf("Bitte die te Drehzahl in U/min eingeben:\n", );
    scanf();
 
    printf("Bitte das te Drehmoment in Nm eingeben:\n", );
    scanf();
 
    printf("Bitte die te Leistung in kW eingeben:\n", );
    scanf();
 
    //Nachfragen, ob weitere Drehzahl eingelesen werden soll
    printf("Ist ein weiterer Messwert notwendig? ja (1) nein (0)\n");
    scanf();
    
//Schleifen zum Berechnen der Mittelwerte

//Ausgabe
    printf("\nDie durchschnittliche Drehzahl betraegt:  U/min", );
    printf("\nDas durchschnittliche Drehmoment betraegt:  Nm", );
    printf("\nDie durchschnittliche Leistung betraegt:  kW", );
