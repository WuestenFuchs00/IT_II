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
  int* piZeiger = NULL;
  int i = 0;

  piZeiger = iAFeld;
  piZeiger++;

  printf("Adresse des ersten Arrayelements: %p\n", (void*)iAFeld);
  printf("Adresse des dritten Arrayelements: %p\n", (void*)&iAFeld[2]);
  printf("Wert des Zeigers: %p\n\n", (void*)piZeiger);
  
  //Ausgabe des Ausgangsarrays
  for (i = 0; i < 6; i++)
  printf("%i ",iAFeld[i]);
  printf("\n");
  
  //1. Schritt
  *(++piZeiger) = iAFeld[4];
  
  //Ausgabe des Arrays
  for (i = 0; i < 6; i++)
  printf("%i ",iAFeld[i]);
  printf("\n");
  
  //2. Schritt
  piZeiger+2;
  ++(*piZeiger);
  
  //Ausgabe des Arrays
  for (i = 0; i < 6; i++)
  printf("%i ",iAFeld[i]);
  printf("\n");
  
  //3. Schritt
  piZeiger += 2;
  *(piZeiger+1) = *piZeiger&12;
  
  //Ausgabe des Arrays
  for (i = 0; i < 6; i++)
    printf("%i ",iAFeld[i]); 
  printf("\n");
  
  printf("\nZeiger zeigt auf die Stelle, dessen Inhalt ist: %i\n", *(piZeiger++));
  printf("Zeiger zeigt auf die Stelle, dessen Inhalt ist: %i", *piZeiger);
  
  return 0;
}
	 
