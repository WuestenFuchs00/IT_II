/**
 * LinkedList.c
 *
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

#define MAX 81

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
typedef struct KNOTEN { 
	char szBezeichnung[MAX];
	int iWert;
	struct KNOTEN * pNext; // forward-declaration
} KNOTEN;

typedef struct {
	KNOTEN * pFirst;
	int iAnzahl;
} LISTE;

/*
 * Creates a new node and assigns the values.
 */
KNOTEN * CreateNode(char * szBezeichnung, int iWert) {
	KNOTEN * pKnoten = (KNOTEN *) malloc(sizeof(KNOTEN));
	pKnoten->pNext = NULL;
	
	// Werte zuweisen
	//strncpy(pKnoten->szBezeichnung, szBezeichnung, strlen(szBezeichnung)+1); +1 bedeutet \0 (String-Ende)
	strcpy(pKnoten->szBezeichnung, szBezeichnung); // String kopieren
	pKnoten->iWert = iWert;
	return pKnoten;
}

/*
 * Durchsucht die Liste nach Knoten an bestimmter Stelle und liefert 
 * Pointer auf ihn zurueck. Listelemente beginnen ab Index 1 (bis N).
 */
KNOTEN * Search(LISTE * pListe, int iStelle /* 1..N */) {
	KNOTEN * pTemp = pListe->pFirst;
	int i = 1;
	while ( i < iStelle ) {
		pTemp = pTemp->pNext;
		++i;
	}
	return pTemp;
}

/*
 * Removes a node with specified index (iStelle) from list.
 * First node has index 1. Last node has index N.
 *
 * Return value:
 *   -1 (FALSE) if the list does not exists
 *    1 (TRUE)  if the specified node has been removed successfully, or the list is empty
 */
int DeleteNode(LISTE * pListe, int iStelle) {
	if ( pListe == NULL ) return -1; // FALSE
	if ( pListe->pFirst == NULL ) return 1; // TRUE;
	
	KNOTEN * pTemp, * pDelete;
	
	if ( iStelle != 1 ) {
		// Sucht nach Knoten an Stelle <iStelle> und <iStelle-1>
		pTemp    = Search(pListe, iStelle-1);
		pDelete  = Search(pListe, iStelle);
		// Loesche Knoten und verweist die Zeiger neu
		pTemp->pNext = pDelete->pNext;
		free(pDelete);
	}
	else { // iStelle == 1
		pTemp = pListe->pFirst->pNext;
		free(pListe->pFirst);
		pListe->pFirst = pTemp;
	}
	
	// Dekrementiert Knotenanzahl
	pListe->iAnzahl -= 1;
	
	return 1; // TRUE
}

/*
 * Removes all nodes of the list (itertiv, loop)
 * Return value:
 *   -1 (FALSE) if the list is null and nothing can be deleted
 *    1 (TRUE)  if the whole list has been deleted successfully
 */
int DeleteList(LISTE * pListe) {
	int res = DeleteNode(pListe, 1);
	if ( res != -1 ) {
		while ( pListe->pFirst != NULL )
			res = DeleteNode(pListe, 1);		
	}
	return res;
}

/*
 * Returns the number of all nodes in linked list.
 */
int GetSize(LISTE * pListe) {
	return pListe->iAnzahl;
}

/*
 * Returns the pointer to the first node of linked list.
 */
KNOTEN * GetFirstNode (LISTE * pListe) {
	return pListe->pFirst;
}

/*
 * Returns the pointer to the last node of linked list.
 */
KNOTEN * GetLastNode (LISTE * pListe) {
	return Search(pListe, pListe->iAnzahl);
}

/*
 * Returns the pointer to a certain node with index <iStelle>
 */
KNOTEN * GetNode (LISTE * pListe, int iStelle) {
	return Search(pListe, iStelle);
}

/*
 * Inserts a new node in first position of linked list.
 *
 * Return value:
 *   -1 (FALSE) if no node can be inserted
 *    1 (TRUE)  if new node has been inserted successfully
 */
int InsertFront(LISTE * pListe, char * szBezeichnung, int iWert) {
	if ( pListe == NULL ) return -1; // FALSE
	
	// Neuen Knoten erzeugen und Werte zuweisen
	KNOTEN * pKnoten = CreateNode(szBezeichnung, iWert);
	
	// Knoten in die Liste einfuegen
	pKnoten->pNext = pListe->pFirst;
	pListe->pFirst = pKnoten;
	
	// Inkrementiert Knotenanzahl
	pListe->iAnzahl += 1;
	
	return 1; // TRUE
}

/*
 * Inserts a new node at the end of linked list.
 *
 * Return value:
 *   -1 (FALSE) if no node can be inserted
 *    1 (TRUE)  if new node has been inserted successfully
 */
int InsertEnd(LISTE * pListe, char * szBezeichnung, int iWert) {
	if ( pListe == NULL ) return -1; // FALSE
	
	// Neuen Knoten erzeugen und Werte zuweisen
	KNOTEN * pNewNode = CreateNode(szBezeichnung, iWert);
	
	// Knoten am Ende der Liste einfuegen
	KNOTEN * pLastNode = Search(pListe, pListe->iAnzahl); // Letzter Knoten
	
	if ( pLastNode == NULL ) { // Liste ist noch leer => Einfuegen am Anfang
		pListe->pFirst = pNewNode;
	}
	else {
		pLastNode->pNext = pNewNode;
	}
	
	// Inkrementiert Knotenzahl
	pListe->iAnzahl += 1;
	
	return 1; // TRUE
}

/*
 * Removes a node with specified index (iStelle) from list.
 * First node has index 1. Last node has index N.
 *
 * Return value:
 *   -1 (FALSE) if the list does not exists
 *    1 (TRUE)  if the specified node has been removed successfully, or the list is empty
 */
int RemoveNode(LISTE * pListe, int iStelle) {
	return DeleteNode(pListe, iStelle);
}

/*
 * Removes all nodes of the list (recursive).
 * Return value:
 *   -1 (FALSE) if the list is null and nothing can be deleted
 *    1 (TRUE)  if the whole list has been deleted successfully
 */
int RemoveList(LISTE * pListe) {
	int res = RemoveNode(pListe, 1);
	if ( res != -1 ) {
		if ( pListe->pFirst != NULL )
			res = RemoveList(pListe);
	}
	return res;
}

/*
 * Prints the content of a node
 */
void PrintNode(KNOTEN * pKnoten) {
	printf("\n Inhalt: (%s,%i)\n", pKnoten->szBezeichnung, pKnoten->iWert);
}

/*
 * Prints all list elements
 */
void PrintList(LISTE * pListe) {
	if ( pListe == NULL || pListe->pFirst == NULL ) return;
	
	KNOTEN *pKnoten = pListe->pFirst;
	
	printf("  first : ");
	
	do {
		printf(" (%s,%i) ->", pKnoten->szBezeichnung, pKnoten->iWert);
		pKnoten = pKnoten->pNext;
	} while ( pKnoten != NULL );
}

/*
 *
 */
int main () {	
	// Variablen deklarieren
	int i, j, iErg, iAnzahl, iWert;
	char szBezeichnung[MAX];
	
	// Initialisierung einer leeren Liste
	LISTE Liste;
	Liste.pFirst = NULL;
	Liste.iAnzahl = 0;
	
	printf("\n Leere Liste wurde initialisiert.");
	printf("\n Knotenanzahl: %i\n", GetSize(&Liste));
	
	do {	
		fprintf(stdout, "\n Aktionen zum Ausfuehren:\n");
		fprintf(stdout, "  (1) InsertFront       (2) InsertEnd\n");
		fprintf(stdout, "  (3) GetFirstNode      (4) GetLastNode\n");
		fprintf(stdout, "  (5) GetSize           (6) RemoveNode\n");
		fprintf(stdout, "  (7) PrintList         (8) Exit\n\n");
		fprintf(stdout, " Ihre Auswahl: ");
		scanf("%i", &i);
		
		if ( i == 1 || i == 2 ) {
			printf("\n Anzahl der einzufuegenden Knoten: ");
			if ( scanf("%i", &iAnzahl) == 0 || iAnzahl < 0 ) {
				printf("\n Ungueltige Eingabe!");
				return 1;
			}
			// Einfuegen vom Knoten in leere Liste	
			fprintf(stdout, "\n Einfuegen von Knoten. Beispiel: A 3\n");
			for ( j = 0; j < iAnzahl; j++ ) {
				printf(" Knoten %i: ", j+1);
				fscanf(stdin, "%s" "%i", szBezeichnung, &iWert);
				iErg = ( i == 1 ) ? InsertFront(&Liste, szBezeichnung, iWert) : InsertEnd(&Liste, szBezeichnung, iWert);
				if ( iErg != 1 ) {
					printf("\n Fehler! Knoten kann nicht hinzugefuegt werden.\n");
					iErg = RemoveList(&Liste); // Speicherplatz freigeben
					return 1; // Programm abbrechen
				}
			}
		}
		else {
			switch ( i ) {
				case 3: // GetFirstNode
					PrintNode(GetFirstNode(&Liste));
					break;
				case 4: // GetLastNode
					if ( Liste.iAnzahl > 0 ) {
						PrintNode(GetLastNode(&Liste));
					}
					break;
				case 5: // GetSize
					printf("\n Anzahl der Knoten: %i\n", GetSize(&Liste));
					break;
				case 6:
					printf("\n Index des zu entfernenden Knotens: ");
					scanf("%i", &i);
					iErg = RemoveNode(&Liste, i);
					if ( iErg != 1 ) {
						printf("\n Fehler! Knoten kann nicht hinzugefuegt werden.\n");
						iErg = RemoveList(&Liste);
						return 1; // Programm abbrechen
					}
					break;
				case 7: // PrintList, Anzeigen der Listenelemente
					printf("\n Listenelemente:\n");
					printf(" ======================================================\n");
					PrintList(&Liste);
					printf("\n ======================================================\n");
					break;
				default:
					break;
			}
		}		
		printf("\n Wollen Sie weitermachen? Ja(1) Nein(0) ");
		scanf("%i", &i);
	} while ( i );
	
	// Loescht ganze Liste
	iErg = RemoveList(&Liste);
	
	if ( Liste.pFirst == NULL ) {
		printf("\n Bevor beendet wird, wurdne alle Knoten entfernt.");
		printf("\n Knotenanzahl: %i\n\n", GetSize(&Liste));
	}
	
	return 0;
}