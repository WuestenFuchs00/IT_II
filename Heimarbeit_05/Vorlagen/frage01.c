/**
 * Heimarbeit 05
 *
 * Frage 1
 *
 * Schreiben Sie ein vollst‰ndiges C-Programm, bei dem der erste Benutzer zuerst eine ganzzahlige 
 * Zahl zwischen 0 und 100 eingibt, welche der zweite anschlieﬂend erraten soll.
 * 
 * Hinweise:
 *  o Der zweite Spieler hat 6 Versuche
 *  o Zur Hilfe ist folgendes Nassi-Shneidermann-Diagramm gegeben
 *
 *  << Zahlenraten.JPG >>
 *
 * Zum Beispiel:
 *
 * +---------+------------------------------------------------------------+
 * | Eingabe | Result                                                     |
 * +---------+------------------------------------------------------------+
 * | 75      | Bitte geben Sie eine ganze Zahl zwischen 0 und 100 ein:    |
 * | 20      |                                                            |
 * | 60      | Ihr Tipp:                                                  |
 * | 80      | Zu klein! Verbleibende Versuche: 5                         |
 * | 75      | Ihr Tipp:                                                  |
 * |         | Zu klein! Verbleibende Versuche: 4                         |
 * |         | Ihr Tipp:                                                  |
 * |         | Zu hoch! Verbleibende Versuche: 3                          |
 * |         | Ihr Tipp:                                                  |
 * |         | Ihr Tipp war korrekt!                                      |
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
//Variablendeklaration
 
 
//Einlesen der Zahl die vom zweiten Benutzer erraten werden soll
 
    printf("Bitte geben Sie eine ganze Zahl zwischen 0 und 100 ein:\n");
    scanf();
 
 
//Schleife zum Erraten der Zahl
 
    printf("\nIhr Tipp:");
    scanf();
    //Ausgabe bei falschen Tipps
   
        printf("\nZu klein! Verbleibende Versuche: ", );
 
            printf("\nZu hoch! Verbleibende Versuche: ", );
 
 
//Ausgabe Spielergebnis
 
    printf("\nIhr Tipp war korrekt!");
 
    printf("\nZahl nicht erraten!");
