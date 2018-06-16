/**
 * Uebung10_Bsp1.c
 *
 * Schreibt den Text "Dies ist der Beispieltext" in eine externe Textdatei "textdatei.txt".
 */
#include <stdio.h>

int main (void) {
	FILE* fDatei;
	int iRet = 0;
	
	fDatei = fopen("textdatei.txt", "wb");
	
	iRet = fputs("Dies ist der Beispieltext", fDatei);
	printf("fputs : %i\n", iRet);
	
	iRet = fclose(fDatei);
	printf("fclose : %i\n", iRet);
	
	return 0;
}
