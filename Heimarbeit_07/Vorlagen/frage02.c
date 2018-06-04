/**
 * Heimarbeit 07
 *
 * Frage 2
 *
 * Sie sind als Sub-Entwickler für die Implementierung dreier Unterfunktionen einer großen 
 * Softwareprogrammierung zuständig.
 *
 * Ihre Aufgaben sind
 *
 *  1. mit einer Call-by-Value-Funktion folgende Funktionsvorschrift zu realisieren: f(x)=3*x*sin(x*x)
 *  2. mit einer Call-by-Value-Funktion die Stelle des Maximums zwischen zwei Werten anhand diskreter 
 *     Stellen näherungsweise zu berechnen
 *  3. mit einer Call-by-Value-Funktion das Integral zwischen zwei Werten anhand diskreter Stellen 
 *     naeherungsweise zu berechnen
 *
 * Verwenden Sie die Datentypen entsprechend den folgenden Black-Box-Darstellungen der Funktionen:
 *
 *   << Funktionen.JPG >>
 *
 * Hinweise:
 *
 *  o Die main-Funktion haben Ihre Kollegen bereits ausprogrammiert, sodass Sie sich nicht um das 
 *    Einlesen und Ausgeben der Werte kümmern müssen
 *  o Binden Sie benötigte Bibliotheken ein
 *  o Damit Ihre Funktionen in der Hauptfunktion aufgerufen werden können, dürfen Sie die vorgegebenen 
 *    Funktionsname nicht ändern.
 *  o Programmieren Sie zuerst die Funktion f(x) und rufen Sie diese dann in den Funktionen Maximum bzw. 
 *    Integrator auf
 *  o Maximum vergleicht iterativ die Funktionswerte von f an diskreten Stellen mit Abstand "Schrittweite" 
 *    zwischen "Anfangswert" und "Endwert" und gibt die Stelle mit dem größten Funktionswert zurück
 *  o Integrator nähert numerisch das Integral von f(x) zwischen "Anfangswert" und "Endwert" mit der 
 *    eingegebenen Schrittweite an und gibt den Wert des Integrals zurück (Rufen Sie sich hierzu die 
 *    Aufgabe 1 aus der Zentralübung 4 ins Gedächtnis)
 *
 * Zum Beispiel:
 *
 * +---------+--------------------------------------------------------------------------------------+
 * | Eingabe | Result                                                                               |
 * +---------+--------------------------------------------------------------------------------------+
 * | -2.5    | Anfangswert:                                                                         |
 * | 2.7     | Endwert:                                                                             |
 * | 0.015   | Schrittweite:                                                                        |
 * | 1       | Moechten Sie die Stelle des Maximums(1) oder das Integral(2) der Funktion berechnen? |
 * |         | Das Maximum liegt an der Stelle 2.69                                                 |
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
 

//Funktion f(x)=3x*sin(x*x)
 f()
 
//Funktion zum Findes des Maximums
 Maximum()
 
//Integrator
 Integrator()

