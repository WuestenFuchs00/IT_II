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
 
     
    printf("Der Getraenkeautomat ist bereit.\n");
 
    //do-while
   
        //Ausgabe Flaschenstand
        printf("\nNoch  Wasserflaschen im Automat.", );
          
        //Benutzerabfrage 
        printf("\nWollen Sie ein Wasser? Ein Wasser kostet einen Euro.(ja=1/nein=0)\n");
          
        //Einlesen Benutzereingabe
        scanf();
  
        //if-else
 
            //Geldeinwurf
            printf("Geld jetzt einwerfen!(Einwerfen=1, Nicht_Einwerfen=0)");
         
            //Einlesen Geldeinwurf       
            scanf();
      
            //Geldeinwurf
            //Falls Geld eingeworfen
 
  
                printf("\nSie koennen Ihr Wasser entnehmen.\n");
 
         
        //Falls Geld nicht eingeworfen und Getränk angefordert    
 
            printf("\nEs wurde kein Geld eingeworfen. Der Vorgang wurde abgebrochen.");
 
     
       //nichts gewaehlt 
 
            printf("\nEs wurde nichts gewaehlt. Der Automat wird heruntergefahren.");
 
         
    //Ende do-while
 
          
    //Aufforderung, falls Automat leer und Geldbox voll      
 
        printf("\nBitte Wasserflaschen auffuellen und Geldbox leeren!");   
     
     return 0;
 }
