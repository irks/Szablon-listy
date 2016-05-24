#include <iostream>
#include "SinglyLinkedList.hpp"
using namespace std;
int main() {
	bool menu = true;
	int wybor;
	int element;
	SinglyLinkedList< int > lista;

	while( menu ) {

		cout << endl << endl;
        cout << "===================================================================" << endl;
        cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << endl;
        cout << "1. Dodac nowy element" << endl;
        cout << "2. Usunac element" << endl;
        cout << "3. Wyswietlic ilosc elementow" << endl;
        cout << "4. Sprawdzic czy baza jest pusta" << endl;
        cout << "5. Wyczyscic baze" << endl;
        cout << "6. Wyswietlic baze" << endl;
        cout << "7. Wyjsc z programu" << endl;
        cout << "===================================================================" << endl;

        cin >> wybor;

        switch( wybor ) {
        	case 1:
                cout << "===================================================================" << endl;
                cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << endl;
                cout << "1. Dodac nowy element na koniec listy" << endl;
                cout << "2. Dodac nowy element na poczatek listy" << endl;
                cout << "===================================================================" << endl;

                cin >> wybor;

                switch( wybor ) {
                    case 1:
                        cout << "Podaj wartosc" << endl;
                        cin >> element;
                        try {
                            lista.push_back( element );
                        }
                        catch( std::bad_alloc) {

                        }
                        break;
                    case 2:
                        cout << "Podaj wartosc" << endl;
                        cin >> element;
                        try {
                            lista.push_front( element );
                        }
                        catch( std::bad_alloc) {
                            
                        }
                        break;
                    default:
                        cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl;
                        break;
                }               
		
                break;

        	case 2:
        		cout << "===================================================================" << endl;
                cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << endl;
                cout << "1. Usunac element z poczatku listy" << endl;
                cout << "2. Usunac element z konca listy" << endl;
                cout << "===================================================================" << endl;

                cin >> wybor;

                switch( wybor ) {
                    case 1:
                        try {
                            lista.pop_back();
                        }
                        catch( std::bad_alloc) {
                            
                        }
                        break;
                    case 2:
                        try {
                            lista.pop_front();
                        }
                        catch( std::bad_alloc) {
                            
                        }
                        break;
                    default:
                        cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl;
                        break;
                }

                break;

        	case 3:
        		cout << endl << "Liczba elementow: " << lista.size(); cout << endl;
        		break;
        	case 4:
        		if ( lista.empty() )
                    cout << "Baza pusta" << endl;
                else
                    cout << "Baza nie jest pusta" << endl;
                break;
        	case 5: 
                try {
                    lista.clear();
                }
                catch( std::bad_alloc) {
                            
                }
                break;
        	case 6:
                lista.printList();
        		break;
        	case 7:
                try {
                    lista.clear();
                }
                catch( std::bad_alloc) {
                            
                }
                menu = false;
                break;
        	default:
        		cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl;
                break;
        }
	}
}