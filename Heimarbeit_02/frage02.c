/**
 * Heimarbeit 02
 * Fragen 2,3,4
 *
 * Ausgangssituation:
 *
 * Ein Mitarbeiter in einer Logistikfirma wünscht sich ein Programm, das ihm bei den Berechnungen 
 * seiner Autotransporte hilft. Er lässt die Autos mit einem Gewicht von derzeit je 2000 kg immer 
 * auf Autotransporter verladen (12 Autos pro Ladung). Jedes Auto bekommt eine Schutzhülle gegen
 * Transportschäden, die derzeit 500g wiegt. Die Autotransporter müssen aus Kostengründen immer
 * vollbeladen werden.
 *
 * Dieses Programm wird Schritt für Schritt erstellt. 
 *
 * Folgende Initialisierung der Variablen ist bereits durchgeführt:
 *
 * Initialisierung konstanter Variablen:
 *
 *  float fGewichtAuto = 2000;	//Gewicht pro Auto
 *  float fGewichtHuelle = 0.5;	//Gewicht pro Hülle 
 *  int iAutosproLadung = 12;	// Autos pro Ladung
 *
 * Initialisierung veränderlichen Variablen:
 * 
 *  float fGewichtLadung = 0;	//Gewicht pro Ladung
 *  int iAnzahlAutos = 51013;	//Anzahl Autos pro Jahr
 *  int iAnzahlVerladen = 0;	//Anzahl verladener Autos
 *  int iAnzahluebrig = 0;	//Anzahl nicht verladener Autos
 *  int iAnzahlLadungen = 0;	//Anzahl Ladungen
 *
 * Compile:
 *    gcc -Wall -std=c90 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 */
#include <stdio.h>

int main () {
	
	/* Initialisierung konstanter Variablen */
	float fGewichtAuto = 2000;	/* Gewicht pro Auto */
	float fGewichtHuelle = 0.5;	/* Gewicht pro Hülle */
 	int iAutosproLadung = 12;	/* Autos pro Ladung */
	
	/* Initialisierung veränderlicher Variablen */
	float fGewichtLadung = 0;	/* Gewicht pro Ladung */
 	int iAnzahlAutos = 51013;	/* Anzahl Autos pro Jahr */
	int iAnzahlVerladen = 0;	/* Anzahl verladener Autos */
	int iAnzahluebrig = 0;	    /* Anzahl nicht verladener Autos */
 	int iAnzahlLadungen = 0;	/* Anzahl Ladungen */
	
	/* 
	 * Frage 2
	 *
	 * Aufgabe: Berechnen Sie das Gewicht pro Ladung in kg
	 */
	fGewichtLadung = iAutosproLadung * (fGewichtAuto + fGewichtHuelle);
	
	/* 
	 * Frage 3
	 *
	 * Aufgabe: Berechnen Sie
	 *   o wie viele Autotransporte im Jahr benötigt werden
	 *   o wie viele Autos tatsächlich im Jahr transportiert werden
	 *   o wie viele Autos am Ende des Jahres nicht transportiert werden, weil sie keine volle 
	 *     Ladung ergeben
	 */
	iAnzahlLadungen = iAnzahlAutos / iAutosproLadung;
	iAnzahlVerladen = iAnzahlLadungen * iAutosproLadung;
	iAnzahluebrig = iAnzahlAutos - iAnzahlVerladen;
	
	/*
	 * Frage 4
	 *
	 * Erzeugen Sie folgende beispielhafte Ausgabe:
	 * Zum Beispiel:
	 * +---------+--------------------------------------------------+
	 * | Eingabe | Result                                           |
	 * +---------+--------------------------------------------------+
	 * | 51013   | Es werden 4251 Autotransporte im Jahr benoetigt. |
	 * |         | Es werden 51012 Autos transportiert.             |
	 * |         | Es bleiben am Ende des Jahres 1 Auto(s) uebrig.  |
	 * |         | Eine Ladung wiegt 24006.00 kg.                   |
	 * +---------+--------------------------------------------------+
	 *
	 */
	printf("Es werden %d Autotransporte im Jahr benoetigt.\n", iAnzahlLadungen);
	printf("Es werden %d Autos transportiert.\n", iAnzahlVerladen);
	printf("Es bleiben am Ende des Jahres %d Auto(s) uebrig.\n", iAnzahluebrig);
	printf("Eine Ladung wiegt %.2f kg.\n", fGewichtLadung);
	
	return 0;
}