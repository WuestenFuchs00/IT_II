/**
 * Zentralübung 07
 *
 * Frage 2
 *
 * Implementieren Sie ein vollständiges C-Programm, welches das Gewicht von 5 Arten von Kaffeebohnen 
 * nacheinander in zwei Arrays einliest, jeweils nach der Größe ordnet und dann sortiert ausgibt.
 *
 * Hinweise:
 *   o Als Codeschnipsel ist Ihnen die Lösung aus der Sortieraufgabe der letzten ZÜ gegeben
 *   o Passen Sie nun den Code so an, dass der Nutzer die 5 Werte erst in Array 1 und anschließend 
 *     in Array2 eingeben muss
 *   o Realisieren Sie dies mit Hilfe eines Zeigers, der auf das entsprechende Array umgebogen wird
 *   o Die Sortierfunktion muss nun auch an die Verwendung von Zeigern angepasst werden
 *
 * Zum Beispiel:
 *
 * +---------+------------------------------------------------------+
 * | Eingabe | Result                                               |
 * +---------+------------------------------------------------------+
 * | 1.5     |                                                      |
 * | 8.65    | Bitte geben Sie das Gewicht der 1. Bohnensorte ein:  
 * | 4.456   | Bitte geben Sie das Gewicht der 2. Bohnensorte ein:  |
 * | 2.55    | Bitte geben Sie das Gewicht der 3. Bohnensorte ein:  |
 * | 9.56    | Bitte geben Sie das Gewicht der 4. Bohnensorte ein:  |
 * | 2.4     | Bitte geben Sie das Gewicht der 5. Bohnensorte ein:  |
 * | 6.3     | Sortierte Auflistung:                                |
 * | 8.25    | 1.50                                                 |
 * | 1.5     | 2.55                                                 |
 * | 6.4     | 4.46                                                 |
 * |         | 8.65                                                 |
 * |         | 9.56                                                 |
 * |         | Bitte geben Sie das Gewicht der 1. Bohnensorte ein:  |
 * |         | Bitte geben Sie das Gewicht der 2. Bohnensorte ein:  |
 * |         | Bitte geben Sie das Gewicht der 3. Bohnensorte ein:  |
 * |         | Bitte geben Sie das Gewicht der 4. Bohnensorte ein:  |
 * |         | Bitte geben Sie das Gewicht der 5. Bohnensorte ein:  |
 * |         | Sortierte Auflistung:                                |
 * |         | 1.50                                                 |
 * |         | 2.40                                                 |
 * |         | 6.30                                                 |
 * |         | 6.40                                                 |
 * |         | 8.25                                                 |
 * +---------+------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
#include <stdio.h>

void bohnenAutomat (float *fpA, int i, int j, int k, int iMin, float fTemp) {	
	for( j = 0; j <= 4; j++ )
    {
        printf("\nBitte geben Sie das Gewicht der %i. Bohnensorte ein:", j+1);
        scanf("%f", fpA+j);
    }
	
	//Sortieren
    for( i = 0; i <= 3; i++ )
    {
        iMin = i;
        for( k = i + 1; k <= 4; k++ )
        {
            if( *(fpA+k) < *(fpA+iMin) ) iMin=k;
        }
		//Tauschen
        fTemp = *(fpA+i);
        *(fpA+i) = *(fpA+iMin);
        *(fpA+iMin) = fTemp;
    }
   
    //Ausgeben
    printf("\nSortierte Auflistung:");
    for( j = 0; j <= 4; j++ ) printf("\n%.2f", *(fpA+j)); 
	
	return;
}


int main()
{
  //Variablendeklaration
    int i=0, k=0, j=0; //s=0, n=0;
    int iMin=0;
    float fArray1[5];
    float fArray2[5];
    float fTemp=0;
	
    //2 Mal Einlesen der fünf Sorten
	bohnenAutomat(&fArray1[0] /* Zeiger um biegen */, i, j, k, iMin, fTemp);
	bohnenAutomat(fArray2 /* Zeiger um biegen */, i, j, k, iMin, fTemp);
	
    return 0;
   
}
