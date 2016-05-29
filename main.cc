#include <iostream>

#include "SList.hpp"

int main() {
	bool menu = true;
	int choice;
	int element;
	SList< int > list;
    SList< int > list2;  
    Iterator< int > result;

	while( menu ) {

	    std::cout << std::endl << std::endl;
        std::cout << "===================================================================" << std::endl;
        std::cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << std::endl;
        std::cout << "1.  Dodac nowy element na koniec listy" << std::endl;
        std::cout << "2.  Dodaj nowy element na pierwsze wolne miejsce w liscie " << std::endl;
        std::cout << "3.  Usunac element z konca listy " << std::endl;
        std::cout << "4.  Usun element o podanej wartosci ( usuwa pierszy znaleziony element o tej wartosci )" << std::endl;
        std::cout << "5.  Wyswietlic ilosc wezlow listy" << std::endl;
        std::cout << "6.  Liczba wszystkich elementow w liscie" << std::endl;
        std::cout << "7.  Wyswietlic baze" << std::endl;
        std::cout << "8.  Wyszukaj elementu o podanej wartosci" << std::endl;
        std::cout << "9.  Wyczyscic liste i aapelnic ja elementami od -10 do 100" << std::endl;
        std::cout << "10. Wyczyscic baze " << std::endl;
        std::cout << "11. Wyjsc z programu" << std::endl;
        std::cout << "===================================================================" << std::endl;

        std::cin >> choice;

        try {
            
            switch( choice ) {
            	case 1:
                    std::cout << "Podaj wartosc" << std::endl;
                    std::cin >> element;
                    list.push_back( element );
                    break;

            	case 2:
                    std::cout << "Podaj wartosc" << std::endl;
                    std::cin >> element;
                    list.pushInFirstEmpty( element );
                    break;

            	case 3:
                    list.pop_back();
                    break;

            	case 4:
            		std::cout << "Podaj wartosc" << std::endl;
                    std::cin >> element;
                    result = list.search( element );
                    list.erase( result );
                    break;

            	case 5:
                    std::cout << std::endl << "Liczba wezlow w liscie: " << list.size(); std::cout << std::endl;
                    break;

            	case 6:
                    std::cout << std::endl << "Liczba wszystkich elementow: " << list.sizeElementsInArrays(); std::cout << std::endl;
            		break;

            	case 7:
                    list.printList();
                    break;

                case 8:
                    std::cin >> choice;
                    result = list.search( choice );
                    std::cout << (*result) << std::endl;
                    break;

                case 9:
                    for(int i = -10; i < 100; ++i)
                        list.push_back(i);
                    break;

                case 10:
                    list.clear();
                    break;

                case 11:
                    menu = false;
                    break;

            	default:
            		std::cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << std::endl;
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
	} // while( menu )
} //main
