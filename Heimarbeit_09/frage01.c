/**
 * Heimarbeit 9
 *
 * Frage 1
 *
 * Schreiben Sie ein vollst�ndiges C-Programm, das aus der externen Datei "Messdaten.txt" eine Messwertreihe
 * einliest, nach dem gr��ten und kleinsten Wert sucht und diese anschlie�end in einer neuen Datei speichert.
 * Zus�tzlich sollen die gespeicherten Werte ausgegeben werden (siehe Beispiel).
 * Die externe Datei "Messdaten.txt" enth�lt in jeder Zeile jeweils den Zeitpunkt der Messung in Sekunden, 
 * sowie den Messwert in folgender Formatierung:
 *
 * << Messdaten.JPG >>
 *
 * Hinweis:
 *   o Die Datei aus der auszulesen ist, ist bereits hinterlegt. Sie heisst "Messdaten.txt".
 *
 * Zum Beispiel:
 *
 * +--------------------------------------------------+
 * | Result                                           |
 * +--------------------------------------------------+
 * | Kleinster Messwert: 0.2456 zur Zeit 1 Sekunden   |
 * | Groesster Messwert: 51.5248 zur Zeit 20 Sekunden | 
 * +--------------------------------------------------+
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
 * |          | Formatierte Ausgabe. Analog zu printf, nur dass der Stream gew�hlt      |
 * |          | werden kann. Der Stream ist: stdin, stdout, stderr.                     |
 * +----------+-------------------------------------------------------------------------+
 * | fscanf   | int fprintf(FILE * stream, const char * format, ...)                    |
 * |          |                                                                         |
 * |          | int tag, monat, jahr;                                                   |
 * |          | printf("Welches Datum ist heute? ");                                    |
 * |          | fscanf(stdin, "%d/%d/%d", &tag, &monat, &jahr);                         |
 * |          |                                                                         |
 * |          | Formatierte Eingabe. Analog zu scanf, nur dass der Stream gew�hlt       |
 * |          | werden kann. Der Stream ist: stdin, stdout, stderr.                     |
 * +----------+-------------------------------------------------------------------------+
 * | scanf    | int scanf(const char * format, ...)                                     |
 * |          |                                                                         |
 * |          | Formatierete Eingabe. Liest formatierte Inputs aus dem stdin-Stream.    |
 * |          | Ist �quivalent zu:                                                      |
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
 * |          |   0 wird zur�ckgegeben, wenn der Stream (Datei) erfolgreich geschlossen |
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
#include<stdio.h>
#define MAX 50
     
int main()
{
    int i = 0;
    int j = 0;
    int iMin, iMax;
    int iZeit[MAX];
    float fMessreihe[MAX];
    char szFilename[14] = "Messdaten.txt";
    char szFilename2[13] = "Ergebnis.txt";
    FILE * Datei;

    //File oeffnen im Lesemodus
    if ( (Datei = fopen(szFilename, "rt")) == NULL ) {
        printf("\nDatei kann nicht geoeffnet werden.");
        return 1;
    }
   
    /*Einlesen der Messwerte*/
    //solange nicht das Ende des Files erreicht ist
    while( feof(Datei) == 0 )
    {
        //Zeit einlesen
        fscanf(Datei, "%i", &iZeit[i]);
        
        //Messwert einlesen
        fscanf(Datei, "%f", &fMessreihe[i]);
          
        ++i;
    }
     
    //Maximal und Minimalwerte auf den ersten Messwert setzen
    iMin = 0;
    iMax = 0;
    
    //Suchen nach groesstem und kleinstem Wert  
    for( j = 1; j < i; j++ )
    {
        if ( fMessreihe[j] > fMessreihe[iMax] )  iMax = j;
        if ( fMessreihe[j] < fMessreihe[iMin] )  iMin = j;
    }
      
    //Schliessen der Lese-Datei
    if ( fclose(Datei) != 0 ) {
        printf("\nDatei kann nicht geschlossen werden.");
        return 1;
    }
      
    //File erstellen im Schreibmodus
    if ( (Datei = fopen(szFilename2, "wt")) == NULL ) {
        printf("\nDatei kann nicht erstellt werden.");
        return 1;
    }
        
    //Schreiben in Datei
    fprintf(Datei, "Kleinster Messwert: %.4f zur Zeit %i Sekunden", fMessreihe[iMin], iZeit[iMin]);
    fprintf(Datei, "\nGroesster Messwert: %.4f zur Zeit %i Sekunden", fMessreihe[iMax], iZeit[iMax]);
      
    //Schliessen der Schreib-Datei
    if ( fclose(Datei) != 0 ) {
        printf("\nDatei kann nicht geschlossen werden.");
        return 1;
    }
      
    /*TEST, OB SCHREIBEN GEKLAPPT HAT*/
    Datei = fopen(szFilename2, "rt");
    
    char string[100];
    while(feof(Datei) == 0)
    {         
        if(fgets(string, 100, Datei) != 0)
        {
            printf("%s", string);
        }        
    }
      
    //Schliessen des Tests
    fclose(Datei); 
        
    return 0;
}