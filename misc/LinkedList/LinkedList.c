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
typedef struct { // anonymous struct
	char szBezeichnung[MAX];
	int iWert;
	struct KNOTEN *pNext; // forward-declaration
} KNOTEN;

typedef struct {
	KNOTEN *pFirst;
	int iAnzahl;
} LISTE;

/*
 * Erzeugt und initialisiert eine leere Liste
 */
LISTE* Initialize() {
	LISTE *pListe = (LISTE *) malloc(sizeof(LISTE));
	//(*pListe).pFirst = NULL
	pListe->pFirst = NULL;
	pListe->iAnzahl = 0;
	return pListe;
}

/*
 * Returns the number of all nodes in linked list.
 */
int GetSize(LISTE *Liste) {
	return Liste->iAnzahl;
}

/*
 * Creates a new node and assigns the values.
 */
KNOTEN * CreateNode(char szBezeichnung[], int iWert) {
	KNOTEN *pKnoten = (KNOTEN *) malloc(sizeof(KNOTEN));
	pKnoten->pNext = NULL;
	// Werte zuweisen
	strcpy(pKnoten->szBezeichnung, szBezeichnung); // String kopieren
	//strncpy(pKnoten->szBezeichnung, szBezeichnung, strlen(szBezeichnung)+1); +1 bedeutet \0 (String-Ende)
	pKnoten->iWert = iWert;
	return pKnoten;
}

/*
 * Returns the pointer to the first node of linked list.
 */
KNOTEN * GetFirstNode (LISTE * Liste) {
	return Liste->pFirst;
}

/*
 * Returns the pointer to the last node of linked list.
 * If the list is empty (no node exists), the pointer to list is returned.
 * One may have to cast from generic type (void *) to specific type as (KNOTEN *) or (LISTE *).
 */
void * GetLastNode (LISTE * Liste) {
	if ( Liste == NULL ) return NULL;
	//if ( Liste->pFirst == NULL ) return Liste;
	if ( Liste->iAnzahl == 0 ) return Liste;
	KNOTEN *pKnoten = Liste->pFirst;
	while ( pKnoten->pNext != NULL ) {
		pKnoten = (KNOTEN *) pKnoten->pNext;
	}
	return pKnoten;
}
 
/*
 * Inserts a new node (Knoten) at the end of linked list.
 *
 * Return value:
 *   -1 (FALSE) if no node can be inserted
 *    1 (TRUE)  if new node has been inserted successfully
 */
int InsertAtEnd(LISTE * Liste, char szBezeichnung[], int iWert) {
	if ( Liste == NULL ) return -1; // FALSE
	
	KNOTEN *pKnoten = NULL, *pLast = NULL;
	
	// Neuen Knoten erzeugen und Werte zuweisen
	pKnoten = CreateNode(szBezeichnung, iWert);
	
	// Knoten in die Liste (am Ende) einfuegen
	if ( Liste->iAnzahl == 0 ) {
		Liste->pFirst = pKnoten;
	} 
	else {
		pLast = (KNOTEN *)GetLastNode(Liste);
		pLast->pNext = (struct KNOTEN *) pKnoten;
	}	
	
	// Inkrementiert Knotenzahl
	Liste->iAnzahl += 1;
	
	return 1; // TRUE
}

/*
 * Inserts a new node (Knoten) in first position of linked list.
 *
 * Return value:
 *   -1 (FALSE) if no node can be inserted
 *    1 (TRUE)  if new node has been inserted successfully
 */
int InsertAtBegin(LISTE * Liste, char szBezeichnung[], int iWert) {
	if ( Liste == NULL ) return -1; // FALSE
	
	// Neuen Knoten erzeugen und Werte zuweisen
	KNOTEN *pKnoten = CreateNode(szBezeichnung, iWert);
	
	// Knoten in die Liste einfuegen
	pKnoten->pNext = (struct KNOTEN *) Liste->pFirst;
	Liste->pFirst = pKnoten;
	
	// Inkrementiert Knotenzahl
	Liste->iAnzahl += 1;
	
	return 1; // TRUE
}

/*
 * Removes a node with specified index from list.
 * First node has index 0. Last node has index n-1.
 *
 * Return value:
 *   -1 (FALSE) if no node can be removed
 *    1 (TRUE)  if the specified node has been removed successfully
 */
int RemoveNode(LISTE * Liste, int iIndex) {
	if ( Liste == NULL || Liste->pFirst == NULL ) return -1; // FALSE
	if ( iIndex >= Liste->iAnzahl || iIndex < 0 ) return -1;
	
	int i = 0;
	KNOTEN * pKnoten = Liste->pFirst;
	KNOTEN * pTemp = NULL;
	
	if ( iIndex == 0 ) {
		Liste->pFirst = (KNOTEN *) pKnoten->pNext;
		free(pKnoten);
	} else {
		while ( i++ < iIndex-1 ) {
			pKnoten = (KNOTEN *) pKnoten->pNext;
		}
		pTemp = (KNOTEN *) pKnoten->pNext;
		pKnoten->pNext = pTemp->pNext;
		free(pTemp);
	}
	
	Liste->iAnzahl -= 1;
	
	return 1; // TRUE
}

/*
 * Prints the content of a node
 */
void PrintNode(KNOTEN *pKnoten) {
	printf("\n Inhalt: (%s,%i)\n", pKnoten->szBezeichnung, pKnoten->iWert);
}

/*
 * Prints all list elements
 */
void PrintList(LISTE * Liste) {
	if ( Liste == NULL || Liste->pFirst == NULL ) return;
	KNOTEN *pKnoten = Liste->pFirst;
	printf("  first : ");
	do {
		printf(" (%s,%i) ->", pKnoten->szBezeichnung, pKnoten->iWert);
		pKnoten = (KNOTEN *) pKnoten->pNext;
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
	printf("\n Leere Liste wurde initialisiert.");
	LISTE * Liste = Initialize();	
	printf("\n Knotenanzahl: %i\n", GetSize(Liste));
	
	do {	
		fprintf(stdout, "\n Aktionen zum Ausfuehren:\n");
		fprintf(stdout, "  (1) InsertAtBegin     (2) InsertAtEnd\n");
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
				printf(" Knoten %1i: ", j+1);
				fscanf(stdin, "%s" "%i", szBezeichnung, &iWert);
				iErg = ( i == 1 ) ? InsertAtBegin(Liste, szBezeichnung, iWert) : InsertAtEnd(Liste, szBezeichnung, iWert);
				if ( iErg != 1 ) {
					printf("\n Fehler! Knoten kann nicht hinzugefuegt werden.\n");
					free(Liste); // Speicherplatz freigeben
					return 1; // Programm abbrechen
				}
			}
		}
		else {
			switch ( i ) {
				case 3: // GetFirstNode
					PrintNode(GetFirstNode(Liste));
					break;
				case 4: // GetLastNode
					if ( Liste->iAnzahl > 0 ) {
						PrintNode((KNOTEN *)GetLastNode(Liste));
					}
					break;
				case 5: // GetSize
					printf("\n Anzahl der Knoten: %i\n", GetSize(Liste));
					break;
				case 6:
					printf("\n Index des zu entfernenden Knotens: ");
					scanf("%i", &i);
					iErg = RemoveNode(Liste, i);
					if ( iErg != 1 ) {
						printf("\n Fehler! Knoten kann nicht hinzugefuegt werden.\n");
						free(Liste); // Speicherplatz freigeben
						return 1; // Programm abbrechen
					}
					break;
				case 7: // PrintList, Anzeigen der Listenelemente
					printf("\n Listenelemente:\n");
					printf(" ======================================================\n");
					PrintList(Liste);
					printf("\n ======================================================\n");
					break;
				default:
					free(Liste);
					return 0;
					break;
			}
		}
		
		printf("\n Wollen Sie weitermachen? Ja(1) Nein(0) ");
		scanf("%i", &i);
	} while ( i );
	
	// Speicherplatz freigeben
	free(Liste);
	
	return 0;
}