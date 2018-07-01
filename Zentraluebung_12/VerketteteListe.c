/**
 * LinkedList.c
 * Einfache verkettete Liste
 *
 * Erstellung einer einfach verketteten Liste:
 *
 * o Schritt 1: Definition der benötigten Datenstrukturen
 *     o Nutzdaten
 *     o Listenelement (enthält 
 *         1. Nutzdaten, und 
 *         2. Zeiger das folgende Listenelement)
 *     o Liste:
 *         - Zeiger auf das erste Listenelement
 *         - Optional: Weitere Informationen über die Liste (z.B. Zahl der Elemente)
 *
 * o Schritt 2: Nutzung der Liste
 *     o Initialisierung einer leeren Liste
 *     o Einfügen neuer ELemente (am Anfang, in der Mitte, am Ende)
 *     o Suche nach Elementen
 *     o Löschen von Elementen / Löschen der gesamten Liste
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * typedef:
 *   https://en.cppreference.com/w/c/language/typedef
 * name space (tag, ordinary):
 *   https://en.cppreference.com/w/c/language/name_space
 * struct (Forward declaration):
 *   https://en.cppreference.com/w/c/language/struct
 *
 * Typedef (syntax):
 *   typedef TYP NAME;
 *
 * Anonymous struct (= struct without name): struct {..}
 *   typedef struct {} name;
 *   -> Mit "typedef" wird neuer (anonymer) Typ "struct {}" ohne Bezeichner definiert.
 *   -> "struct {}" wird nur in Ordinary-Namespace eingetragen.
 *   -> In Tag-Namespace wird nicht(s) eingetragen, da es "anonymous struct" ist und kein Bezeichner.
 *
 * Not anonymous struct (= struct with name): struct name {..}
 *   typedef struct name {..} name;
 * bzw.
 *   struct name {..};
 *   typedef struct name name;
 *
 *   -> Mit "struct name" wird der Typ "struct name" bzw. "name" deklariert und in Tag-Namespace eingetragen.
 *   -> Mit "typedef" wird neuer Typ "struct name" definiert und in Ordinary-Namespace eingetragen.
 *   -> Sowohl in Tag-Namespace als auch Ordinary-Namespace findet sich "struct name".
 *   -> Damit ist der Typ "struct name" komplett.
 */
typedef struct {
	char szMarke[81];
	int iBaujahr;
	float fPreis;
} PKW;

typedef struct KNOTEN {
	PWK Pkw;
	struct KNOTEN *pNext;
} KNOTEN;

typedef struct {
	KNOTEN *pFirst;
	int iAnzahl;
} LISTE;

/*
 * Sucht nach einem Element an einer bestimmten Stelle <iStelle>.
 * iStelle (iLauf) erstreckt sich von 1 bis N.
 */
KNOTEN * search (LISTE * Liste, int iStelle) {
	KNOTEN *pTempLauf = Liste->pFirst;
	int iLauf;
	for ( iLauf = 1; iLauf < iStelle; iLauf++ ) {
		pTempLauf = pTempLauf->pNext;
	}
	return pTempLauf;
}

/*
 * Einfuegen eines Elements an erster Stelle
 */
void insertfront (LISTE* Liste) {
	KNOTEN *pTemp = Liste->pFirst;
	Liste->pFirst = (KNOTEN *) malloc(sizeof(KNOTEN));
	Liste->pFirst->pNext = pTemp;
	Liste->iAnzahl++;
	
	/*
	KNOTEN *pTemp = (KNOTEN *) malloc(sizeof(KNOTEN));
	pTemp->pNext = Liste->pFirst;
	Liste->pFirst = pTemp;
	Liste->iAnzahl++;
	*/
}

/*
 * Loeschen eines Listenelements an einer bestimmten Stelle <iStelle>.
 * iStelle (iLauf) erstreckt sich von 1 bis N.
 */
void deleteElement(LISTE * Liste, int iStelle) {
	KNOTEN *pTemp, *pTemp2;	
	if ( iStelle != 1 ) { // 1 : Erstes Listenelement
		pTemp = search(Liste, iStelle);
		pTemp2 = search(Liste, iStelle-1);
		pTemp2->pNext = pTemp->pNext;
		free(pTemp);
	}
	else {
		/*
		pTemp = Liste->pFirst;
		Liste->pFirst = pTemp->pNext;
		free(pTemp);
		*/
		pTemp = Liste->pFirst->pNext;
		free(Liste->pFirst);
		Liste->pFirst = pTemp;
	}
	Liste->iAnzahl--;
}

/*
 * Loeschen aller Listenelemente (Iterativ, Schleife)
 */
void deleteList (LISTE * Liste) {
	/* Pruefen, ob eine leere Liste uebergeben wurde */
	while ( Liste->pFirst != NULL ) {
		deleteElement(Liste, 1);
	}
}

/*
 * Loeschen aller Listenelemente (Rekursiv)
 */
void deleteListRec (LISTE * Liste) {
	if ( Liste->pFirst != NULL ) {
		deleteElement(Liste, 1);
		deleteListRec(Liste);
	}
}

/*
 *
 */
void printliste (LISTE * Liste);

/*
 *
 */
int main ()
{
	int i, iStelle;
	
	LISTE PKW_Liste;
	PKW_Liste.pFirst = NULL;
	PKW_Liste.iAnzahl = 0;

	//Auswahl
	switch ( i ) {
		case 1:
			insertfront(&PKW_Liste);
			break;
		case 2:
			deleteElement(&PKW_Liste, iStelle);
			break;
		default:
			printliste(&PKW_Liste);
			break;
	}
	deletelist(&PKW_Liste);
	
	return 0;
}