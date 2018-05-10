/**
 * Heimarbeit 02
 * Frage 1:
 * 
 * Erstellen Sie ein vollständiges C-Programm, welches zuerst drei Zahlen einliest und anschließend 
 * die eingegebenen Zahlen bzgl. der unten angegebenen Eigenschaften vergleicht.
 * Das Programm soll eine 1 ausgeben, falls die Bedingung erfüllt ist und eine 0, wenn nicht.
 * 
 * Die zu prüfende Eigenschaften sind:
 *   o Ist die erste Zahl größer als die zweite Zahl?
 *   o Ist die erste Zahl die kleinste der drei Zahlen?
 *   o Ist die dritte Zahl die größte der eingegebenen Zahlen?
 *   o Ist die dritte Zahl ungleich der ersten und ungleich der zweiten Zahl?
 *   o Ist die dritte Zahl gleich der ersten oder gleich der zweiten?
 *
 * Überprüfen Sie die Eigenschaften mit Hilfe von Bool'scher Algebra!
 *
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Bitte geben Sie die 1. Zahl ein:
 *   Bitte geben Sie die 2. Zahl ein:
 *   Bitte geben Sie die 3. Zahl ein:
 *   Die 1. Zahl ist groesser als die 2. Zahl:
 *   Die 1. Zahl ist die kleinste der drei Zahlen:
 *   Die 3. Zahl ist die groesste eingegebene Zahl:
 *   Die 3. Zahl ist ungleich der 1. und ungleich der 2. eingegebenen Zahl:
 *   Die 3. Zahl ist gleich der 1. oder gleich der 2. eingegebenen Zahl: 
 *
 * Compile: 
 *    gcc -Wall -std=c90 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
#include <stdio.h>

/* Aufruf der Hauptfunktion */
int main () {
	
	/* Variablendeklaration */
	int iZahl1, iZahl2, iZahl3;
	
	printf("Bitte geben Sie die 1. Zahl ein: ");
	scanf("%d", &iZahl1);
	
	printf("Bitte geben Sie die 2. Zahl ein: ");
	scanf("%d", &iZahl2);
	
	printf("Bitte geben Sie die 3. Zahl ein: ");
	scanf("%d", &iZahl3);
	
	printf("Die 1. Zahl ist groesser als die 2. Zahl: %d\n", iZahl1 > iZahl2);
	printf("Die 1. Zahl ist die kleinste der drei Zahlen: %d\n", iZahl1 < iZahl2 && iZahl1 < iZahl3);
	printf("Die 3. Zahl ist groesste eingegebene Zahl: %d\n", iZahl3 > iZahl2 && iZahl3 > iZahl1);
	printf("Die 3. Zahl ist ungleich der 1. und ungleich der 2. eingegebenen Zahl: %d\n", iZahl3 != iZahl1 && iZahl3 != iZahl2);
	printf("Die 3. Zahl ist gleich der 1. oder gleich der 2. eingegebenen Zahl: %d\n", iZahl3 == iZahl1 || iZahl3 == iZahl2);
	
	return 0;
}