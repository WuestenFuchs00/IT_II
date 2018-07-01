/**
 * Funktionen aus <string.h>
 * +----------------------------------------+------------------------------------------------------+
 * | Funktion                               | Bedeutung                                            |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strchr(const char* s, int ch);   | Sucht im String s nach dem Zeichen ch (ASCII code)   |
 * |                                        | und gibt die Position des ersten Auftretens zurück,  |
 * |                                        | sonst NULL.                                          |
 * +----------------------------------------+------------------------------------------------------+
 * | uint strlen(const char* s1);           | Gibt die Länge von s1 ohne String-Ende '\0' Zeichen  |
 * |                                        | zurück.                                              |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strncat(char* s1,                | Hängt s2 an das Ende von s1 an. Hängt maximal n      |
 * |               const char* s2, uint n); | Zeichen an.                                          |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strncpy(char* s1,                | Kopiert n Zeichen aus dem String s2 in den String s1 |
 * |               const char* s2, uint n); | s1 = Ziel, s2 = Quelle                               |
 * |                                        | Liefert Zeiger auf String s1 (Ziel) zurueck.         |
 * +----------------------------------------+------------------------------------------------------+
 * | char* strcpy(char* s1, const char* s2) | Kopiert String s2 (Quelle) nach String s1 (Ziel),    |
 * |                                        | inkl. das Endzeichen '\0'.
 * |                                        | Liefert Zeiger auf String s1 (Ziel) zurueck.         | 
 * +----------------------------------------+------------------------------------------------------+
 * | char* strstr(const char* s1,           | Sucht in s1 nach einem Teilstring s2. Liefert die    |
 * |              const char* s2);          | Position von s2 in s1 zurück.                        |
 * +----------------------------------------+------------------------------------------------------+
 *
 * I/O-Funktionen aus <stdio.h>
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
 * |          |   Zugriffsart:                                                          |
 * |          |     o w : Existierender Dateinhalt geht bei jedem Schreiben verloren.   |
 * |          |           Datei wird geaendert bzw. neu geschrieben. (write)            |
 * |          |     o a : Existierender Datei bleibt erhalten. Neuer Inhalt wird nur    |
 * |          |           am Dateiende geschrieben bzw. angehaengt. (append)            |
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
 * | fgets    | char *fgets(char * str, int N, FILE * stream)                           |
 * |          |                                                                         |
 * |          | Zeilenweise Lesen. Liest vom Stream <stream>maximale N Zeichenanzahl.   |
 * |          |                                                                         |
 * |          | Liest eine Zeile (N Zeichen) vom Stream <stream> nur bis zum naechsten  |
 * |          | Newline (\n) und speichert das Gelesene in <str>.                       |
 * |          | Rueckgabewert ist ein (char *)Pointer auf <str>.                        |
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
 * |          |                                                                         |
 * |          | fprintf(stdout, "...")  ist-gleich  printf("...")                       |
 * +----------+-------------------------------------------------------------------------+
 * | fscanf   | int fprintf(FILE * stream, const char * format, ...)                    |
 * |          |                                                                         |
 * |          | int tag, monat, jahr;                                                   |
 * |          | printf("Welches Datum ist heute? ");                                    |
 * |          | fscanf(stdin, "%d/%d/%d", &tag, &monat, &jahr);                         |
 * |          |                                                                         |
 * |          | Formatierte Eingabe. Analog zu scanf, nur dass der Stream gewählt       |
 * |          | werden kann. Der Stream ist: stdin, stdout, stderr.                     |
 * |          |                                                                         |
 * |          | fscanf(stdin, "%d/%d/%d", &tag, &monat, &jahr)  ist-gleich              |
 * |          |  scanf("%d/%d/%d", &tag, &monat, &jahr)                                 |
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
