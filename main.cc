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
        cout << "1. Dodac na koniec" << endl;
        cout << "2. Dodac na poczatek" << endl;
        cout << "3. Usunac z konca" << endl;
        cout << "4. Usunac z poczatku" << endl;
        cout << "5. Ilosc elementow" << endl;
        cout << "6. Czy baza jest pusta?" << endl;
        cout << "7. Wyczyscic baze" << endl;
        cout << "8. Wyswietlic baze" << endl;
        cout << "9. Wyjsc z programu" << endl;
        cout << "===================================================================" << endl;

        cin >> wybor;

        switch( wybor ) {
        	case 1:
        		cout << "Podaj wartosc" << endl;
                cin >> element;
                lista.push_back( element );
                break;
        	case 2:
        		cout << "Podaj wartosc" << endl;
                cin >> element;
                lista.push_front( element );
                break;
        	case 3:
        		lista.pop_back();
        		break;
        	case 4:
        		lista.pop_front();
        		break;
        	case 5: 
        		cout << lista.size(); cout << endl;
        	case 6:
        		if ( lista.empty() )
        			cout << "Baza pusta" << endl;
        		else
        			cout << "Baza nie jest pusta" << endl;
        		break;
        	case 7:
        		lista.clear();
        	case 8:
        		//cout << lista.begin(); cout << endl;
        		break;
        	case 9:
        		lista.clear();

        		menu = false;
        		break;
        	default:
        		cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl;
                break;
        }
	}
}