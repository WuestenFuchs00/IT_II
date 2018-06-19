/**
 * Heimarbeit 9
 *
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm, das aus der externen Datei "Messdaten.txt" eine Messwertreihe
 * einliest, nach dem größten und kleinsten Wert sucht und diese anschließend in einer neuen Datei speichert.
 * Zusätzlich sollen die gespeicherten Werte ausgegeben werden (siehe Beispiel).
 * Die externe Datei "Messdaten.txt" enthält in jeder Zeile jeweils den Zeitpunkt der Messung in Sekunden, 
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
#include<stdio.h>
#define MAX 50
     
int main()
{
       
    int i = 0;
    int j = 0;
    float fMessreihe[MAX];
    float fmin = 0;
    float fmax = 0;
    int iZeit[MAX];
    int izeitmax = 0;
    int izeitmin = 0;

    //File oeffnen im Lesemodus
     
   
    /*Einlesen der Messwerte*/
    //solange nicht das Ende des Files erreicht ist
    while( == 0)
    {
   
        //Zeit einlesen
       
   
        //Messwert einlesen
        
          
        ++i;
    }
     
    //Maximal und Minimalwerte auf den ersten Messwert setzen
 
     
    //Suchen nach groesstem und kleinstem Wert  
    for()
    {
           
    }
      
    //Schliessen der Lese-Datei
    
      
    //File erstellen im Schreibmodus
     
        
    //Schreiben in Datei
    (, "Kleinster Messwert:  zur Zeit  Sekunden", , );
    (, "\nGroesster Messwert:  zur Zeit  Sekunden", , );
      
    //Schliessen der Schreib-Datei
     
      
      
    /*TEST, OB SCHREIBEN GEKLAPPT HAT*/
     
      
    char string[100];
    while( == 0)
    {         
        if(fgets( != 0)
        {
            printf("", );
        }        
    }
      
    //Schliessen des Tests
     
        
    return 0;
}