/**
 * Zentralübung 4
 *
 * Frage 1
 *
 * Schreiben ein C-Programm, dass den Wert einer Integration numerisch annähert.
 * Folgende Funktion soll integriert werden: 
 *
 *   y = ( sin(x)* x^3 ) / sqrt(7*x)
 *
 * Die Ausgabe soll wie folgt aussehen:
 *
 *   Bitte geben Sie die untere Grenze des Integrals ein:
 *   Bitte geben Sie die obere Grenze des Integrals ein:
 *   Bitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein:
 *   Die Integration hat den Wert  
 *
 * Hinweise und Tipps:
 *
 *   o Beachten Sie, dass für einige Rechenoperationen die Bibliothek <math.h> eingebunden werden muss
 *       o a^b -> pow(a,b)
 *       o sqrt(a) -> sqrt(a)
 *  o Um die Genauigkeit der Rechnung überprüfen zu können, benötigen Sie möglichst viele Nachkommastellen
 *  o Realisieren Sie die Berechnung des Integrals einmal mittels einer WHILE-Schleife und einmal mittels 
 *    einer FOR-Schleife
 *  o Der Nutzer des Programmes soll die Integrationsgrenzen und die Schrittweite, also die Genauigkeit 
 *    der Annäherung bestimmen können
 *  o Die zu integrierende Formel muss direkt in den Code geschrieben werden
 *
 * Zum Beispiel:
 *
 *  +----------+---------------------------------------------------------------------+
 *  | Eingabe  | Result                                                              |
 *  +----------+---------------------------------------------------------------------+
 *  | 2        | Bitte geben Sie die untere Grenze des Integrals ein:                |
 *  | 3        | Bitte geben Sie die obere Grenze des Integrals ein:                 |
 *  | 0.001    | Bitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein: |
 *  |          | Die Integration hat den Wert 1.951739                               |
 *  +----------+---------------------------------------------------------------------+
 *
 * Compile: 
 *    gcc -Wall -std=gnu99 -pedantic <quelldatei.c> -lm -o <output.exe>
 *
 *    -std=c90 -pedantic
 *    -std=c89 -pedantic
 *    -std=c99 -pedantic
 *    -std=gnu99 -pedantic
 *
 *    -lm : wird benötigt, um <math.h> einzubinden. Sonst gibts "Reference-Error" bzw. Verweisfehler.
 */
#include <stdio.h>
#include <math.h>

int main () {
  
  //Variablendeklaration
  float fUntereGrenze, fObereGrenze;
  float fDX;
  double fX, fA = 0;
  
  printf("Bitte geben Sie die untere Grenze des Integrals ein:");
  if ( scanf("%f", &fUntereGrenze) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
  
  printf("Bitte geben Sie die obere Grenze des Integrals ein:");
  if ( scanf("%f", &fObereGrenze) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
  
  printf("Bitte geben Sie die Schrittweite (Genauigkeit) der Annaeherung ein:");
  if ( scanf("%f", &fDX) == 0 ) {
    printf("\nUngueltige Eingabe!");
    return 1;
  }
  
  /* Realisierung mittels WHILE-Schleife */
  fX = fUntereGrenze;  
  while ( fX <= fObereGrenze ) {
    fA += sin(fX) * pow(fX,3) / sqrt(fX*7) * fDX;
    fX += fDX;
  }
  
  /* Realisierung mittels FOR-Schleife */
  fA = 0;
  for ( fX = fUntereGrenze; fX <= fObereGrenze; fX = fX + fDX ) {
    fA += sin(fX) * pow(fX,3) / sqrt(fX*7) * fDX;
  }
  
  printf("Die Integration hat den Wert %lf", fA);
  
  return 0;
}

/**
 * °° Datentyp "float" hat Größe (Bitgenauigkeit) von 4 Byte (32 Bit), während "double" die doppelte
 *    Bitgenauigkeit (8 Byte, 64 Bit) hat. 
 *    
 *    Sei die Gleitkommazahl 0.001 gegeben. Man macht einen Test auf deren Datentyp. Zuerst mit "float":
 *
 *      float zahl = 0.001;
 *      printf("Zahl %f ist vom Typ double: %i", zahl, zahl == 0.001); // Zahl 0.001 ist vom Typ double: 0
 *
 *    Der Ausdruck "zahl == 0.001" wird mit 0 (FALSE) bewertet, d.h. mit "float" kann der Wert von 0.001 
 *    nicht exakt genug dargestellt bzw. approximiert werden.
 *    
 *    Mit "double" würde das anders aussehen:
 *
 *      doublet zahl = 0.001;
 *      printf("Zahl %lf ist vom Typ double: %i", zahl, zahl == 0.001); // Zahl 0.001 ist vom Typ double: 1
 *
 *    Der Ausdruck "zahl == 0.001" wird mit 1 (TRUE) bewertet, d.h. mit "double" wird näher an dem exakten
 *    Wert 0.001 approximiert.
 *
 *    Die Gleitkommazahl 0.001 hat die Binärdarstellung:
 *
 *       0.001 = 0.00000000010000011000100100110111...
 *
 *    IEEE-754 Einfache Genauigkeit (float, 32 Bit) ergbit:
 *
 *        1 Bit    8 Bit             23 Bit
 *         VZ     Exponent          Mantisse M
 *       +-----+------------+---------------------------+
 *       |  0  |  01111111  |  00000000010000011000100  |  32 Bit
 *       +-----+------------+---------------------------+
 *
 *    mit Bias B = 2^(r-1)-1 = 2^(8-1)-1 = 127, da Exponent E ist 8 Bit lang für IEEE-754 float.
 *    
 *    Zurückrechnen:
 *      VZ = 0
 *      E = 01111111 = 127  ==>  e = B - E = 127 - 127 = 0
 *      M = .00000000010000011000100
 *
 *      Zahl = (-1)^VZ * 0.M * 2^e
 *           = 0.00000000010000011000100 
 *           =~ 1*2^(-10) + 1*2^(-16) + 1*2^(-17) + 1*2^(-21)
 *           =~ 0.00099992752
 */
