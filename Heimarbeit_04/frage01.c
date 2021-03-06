/**
 * Heimarbeit 04
 * Frage 1
 *
 * Schreiben Sie ein vollständiges C-Programm für einen Getränkeautomat einer Universität. Der Automat besitzt drei 
 * Getränke im Sortiment.
 *
 *   o Mineralwasser (0,50 €)
 *   o Limonade (1,00 €)
 *   o Apfelsaft (1,50€)
 *
 * Das Programm soll zu Beginn den Kunden fragen, welches Getränk er möchte. Nach der Eingabe des Getränkes soll der 
 * Kunde solange gefragt werden, ob er ein weiteres Getränk möchte, bis er die Frage mit Nein beantwortet. 
 * Bei unzulässigen Eingaben, muss der Kunde erneut gefragt werden. Der Gesamtpreis soll nach jeder Eingabe addiert 
 * werden (noch ohne Berücksichtigung eines Rabattes). Wenn der Kunde kein weiteres Getränk wünscht, soll sein Status
 * abgefragt werden. Es gibt drei Auswahlmöglichkeiten:
 *
 *   o Student: Ein Student muss 50% des Gesamtpreises zahlen.
 *   o Mitarbeiter: Ein Mitarbeiter muss 75% des Gesamtpreises zahlen.
 *   o Gast: Ein Gast muss den kompletten Preis bezahlen.
 *
 * Im Anschluss an die Personenabfrage soll der zu zahlende Gesamtpreis (jetzt mit Berücksichtigung des Rabattes) auf 
 * zwei Nachkommastellen ausgegeben werden.
 *
 * Um Ihnen die Bearbeitung der Aufgabe zu erleichtern, ist folgendes Zustandsdiagramm gegeben:
 *
 *   << Zustanddiagramm.JPG >>
 *
 * Hinweise:
 *
 *   o Verwenden Sie für die verschieden Fälle der Getränkeauswahl und der Personenabfrage Switch-Case-Strukturen
 *
 * Zum Beispiel:
 *
 * +---------+------------------------------------------------------+
 * | Eingabe | Result                                               |
 * +---------+------------------------------------------------------+
 * | 2       | Bitte waehlen Sie ein Getraenk:                      |
 * |         | Mineralwasser(1) 0.50 Euro                           |
 * |         | Limonade(2) 1.00 Euro                                |
 * |         | Apfelsaft(3) 1.50 Euro                               |
 * |         |                                                      |
 * |         | Sie haben eine Limonade gewaehlt.                    |
 * |         | Gesamtpreis: 1.00 Euro                               |
 * | 0       | Wuenschen Sie ein weiteres Getraenk? Ja(1)/Nein(0)   |
 * |         |                                                      |
 * | 1       | Sind Sie Student(1), Mitarbeiter(2) oder Gast(3)?    |
 * |         | Als Student erhalten Sie 50 Prozent Rabatt.          |
 * |         | Bitte zahlen Sie: 0.50 Euro                          |
 * |         | Vielen Dank fuer Ihren Einkauf.                      |
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

int main () {

  //Variablendeklaration
  int iEingabe;
  float fPreis = 0;
  
  //Schleifen+Fallunterscheidung zum Abfragen der Getraenke
  do {
  
    do {
      printf("Bitte waehlen Sie ein Getraenk:\nMineralwasser(1) 0.50 Euro \nLimonade(2) 1.00 Euro \nApfelsaft(3) 1.50 Euro\n");
      if ( scanf("%i", &iEingabe) == 0 ) {
        printf("\nUngueltige Eingabe!");
        return 1;
      }
    } while ( !(iEingabe == 1 || iEingabe == 2 || iEingabe == 3) );
    
    //Fallunterscheidung_1
    switch ( iEingabe ) {
      //Mineralwasser
      case 1:
        fPreis += .5;
        printf("\nSie haben ein Mineralwasser gewaehlt.\nGesamtpreis: %.2f Euro", fPreis);
        break;    
      //Limonade
      case 2:
        fPreis += 1;
        printf("\nSie haben eine Limonade gewaehlt.\nGesamtpreis: %.2f Euro", fPreis);
        break;
      //Apfelsaft
      default: // case 3
        fPreis += 1.5;
        printf("\nSie haben einen Apfelsaft gewaehlt.\nGesamtpreis: %.2f Euro", fPreis);
        break;
    }
    
    //Abfrage:Weiteres Getraenk            
    do {
      printf("\nWuenschen Sie ein weiteres Getraenk? Ja(1)/Nein(0)\n");
      if ( scanf("%i", &iEingabe) == 0 ) {
        printf("\nUngueltige Eingabe!");
        return 1;
      }
    } while ( !(iEingabe == 0 || iEingabe == 1) );
    
  } while ( iEingabe == 1 );
 
  //Unterscheidung zwischen Student, Mitarbeiter und Gast
  do {
    printf("\nSind Sie Student(1), Mitarbeiter(2) oder Gast(3)?");
    if ( scanf("%i", &iEingabe) == 0 ) {
      printf("\nUngueltige Eingabe!");
      return 1;
    }
  } while ( !(iEingabe == 1 || iEingabe == 2 || iEingabe ==3) );
  //Fallunterscheidung_2
  switch ( iEingabe ) {
    //Student
    case 1:
      printf("\nAls Student erhalten Sie 50 Prozent Rabatt.");
      fPreis *= .5;
      break;      
    //Mitarbeiter
    case 2:
      printf("\nAls Mitarbeiter erhalten Sie 25 Prozent Rabatt."); 
      fPreis *= .75;
      break;
    //Gast
    default: //case 3
      printf("\nAls Gast zahlen Sie den Normalpreis.");
      break;
  } 

  //Ausgabe des zu zahlenden Betrages
  printf("\nBitte zahlen Sie: %.2f Euro \nVielen Dank fuer Ihren Einkauf.", fPreis);


  return 0;
}
