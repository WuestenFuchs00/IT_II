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
#include <stdio.h>
#include <math.h>

#define MAXFLOAT ((float)3.402823466e38)

//Funktion f(x)=3x*sin(x*x)
float f(float x) {
	return 3*x*sin(x*x);
}
 
//Funktion zum Findes des Maximums
float Maximum(float anfang, float ende, float schritt) {
	float xMax = 0; // Stelle des Maximums	
	float yMax = -MAXFLOAT; // Kleinstmoegliche float Zahl
	
	for ( float x = anfang; x <= ende; x += schritt ) {
		if ( f(x) > yMax ) {
			yMax = f(x);
			xMax = x;
		}
	}
	
	return xMax;
}
 
//Integrator
float Integrator(float anfang, float ende, float schritt) {
	float summe = 0;
	for ( float x = anfang; x < ende; x += schritt ) {
		summe += f(x)*schritt;
	}
	
	return summe;
}


// Hauptprogramm
int main () {	 
	//Variablendeklaration
	unsigned short int i;
	float anfang, ende, schritt;
	
	printf("Anfangswert:");
	scanf("%f", &anfang);
	
	printf("Endwert:");
	scanf("%f", &ende);
	
	printf("Schrittweite:");
	scanf("%f", &schritt);
	
	printf("Moechten Sie die Stelle des Maximums(1) oder das Integral(2) der Funktion berechnen?");
	scanf("%hu", &i);
	
	if ( i == 1 )
		printf("Das Maximum liegt an der Stelle %.2f", Maximum(anfang, ende, schritt));
	else if ( i == 2 )
		printf("Das Integral hat den Wert %.2f", Integrator(anfang, ende, schritt));
	
	return 0;
 }