/**
 * Heimarbeit 04
 * Frage 3
 *
 * Schreiben Sie ein vollständiges C-Programm für einen Fahrkartenautomaten, der folgende drei Ziele anbietet:
 *
 *   o Berlin (B): 75 €
 *   o Frankfurft (F): 50 €
 *   o Augsburg (A): 25 €
 *
 * Falls ein ungueltiges Reiseziel eingegeben wird, soll darauf hingewiesen werden und erneut nach dem Reiseziel gefragt werden. 
 * Nach Eingabe eines korrekten Reiseziels soll der Kunde seine Eingabe bestätigen. Nach der Bestätigung hat der Benutzer die Wahl 
 * ein weiteres Ticket zu erwerben oder den Kauf zu beenden. Wenn er kein weiteres Ticket kauft, soll der Gesamtpreis ausgegeben 
 * und das Programm beendet werden.
 *
 * Himweis:
 *   o 
 *
 * Zum Beispiel:
 *
 * +---------+---------------------------------------------------------------------+
 * | Eingabe | Result                                                              |
 * +---------+---------------------------------------------------------------------+
 * | H       | Wo moechten Sie hinfahren? Berlin(B), Frankfurt(F) oder Augsburg(A) |
 * |         | Ihre Eingabe war nicht korrekt.                                     |
 * |         | Reiseziel nicht vorhanden.                                          |
 * |         |                                                                     |
 * | A       | Wo moechten Sie hinfahren? Berlin(B), Frankfurt(F) oder Augsburg(A) |
 * |         | Sie haben Augsburg als Reiseziel gewaehlt.                          |
 * | 1       | War Ihre Eingabe korrekt? Ja(1)/Nein(0)                             |
 * |         |                                                                     |
 * |         | Eine Reise nach Augsburg kostet 25 Euro.                            |
 * |         |                                                                     |
 * | 0       | Wollen Sie ein weiteres Ticket kaufen? Ja(1)/Nein(0)                |
 * |         |                                                                     |
 * |         | Vielen Dank fuer Ihren Einkauf. Der Gesamtpreis betraegt: 25 Euro   |
 * +---------+---------------------------------------------------------------------+
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

int main () {

  //Variablendeklaration
  char cZiel;
  int iEingabe = 1;
  unsigned int iGesamtpreis = 0;
  
  const unsigned short int iPreisBerlin = 75;
  const unsigned short int iPreisFrankfurt = 50;
  const unsigned short int iPreisAugsburg = 25;
 
 
  //Schleife zum Einlesen des Reiseziels
  do {
    printf ("Wo moechten Sie hinfahren? Berlin(B), Frankfurt(F) oder Augsburg(A)");
    if ( scanf(" %c", &cZiel) == 0 ) {
      printf("\nUngueltige Eingabe!");
      return 1;
    }
 
    //Fallunterscheidung
    switch ( cZiel ) {
      //Berlin
      case 'B':
        printf("\nSie haben Berlin als Reiseziel gewaehlt.");
        break;
      //Frankfurt
      case 'F':
        printf("\nSie haben Frankfurt als Reiseziel gewaehlt.");
        break;
      //Augsburg
      case 'A':
        printf("\nSie haben Augsburg als Reiseziel gewaehlt.");
        break;
      default:
        //sonst
        printf("\nIhre Eingabe war nicht korrekt. \nReisziel nicht vorhanden.\n\n");
        iEingabe = 0;
        break;
    }
 
    //falls gueltige Eingabe
    if ( cZiel == 'B' || cZiel == 'F' || cZiel == 'A' ) {
        do {
          printf ("\nWar Ihre Eingabe korrekt? Ja(1)/Nein(0)");
          if ( scanf("%i", &iEingabe) == 0 ) {
            printf("\nUngueltige Eingabe!");
            return 1;
          }
        } while ( !(iEingabe == 0 || iEingabe == 1) );
 
        //falls Eingabe korrekt
        if ( iEingabe ) {
          //Fallunterscheidung zur Berechnung und Ausgabe des Fahrpreises
          switch ( cZiel ) {
            //Berlin
            case 'B':
              printf("\n\nEine Reise nach Berlin kostet %hu Euro.", iPreisBerlin);
              iGesamtpreis += iPreisBerlin;
              break;
            //Frankfurt
            case 'F':
              printf("\n\nEine Reise nach Frankfurt kostet %hu Euro.", iPreisFrankfurt);
              iGesamtpreis += iPreisFrankfurt;
              break;
            //Augsburg
            default: // case 3
              printf("\n\nEine Reise nach Augsburg kostet %hu Euro.", iPreisAugsburg);
              iGesamtpreis += iPreisAugsburg;
              break;
          }
          
          //Benutzereingabe weiteres Ticket
          do {
            printf ("\n\nWollen Sie ein weiteres Ticket kaufen? Ja(1)/Nein(0)\n");
            if ( scanf("%i", &iEingabe) == 0 ) {
              printf("\nUngueltige Eingabe!");
              return 1;
            }
          } while ( !(iEingabe == 0 || iEingabe == 1) );
          
          iEingabe = !iEingabe;
        }
        //falls Eingabe nicht korrekt
        else {
          printf("\n\nBitte waehlen Sie Ihr Ticket erneut.\n");
        }
    }
    
    //falls ungueltige Eingabe    
  } while ( !iEingabe ); 
 
 
//Ausgabe des Gesamtpreises
printf("\nVielen Dank fuer Ihren Einkauf. Der Gesamtpreis betraegt: %u Euro", iGesamtpreis);

return 0;
}
