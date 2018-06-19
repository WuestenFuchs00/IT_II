/**
 * Heimarbeit 9
 *
 * Frage 2
 *
 * Der Hersteller eines Sportwagens möchte die Messergebnisse seiner Testfahrt grafisch dargestellt haben. 
 * Bei der Testfahrt wird alle 5 Sekunden, die aktuelle Geschwindigkeit in die Textdatei "vmess.txt" 
 * geschrieben, diese sieht in etwa so aus:
 *
 * << vmess.JPG >>
 *
 * Lesen Sie aus dieser Datei die Geschwindigkeitswerte aus und speichern Sie diese in einem Integer-Array. 
 * Übergeben Sie dieses Array anschließend der Funktion "plotter", welche eine grafische Ausgabe der 
 * Messwerte erzeugt. Die Funktion plotter ist bereits in den Codeschnipseln implementiert.
 *
 * Hinweis:
 *   o Die auszulesende Zahl hat immer drei Ziffern
 *   o Zahlen sind in der ASCII Tabelle um den Wert 48 nach rechts verschoben. Beachten Sie dies beim 
 *     Auslesen der Zahl
 *   o Tipp: Da die Zahl aus drei Ziffern besteht, muss sie durch Multiplikation/Addition zusammengesetzt 
 *     werden
 *   o Binden Sie die string.h ein
 *   o Strings sollen maximal 200 Zeichen lang sein!
 *   o Die Datei aus der auszulesen ist, ist bereits hinterlegt. Sie heisst "vmess.txt"
 *   o Die Funktion Plotter ist bereits in den Codeschnipseln implementiert. Machen Sie sich damit 
 *     vertraut, was Sie dieser übergeben müssen.
 *
 * I/O-Operationen in <stdio.h>
 * 
 * +----------+-------------------------------------------------------------------------+
 * | Funktion | Snytax                                                                  |
 * +----------+-------------------------------------------------------------------------+
 * | fopen    | FILE* fopen(const char * szFilename, const char * szMode)               |
 * |          |                                                                         |
 * |          | Oeffne bzw. erstelle eine Datei.                                        |
 * |          |                                                                         |
 * |          | Parameter:                                                              |
 * |          |   szFiename : Name der zu oeffnenden Datei                              |
 * |          |   szMode : Zugriffsart (r,w,a,r+,w+,a+,t,b)                             |
 * |          |      t : textmode, translate mode ("rt", "at+")                         |
 * |          |      b : binary mode ("rb", "ab+")                                      |
 * |          |                                                                         |
 * |          | Rueckgabewert:                                                          |
 * |          |   ZEIGER auf Datei. Sonst NULL, wenn Datei nicht erstellt werden kann   |
 * |          |   oder Datei nicht existiert.
 * +----------+-------------------------------------------------------------------------+
 * | fputs    | int fputs(const char * str, FILE * stream)                              |
 * |          |                                                                         |
 * |          | Zeilenweise Ausgabe. Schreibt string (= Array von char) auf den Stream. |
 * |          | Schreibt eine Zeile auf den Stream.                                     |
 * |          |                                                                         |
 * |          | Bei Erfolg gibt fputs eine NICHT-NEGATIVE Ganzzahl (0,1,..) zurueck.    |
 * +----------+-------------------------------------------------------------------------+
 * | fputc    | int fputc(int char, FILE * stream)                                      |
 * |          |                                                                         |
 * |          | Zeichenweise Ausgabe auf den Stream. Schreibt ein char auf den Stream.  |
 * +----------+-------------------------------------------------------------------------+
 * | fgets    | char *fgets(char * str, int n, FILE * stream)                           |
 * |          |                                                                         |
 * |          | Zeilenweise Lesen. Liest vom Stream maximale n Zeichenanzahl.           |
 * |          | Liest eine Zeile vom Stream nur bis zum naechsten Newline (\n).         |
 * +----------+-------------------------------------------------------------------------+
 * | fgetc    | int fgetc(FILE * stream)                                                |
 * |          |                                                                         |
 * |          | Zeichenweise Eingabe. Liest ein (weiteres) char vom Stream.             |
 * +----------+-------------------------------------------------------------------------+
 * | fprintf  | int fprintf(FILE * stream, const char * format, ...)                    |
 * |          |                                                                         |
 * |          | fprintf(stdout, "Hello World!\n");                                      |
 * |          |                                                                         |
 * |          | int tag = 10, monat = 12, jahr = 2008;                                  |
 * |          | fprintf(stdout, "Heute ist der %d/%d/%d.", tag, monat, jahr);           |
 * |          |                                                                         |
 * |          | Formatierte Ausgabe. Analog zu printf, nur dass der Stream gewählt      |
 * |          | werden kann. Der Stream ist: stdin, stdout, stderr.                     |
 * +----------+-------------------------------------------------------------------------+
 * | fscanf   | int fprintf(FILE * stream, const char * format, ...)                    |
 * |          |                                                                         |
 * |          | int tag, monat, jahr;                                                   |
 * |          | printf("Welches Datum ist heute? ");                                    |
 * |          | fscanf(stdin, "%d/%d/%d", &tag, &monat, &jahr);                         |
 * |          |                                                                         |
 * |          | Formatierte Eingabe. Analog zu scanf, nur dass der Stream gewählt       |
 * |          | werden kann. Der Stream ist: stdin, stdout, stderr.                     |
 * +----------+-------------------------------------------------------------------------+
 * | scanf    | int scanf(const char * format, ...)                                     |
 * |          |                                                                         |
 * |          | Formatierete Eingabe. Liest formatierte Inputs aus dem stdin-Stream.    |
 * |          | Ist äquivalent zu:                                                      |
 * |          |     fscanf(stdin, ...) == scanf(...)                                    |
 * +----------+-------------------------------------------------------------------------+
 * | fwrite   | size_t fwrite(const void *puffer, size_t size, size_t n, FILE *stream)  |
 * |          |                                                                         |
 * |          | Blockweise Ausgabe. Schreibt n Bloecke jeweils der Groesse size von der |
 * |          | Adresse <puffer> auf den Ausgabe-Stream <stream>.                       |
 * |          | Kurz: Schreibt n*sizeof(size_t) auf den Ausgabe-Stream.                 |
 * |          |                                                                         |
 * |          | size_t steht fuer NICHT-NEGATIVE Werte, z.B. usigned int                |
 * |          |                                                                         |
 * |          | Rueckgabewert (Typ size_t):                                             |
 * |          |   Wird erfolgreich geschrieben, ist Rueckgabewert genau die Anzahl n    |
 * |          |   der Bloecke. Sonst gibt es Fehler, g.d.w. Rueckgabewert ungleich n.   |
 * +----------+-------------------------------------------------------------------------+
 * | fread    | size_t fread(void *puffer, size_t size, size_t n, FILE *stream)         |
 * |          |                                                                         |
 * |          | Blockweise Eingabe. Liest n Bloecke jeweils der Groesse size aus dem    | 
 * |          | Eingabe-Stream in die Adresse von puffer.                               |
 * |          | Kurz: Liest n*sizeof(size_t) aus dem Stream in puffer.                  |
 * |          |                                                                         |
 * |          | Rueckgabewert (size_t):                                                 |
 * |          |   Wird erfolgreich eingelesen, ist Rueckgabewert gleich der Anzahl n    |
 * |          |   der Bloecke. Wird EOF erreicht oder gibt es Fehler, dann ist          |
 * |          |   Rueckgabewert ungleich n.                                             |
 * +----------+-------------------------------------------------------------------------+
 * | fclose   | int fclose(FILE * stream)                                               |
 * |          |                                                                         |
 * |          | Schliesst den Stream bzw. eine Datei.                                   |
 * |          |                                                                         |
 * |          | Rueckgabewert (int):                                                    |
 * |          |   0 wird zurückgegeben, wenn der Stream (Datei) erfolgreich geschlossen |
 * |          |   wird. Sonst wird EOF zurueckgegeben.                                  |
 * +----------+-------------------------------------------------------------------------+
 * | feof     | int feof(FILE * stream)                                                 |
 * |          |                                                                         |
 * |          | EOF (End of File) Flag = Kennzeichnet das Ende einer Datei.             |
 * |          | feof testet auf EOF, d.h. ob Ende einer Datei (Stream) erreicht ist.    |
 * |          |                                                                         |
 * |          | Rueckgabewert (int):                                                    |
 * |          | Liefert 0 zurueck, solange Dateiende nicht erreicht ist. Sonst nicht 0  |
 * +----------+-------------------------------------------------------------------------+
 * 
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
//Header
#include<stdio.h>
#include<string.h>
   
//Funktion Plotter
 
void plotter(int* iArray)
{
    int i = 0;
    int j = 0;
    int ivalue = 0;

    printf("^");
     
    for(j = 18; j >= 0; j--)
    {
        printf("\n|");
   
        for(i = 0; i <= 12; i++)
        {
            ivalue = (iArray[i])*0.06;
              
            if(ivalue == j)
            {
                printf("*");
            }
            else
            {
                if(j==0 && i!=12) printf("-");
                if(j==0 && i==12) printf(">");
                if(j!=0) printf(" ");
            }
        }
     }   
}
    
//Main
int main()
{
    //Variablendeklaration
	char sZeile[200];
	int iGeschwindigkeit[13];
	int i = 0;
	
	char *pc;
	FILE *Datei;
   
    //Öffnen der Datei
    if ( (Datei = fopen("vmess.txt", "r")) == NULL ) {
		printf("Diese Datei kann nicht geoeffnet werden.");
		return 1;
	}
	
	/* Lesen solange EOF noch nicht erreicht ist */
	while ( feof(Datei) == 0 ) {
		//Einlesen des Strings
		if ( fgets(sZeile, 200, Datei) != 0 ) {
			//Auslesen der benötigten Werte aus dem String
			if ( (pc = strchr(sZeile, 45)) != NULL ) { // Minuszeichen (-) hat ASCII 45
				pc += 2; // Zeiger auf erste Ziffer der Geschwindigkeit
				iGeschwindigkeit[i] = (*pc-48)*100 + (*(pc+1)-48)*10 + (*(pc+2)-48);
				i += 1;
			}
		}
	}
	   
    //Plotten der Funktion
	plotter(iGeschwindigkeit); 
        
    //Schließen der Datei
	fclose(Datei); 
      
    return 0;   
}