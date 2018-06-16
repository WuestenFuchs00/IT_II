/**
 * Zentralübung 10
 *
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm welches Personendaten erfasst und in eine Textdatei schreibt.
 * Erfasst werden sollen der Nachname und das Geburtsjahr der Personen. Es soll zunächst eine Textdatei 
 * erstellt werden und der Nutzer gefragt werden, ob er Daten eingeben möchte. Nachdem Daten eingegeben 
 * wurden, werden alle Einträge der Textdatei ausgeben.
 *
 * Zum Beispiel:
 *
 * +---------------+-------------------------------------------------------------------+
 * | Eingabe       | Result                                                            |
 * +---------------+-------------------------------------------------------------------+
 * | 1             | Wollen Sie einen Eintrag in ihr Adressbuch machen?  Ja(1) Nein(0) |
 * | Amberg 1977   | Nachname Geburtsjahr?                                             |
 * | 1             |                                                                   |
 * | Schmidt 1965  | Wollen Sie einen Eintrag in ihr Adressbuch machen?  Ja(1) Nein(0) |
 * | 0             | Nachname Geburtsjahr?                                             |
 * |               |                                                                   |
 * |               | Wollen Sie einen Eintrag in ihr Adressbuch machen?  Ja(1) Nein(0) |
 * |               |                                                                   |
 * |               | 1. Eintrag:                                                       |
 * |               | Amberg, 1977                                                      |
 * |               |                                                                   |
 * |               | 2. Eintrag:                                                       |
 * |               | Schmidt, 1965                                                     |
 * +---------------+-------------------------------------------------------------------+
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
 * |          | Liefert 0 zurueck, solange Dateiende nicht erreicht ist. Sonst 0.       |
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
#include <stdio.h>
#define MAX 30
   
typedef struct
{ 
    char szNachname[MAX];
    int iGeburtsjahr;     
} PERSON;

   
int main()
{
      
    //Dateien öffnen/erstellen
    FILE* Datei;
    if((Datei = fopen("neutst.of", "a+")) == NULL)
    {
        printf("Datei konnte nicht erstellt werden");
        return 1;
    }
   
    PERSON Person[5];
    int i = 0;
    int j = 0;
    int iEintrag = 0;

    do
    {        
        printf("Wollen Sie einen Eintrag in ihr Adressbuch machen?  Ja(1) Nein(0)");
        scanf("%i", &iEintrag);
   
        if(iEintrag == 1)
        {
            printf("\nNachname Geburtsjahr?\n\n");
			//scanf("%s" "%i", Person[i].szNachname, &(Person[i].iGeburtsjahr));
            scanf("%s" "%i", (Person+i)->szNachname, &((Person+i)->iGeburtsjahr));
   
            //Schreiben in Datei
            fprintf(Datei, "\n\n%s %i", Person[i].szNachname, Person[i].iGeburtsjahr);
            ++i;
        }
   
    }while(iEintrag);
   
    //Datei schliessen
    fclose(Datei);
	
    //Datei öffnen im Lesemodus   
    if((Datei = fopen("neutst.of", "r")) == NULL)
    {
        printf("Datei konnte nicht erstellt werden");
        return 1;
    }
   
    //Auslesen aus Datei 
    i=0;
      
    while(feof(Datei) == 0)
    {
         
        if(fscanf(Datei, "%s" "%i", Person[i].szNachname, &Person[i].iGeburtsjahr) == 0)
        {
            printf("Fehler beim Einlesen der Datei!");
            return 1;
        }
   
    ++i;
    }
   
    for(j = 0; j < i; j++)
    {
        printf("\n\n%i. Eintrag:\n%s, %i", j+1, Person[j].szNachname, Person[j].iGeburtsjahr);
    }
   
    //Datei schliessen
    fclose(Datei);
      
    return 0;
}
