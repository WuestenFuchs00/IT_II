/**
 * Heimarbeit 03
 * Frage 6
 *
 * Sie sollen für einen Kaugummiautomaten mit 4 Spindeln (laufende Nummern von 0 bis 3) ein
 * vollständiges C-Programm schreiben, das 
 *   o den Benutzer fragt, welchen Kaugummi er möchte und
 *   o bei zulässiger Eingabe den Status des Benutzers abfragt (Student, Mitarbeiter oder 
 *     Gast), um den entsprechenden Endpreis auszugeben
 *        o Student bekommt 50% Rabatt
 *        o Mitarbeiter bekommt 20% Rabatt
 *        o Gast zahlt den vollen Preis
 *
 * Hinweise und Tipps:
 *   o Verwenden Sie switch-case-statements, um die gewünschten Ausgaben zu realisieren
 *   o Fangen Sie unzulässige Eingaben mithilfe von switch-case ab und geben Sie in diesem 
 *     Fall eine Fehlermeldung aus
 *   o Setzen Sie den Preis auf 0, sollte der Benutzer eine unzulässige Nummer wählen
 *
 * Zum Beispiel:
 * 
 * +---------+-------------------------------------------------------------+
 * | Eingabe | Result                                                      |
 * +---------+-------------------------------------------------------------+
 * | 2       | Welchen Kaugummi wollen Sie?                                |
 * | 1       | Extra kostet 70 Cent.                                       |
 * |         | Sind Sie Student(0), Mitarbeiter(1) oder Gast(2)?           |
 * |         | Als Mitarbeiter zahlen Sie bitte 0.56 Euro.                 |
 * +---------+-------------------------------------------------------------+
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
  
  //Variableninitialisierung
  unsigned short int iEingabe; // short = half = 1/2 int
  float fPreis = 0;
  
  //Benutzereingabe Nummer des gewuenschten Kaugummis
  printf("Welchen Kaugummi wollen Sie?");
  //Ueberpruefung ob scanf erfolgreich war
  if ( scanf("%hu", &iEingabe) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
  

  //switch-case-Struktur zur Wahl des Kaugummis
  switch ( iEingabe ) {
    //Spindel 0
    case 0:
      printf("\nWrigley's kostet 90 Cent.");
      fPreis = .9;
      break;
    //Spindel 1
    case 1:
      printf("\nBig Red kostet 95 Cent.");
      fPreis = .95;
      break;
    //Spindel 2
    case 2:
      printf("\nExtra kostet 70 Cent.");
      fPreis = .7;
      break; 
    //Spindel 3
    case 3:
      printf("\nOrbit kostet 1 Euro.");
      fPreis = 1;
      break; 
    //sonst
    default:
      printf("\nUngueltige Eingabe!");
      break;
  }
 
 //falls zulaessige Eingabe
 if ( iEingabe >= 0 && iEingabe <= 3 ) {
    //Benutzereingabe Rabatt
    printf("\nSind Sie Student(0), Mitarbeiter(1) oder Gast(2)?");
    if ( scanf("%hu", &iEingabe) == 0 ) {
      printf("\nUngueltige Eingabe!");
      return 1;
    }
    //switch-case-Struktur zur Wahl des Rabattes
    switch ( iEingabe ) {
      //Student
      case 0:
        fPreis *= .5;
        printf("\nAls Student zahlen Sie bitte %.2f Euro.", fPreis);
        break;         
      //Mitarbeiter
      case 1:
        fPreis *= .8;
        printf("\nAls Mitarbeiter zahlen Sie bitte %.2f Euro.", fPreis);
        break; 
      //Gast
      case 2:
        printf("\nAls Gast zahlen Sie bitte %.2f Euro.", fPreis);
        break; 
      //sonst
      default:
        printf("\nUngueltige Eingabe!");
        break;
    }
  }
  
  return 0;
}
