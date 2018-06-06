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
  int iAFeld[4] = {3, 2, 5, 6};
  int* piMeinZeiger = NULL;
  
  piMeinZeiger = iAFeld+2;
  *piMeinZeiger += 2;
  piMeinZeiger = iAFeld;
  *piMeinZeiger -= 1;
  *(++piMeinZeiger) += iAFeld[3];
  
  return 0;
}
	 
