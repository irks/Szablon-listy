#include <iostream>
#include "SList.hpp"
using namespace std;
int main() {
	bool menu = true;
	int choice;
	int element;
	SList< int > list;

	while( menu ) {

		    cout << endl << endl;
            cout << "===================================================================" << endl;
            cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << endl;
            cout << "1. Dodac nowy element" << endl;
//         cout << "2. Usunac element" << endl;
            cout << "3. Wyswietlic ilosc wezlow listy" << endl;
            cout << "4. Sprawdzic czy baza jest pusta" << endl;
            cout << "5. Wyczyscic baze" << endl;
            cout << "6. Wyswietlic baze" << endl;
            cout << "7. Wyjsc z programu" << endl;
            cout << "===================================================================" << endl;

            cin >> choice;

            try {

                switch( choice ) {
                	case 1:
                                // list.test();
        //                 cout << "===================================================================" << endl;
        //                 cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << endl;
        //                 cout << "1. Dodac nowy element na koniec listy" << endl;
        //                 cout << "2. Dodac nowy element na poczatek listy" << endl;
        //                 cout << "===================================================================" << endl;

        //                 cin >> choice;

        //                 switch( choice ) {
        //                     case 1:
                                cout << "Podaj wartosc" << endl;
                                cin >> element;
        //                         try {
                                    list.push_back( element );
        //                         }
        //                         catch( std::bad_alloc) {

        //                         }
        //                         break;
        //                     case 2:
        //                         cout << "Podaj wartosc" << endl;
        //                         cin >> element;
        //                         try {
        //                             lista.push_front( element );
        //                         }
        //                         catch( std::bad_alloc) {

        //                         }
        //                         break;
        //                     default:
        //                         cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl;
        //                         break;
        //                 }

                        break;

                	case 2:
        //         		cout << "===================================================================" << endl;
        //                 cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << endl;
        //                 cout << "1. Usunac element z poczatku listy" << endl;
        //                 cout << "2. Usunac element z konca listy" << endl;
        //                 cout << "===================================================================" << endl;
                            for(int i = 0; i < 26; ++i)
                                list.push_back(i);
        //                 cin >> wybor;

        //                 switch( wybor ) {
        //                     case 1:
        //                         try {
        //                             lista.pop_back();
        //                         }
        //                         catch( ) {

        //                         }
        //                         break;
        //                     case 2:
        //                         try {
        //                             lista.pop_front();
        //                         }
        //                         catch( ) {

        //                         }
        //                         break;
        //                     default:
        //                         cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl;
        //                         break;
        //                 }

                        break;

                	case 3:
                		cout << endl << "Liczba wezlow w liscie: " << list.size(); cout << endl;
                        break;
                	case 4:
                		if ( list.empty() )
                            cout << "Baza pusta" << endl;
                        else
                            cout << "Baza nie jest pusta" << endl;
                        break;
                	case 5:
                            list.clear();
                        break;
                	case 6:
                                list.printList();
                		break;
                	case 7:
                        menu = false;
                        break;
                    case 8:
                        cout << endl << "Liczba wszystkich elementow: " << list.sizeElementsInArrays(); cout << endl;
                        break;
                	default:
                		cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl;
                        break;
                } //switch
            } //try
            catch( EmptyList &e ) {
                std::cerr << e.what();
            }
            catch( LackElement &e) {
                std::cerr << e.what();
            }
            catch( IteratorIndex &e ) {
               std::cerr << e.what();
            }
            catch( ... ) {
                std::cerr << "Niespodziewany wyjatek";
            }
	}
}
