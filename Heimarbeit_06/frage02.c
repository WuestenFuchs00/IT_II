/**
 * Heimarbeit 06
 *
 * Frage 2
 *
 * Das folgende Programm ist lediglich zu Vorführungszwecken gedacht und soll Sie mit Zeigerarithmetik 
 * vertraut machen. Gehen Sie daher den Code aufmerksam durch und versuchen Sie die Vorgänge 
 * nachzuvollziehen.
 *
 * Hinweise:
 *   o Wo werden Adressen oder Werte von Zeigern/Variablen ausgegeben/beeinflusst?
 *   o Beachten Sie den Platzhalter "%p", um Adressen von Pointern auszugeben und die notwendige 
 *     Typenumwandlung der Variablen zu (void*) zu realisieren.
 *   o Achten Sie auf die Adress-Abstände benachbarter Array Elemente. Was fällt Ihnen auf und wieso 
 *     verhält es sich so?
 *   o Es ist ein Befehl im Code enthalten, der nicht wirklich sinnvoll ist, da er keine Aktion ausführt. 
 *     Welcher ist es? = ___________
 *
 * Erhalten:
 *
 *     << AUSGABE.JPG >>
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -lm -o <output.exe>
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
  int iAFeld[6] = {3, 7, 7, 9, 6, 9};
  int* piZeiger = NULL; // Zeiger
  int i = 0;

  piZeiger = iAFeld; // piZeiger zeigt auf gleiche Adresse (= Adresse des 1ten Arrayelements = &iAFeld[0]) wie iAFeld.
  piZeiger++; // piZeiger zeigt auf Adresse (= &iAFeld[1] ) des 2ten Arrayelements.

  printf("Adresse des ersten Arrayelements: %p\n", (void*)iAFeld);
  printf("Adresse des dritten Arrayelements: %p\n", (void*)&iAFeld[2]);
  printf("Wert des Zeigers: %p\n\n", (void*)piZeiger); // piZeiger zeigt auf Adr. des 2ten Arrayelements (= &iAFeld[1])
  
  //Ausgabe des Ausgangsarrays
  for (i = 0; i < 6; i++)
  printf("%i ",iAFeld[i]);
  printf("\n"); // 3 7 7 9 6 9
  
  //1. Schritt
  *(++piZeiger) = iAFeld[4]; // (++piZeiger) heißt, piZeiger wird um 1 erhöht und zeigt auf das nächste ArrElem.
                             // piZeiger zeigt auf die Adr. (= &iAFeld[2] ) des 3ten ArrElems.
                             // *(++piZeiger) == iAFeld[2]
                             // iAFeld[2] = *(++piZeiger) := iAFeld[4]
                             // 3tes ArrElem bekommt Wert des 5ten ArrElems.
  
  //Ausgabe des Arrays
  for (i = 0; i < 6; i++)
  printf("%i ",iAFeld[i]);
  printf("\n"); // 3 7 6 9 6 9
  
  //2. Schritt
  piZeiger+2; // Sinnlose Aktion, piZeiger zeit immer noch auf Adresse &iAFeld[2]
  ++(*piZeiger); // *piZeiger == Inhalt von piZeiger == iAFeld[2]
                 // Inhalt wird um 1 inkrementiert, d.h. ++iAFeld[2]
  
  //Ausgabe des Arrays
  for (i = 0; i < 6; i++)
  printf("%i ",iAFeld[i]);
  printf("\n"); // 3 7 7 9 6 9
  
  //3. Schritt
  piZeiger += 2; // piZeiger zeigt um 2 Stellen erhöht, d.h. zeigt auf Adr (= &iAFeld[4]) des übernächsten ArrElems. 
  *(piZeiger+1) = *piZeiger&12; // *(piZeiger+1) == iAFeld[5]
                                // *piZeiger == iAFeld[4] == 6
                                // 6 & 12 = 0110 & 1100 = 0100 = 4
                                // *(piZeiger+1) = iAFeld[5] := 4
                                // piZeiger zeigt nach diesen Schritten immer noch auf &iAFeld[4].
  
  //Ausgabe des Arrays
  for (i = 0; i < 6; i++)
    printf("%i ",iAFeld[i]); 
  printf("\n"); // 3 7 7 9 6 4
  
  printf("\nZeiger zeigt auf die Stelle, dessen Inhalt ist: %i\n", *(piZeiger++)); // 6
  printf("Zeiger zeigt auf die Stelle, dessen Inhalt ist: %i", *piZeiger); // 4
  
  return 0;
}
	 
