/**
 * Uebung10_Bsp3.c - Blockweise Ein/Ausgabe
 */
#include <stdio.h>
typedef struct {
	int iX;
	int iY;
} KOORDINATEN;

int main() {
	KOORDINATEN APunkte[5] = {{0,0},{1,1},{-1,-1},{-1,1},{1,-1}};
	KOORDINATEN AKontrolle[5];
	int i = 0;
	
	FILE *pDatei = fopen("Koordinaten.bin", "wb");
	fwrite(APunkte, sizeof(KOORDINATEN), 5, pDatei); // Schreibt ganzen Block/Array in pDatei
	fclose(pDatei);
	
	pDatei = fopen("Koordinaten.bin", "rb");
	fread(AKontrolle, sizeof(KOORDINATEN), 5, pDatei); // Liest Block von pDatei in AKontrolle
	fclose(pDatei);
	
	for ( i = 0; i < 5; i++ ) {
		fprintf(stdout, " x: %i \t y: %i \n", AKontrolle[i].iX, AKontrolle[i].iY);
		//printf(" x: %i \t y: %i \n", (AKontrolle+i)->iX, (AKontrolle+i)->iY);
	}
	return 0;
}