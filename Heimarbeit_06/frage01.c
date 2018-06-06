/**
 * Heimarbeit 06
 *
 * Frage 1
 *
 * Gehen Sie den folgenden Code durch und geben Sie die Werte des Arrays an.
 *
 *     << Code_Zeiger.JPG >>
 * 
 * Gefragt ist die finale Arraybelegung nach dem Ausführen des Codes.
 *
 *   iAFeld[0] = ?
 *   iAFeld[1] = ?
 *   iAFeld[2] = ?
 *   iAFeld[3] = ?
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
  int iAFeld[4] = {3, 2, 5, 6}; // Anfaengliche Array-Initialisierung
  // Array-Belegung: 3 2 5 6
  int* piMeinZeiger = NULL; // piMeinZeiger wird erzeugt und zeigt auf NULL
  // iAFeld zeigt auf das erste ArrayElement (Index 0), d.h. iAFeld -> 0.
  piMeinZeiger = iAFeld+2; // iAFeld+2 -> 2, piMeinZeiger = iAFeld+2 = 0+2 = 2, 
                           // piMeinZeiger zeigt auf das dritte ArrayElement (Index 2).
  *piMeinZeiger += 2; // Mit Stern-Operator (*) wird auf den Inhalt einer Speicherzelle zugegriffen. 
                      // *piMeinZeiger greift direkt auf den Inhalt der Speicherzelle mit der in 
					  // piMeinZeiger gespeicherten Adresse zu. 
					  // Da piMeinZeiger -> 2, dann: *piMeinZeiger = iAFeld[2] = 5. 
					  // Deshalb: *piMeinZeiger += 2 bedeutet 
					  // *piMeinZeiger = *piMeinZeiger + 2 = iAFeld[2] + 2 = 5 + 2 = 7
					  // Wegen *piMeinZeiger = iAFeld[2] gilt:
					  // iAFeld[2] = *piMeinZeiger = *piMeinZeiger + 2 = iAFeld[2] + 2 = 5 + 2 = 7
					  // D.h. das dritte ArrayElement (Index 2) hat neuen Wert, nämlich 7
  // Array-Belegung: 3 2 7 6
  piMeinZeiger = iAFeld; // iAFeld -> 0. Daher: piMeinZeiger = iAFeld = 0
                         // Also piMeinZeiger zeigt auf das erste ArrayElement (Index 0).
  *piMeinZeiger -= 1;    // *piMeinZeiger = iAFeld[0] = 3
                         // *piMeinZeiger -= 1 <==> *piMeinZeiger = *piMeinZeiger - 1= 3 - 1 = 2
						 // Daraus folgt: iAFeld[0] = *piMeinZeiger = 2
						 // Das erste ArrayElement (Index 0) bekommt neuen Wert 2.
  // Array-Belegung: 2 2 7 6
  *(++piMeinZeiger) += iAFeld[3]; // piMeinZeiger -> 0, zeigt immer noch auf das erste ArrayElement (Index 0).
                         // (++piMeinZeiger) erhöht piMeinZeiger um 1, d.h. piMeinZeiger -> 1 zeigt 
						 // jetzt auf das zweite ArrayElement (Index 1), d.h. (++piMeinZeiger) = iAFeld[1] = 2.
						 // *(++piMeinZeiger) greift auf den Inhalt von iAFeld[1].
						 // *(++piMeinZeiger) = iAFeld[1] = 2
						 // Und iAFeld[3] hat Wert 6.
						 // *(++piMeinZeiger) += iAFeld[3] bedeutet:
						 // *(++piMeinZeiger) = *(++piMeinZeiger) + iAFeld[3] = 2+iAFeld[3] = 2+6 = 8
						 // Wegen *(++piMeinZeiger) = iAFeld[1] gilt:
						 // iAFeld[1] = *(++piMeinZeiger) = *(++piMeinZeiger) + iAFeld[3] = 2+iAFeld[3] = 2+6 = 8
  // Array-Belegung: 2 8 7 6 
  return 0;
}
/**
 * Finale Arraybelegung nach dem Ausführen des Codes:
 *
 *   iAFeld[0] = 2
 *   iAFeld[1] = 8
 *   iAFeld[2] = 7
 *   iAFeld[3] = 8
 */ 
