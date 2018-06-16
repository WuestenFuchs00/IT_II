/**
 * Uebung10_Bsp2.c
 */
#include <stdio.h>
#define MAX 81

int main() {
	char szString[MAX] = "";
	FILE *pDatei = fopen("Textdatei.txt", "wt");
	
	fputs("Dies ist der Beispieltext \n und das die zweite Zeile", pDatei);
	fclose(pDatei);
	
	pDatei = fopen("Textdatei.txt", "rt");
	fgets(szString, MAX, pDatei); // Eine Zeile lesen
	printf("Aus Datei: %s \n", szString);
	fgets(szString, MAX, pDatei); // Naechste Zeile lesen
	printf("Aus Datei: %s \n", szString);
	
	fclose(pDatei);	
	return 0;
}