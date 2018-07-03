/**
 * Person.cpp
 *
 * Compile:   g++ Person.cpp -o Person
 */
#include <iostream>
#include <cstring>
#define STRSIZE 81
using namespace std;

/*
 *
 */
class Person
{
	private:
		char szName[STRSIZE] = "Mustermann";
		int iGeburtsjahr;
	public:
		Person() { // Konstruktor
			// this ist ein Pointer auf das Objekt, das diesen Konstruktor aufruf
			this->iGeburtsjahr = 0; // (*this).iGeburtsjahr = 0
		}		
		void setName(char * szName) {
			strcpy(this->szName, szName);
		}
		void setGeburtsjahr(int iGeburtsjahr) {
			this->iGeburtsjahr = iGeburtsjahr;
		}
		char * getName() {
			return szName;
		}
		int getGeburtsjahr() {
			return iGeburtsjahr;
		}
};

/*
 *
 */
void printName(char * szName, int iLen) {
	for ( int i = 0; i < iLen; i++ ) {
		cout << *(szName+i);
	}
	cout << "  (mit cout)" << endl;
}

/*
 *
 */
int main () {
	
	char strTest[] = "\n Das ist ein Test String."; // (*)
	cout << strTest << endl; // Durch Deklaration wie in (*) wird das '\0' Zeichen automatisch hinzugefuegt.
	                         // Dann weisst cout, bis wo aufgehoert werden soll.
	
	Person person;
	
	cout << "\n Ein Objekt Person wurde erstellt." << endl;	
	printf("    Person.Name :        %s  (mit printf)\n", person.getName());	
	cout << "    Person.Name :        ";
	printName(person.getName(), strlen(person.getName()));	
	cout << "    Person.Geburtsjahr : " << person.getGeburtsjahr() << endl;
	
	char szNewName[] = "LaOla";
	person.setName(szNewName);
	person.setGeburtsjahr(1980);
	
	cout << "\n Dem Objekt Person wurden neue Werte zugewiesen." << endl;
	printf("    Person.Name :        %s  (mit printf)\n", person.getName());
	cout << "    Person.Name :        ";
	printName(person.getName(), strlen(person.getName()));	
	cout << "    Person.Geburtsjahr : " << person.getGeburtsjahr() << endl;
	
	return 0;
}
 