/**
 * Heimarbeit 06
 *
 * Frage 3
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
  
int main()
{
    //Variablendeklaration
    int i = 0, flaschen = 10, geldstand = 0;
     
    printf("Der Getraenkeautomat ist bereit.\n");
 
    //do-while
    do {
        //Ausgabe Flaschenstand
        printf("\nNoch %i Wasserflaschen im Automat.", flaschen);
          
        //Benutzerabfrage 
        printf("\nWollen Sie ein Wasser? Ein Wasser kostet einen Euro.(ja=1/nein=0)\n");          
        //Einlesen Benutzereingabe
        scanf("%i", &i);
  
        //if-else
        if ( i ) {
            //Geldeinwurf
            printf("Geld jetzt einwerfen!(Einwerfen=1, Nicht_Einwerfen=0)");         
            //Einlesen Geldeinwurf       
            scanf("%i", &i);
      
            //Geldeinwurf
            //Falls Geld eingeworfen
            if ( i ) {  
                printf("\nSie koennen Ihr Wasser entnehmen.\n");
                flaschen -= 1;
                geldstand += 1;
            }
            //Falls Geld nicht eingeworfen und Getränk angefordert    
            else {
                printf("\nEs wurde kein Geld eingeworfen. Der Vorgang wurde abgebrochen.");
            } 
        }
       //nichts gewaehlt 
       else {
            printf("\nEs wurde nichts gewaehlt. Der Automat wird heruntergefahren.");
            break;
       } 
    } while ( flaschen > 0 && geldstand < 10 );     
    //Ende do-while
 
          
    //Aufforderung, falls Automat leer und Geldbox voll      
    if ( !(flaschen > 0 && geldstand < 10) ) {
        printf("\nBitte Wasserflaschen auffuellen und Geldbox leeren!");   
    }
     
    return 0;
 }
