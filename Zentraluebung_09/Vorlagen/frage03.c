/**
 * Zentralübung 09
 *
 * Frage 3
 *
 * Schreiben Sie ein vollständiges C-Programm, welches mit Hilfe zweier Pointer einzelne Einträge einer Matrix A 
 * ausgeben und mit Werten aus B überschreiben kann.
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 */
//Variablendeklaration
    char A[3][3] = {{'a', 'd', 'b'},
                    {'h', 'r', 'k'},
                    {'A', 'F', 'l'}};    
     
    char B[9] = {'e', 'G', 'J', 's', 'y', 'n', 'p', 'Q', 'W'};
 
   
    //Solange der Nutzer bearbeiten will
         
        //Eingabe der Stellen A
        printf("Um wie viele Stellen soll der A-Pointer weiterspringen?");
        scanf();
 
         
        //Ausgabe des Wertes
        printf("\nWert an ausgewaehlter Stelle: ", );
         
        //Wert ueberschreiben?
        printf("\nWollen Sie den Wert ueberschreiben? (1) ja (0) nein");
        scanf();
 
         
        //weiteres Mal bearbeiten?
        printf("\nMatrix nochmal bearbeiten? (1) ja (0) nein\n");
        scanf();
 
       
    //Ausgabe der Matrix
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf(" ", );    
        }
        printf("\n");
    }
