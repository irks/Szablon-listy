// Wrobel Ireneusz, Informatyka, grupa 2I5
// Implementation of template class used to representing forward list
// Memory is allocated in blocks

// Interactive program to demonstrate features of SList

#include <iostream>

#include "SList.hpp"

int main() {
    const int LINES_NUMBER = 60;
	bool menu = true;
	int choice;
	int element;
	SList< int > list;
    Iterator< int > result;

	while( menu ) {

	    std::cout << std::endl << std::endl;
        std::cout << "===================================================================" << std::endl;
        std::cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << std::endl;
        std::cout << "1.  Dodac nowy element do listy" << std::endl;
        std::cout << "2.  Usunac element z listy " << std::endl;
        std::cout << "3.  Wyswietlic ilosc wezlow listy" << std::endl;
        std::cout << "4.  Liczba wszystkich elementow w liscie" << std::endl;
        std::cout << "5.  Wyswietlic baze" << std::endl;
        std::cout << "6.  Wyszukaj elementu o podanej wartosci" << std::endl;
        std::cout << "7.  Zapelnic liste elementami od -10 do 100" << std::endl;
        std::cout << "8.  Wyczyscic baze" << std::endl;
        std::cout << "9.  Wyjsc z programu" << std::endl;
        std::cout << "===================================================================" << std::endl;

        try {

            std::cin >> choice;

            if( std::cin.fail() ) 
                throw CinFail();

            for( int i = 0; i < LINES_NUMBER; ++i )
                std::cout << std::endl; //clearing the screen


            switch( choice ) {
            	case 1:
                    std::cout << "===================================================================" << std::endl;
                    std::cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << std::endl;
                    std::cout << "1. Dodac nowy element na poczatek listy" << std::endl;
                    std::cout << "2. Dodac nowy element na koniec listy" << std::endl;
                    std::cout << "3. Dodac nowy element na pierwsze wolne miejsce w liscie" << std::endl;
                    std::cout << "===================================================================" << std::endl;

                    std::cin >> choice;

                    if( std::cin.fail() ) 
                        throw CinFail();

                    switch( choice ) {
                        case 1:
                            std::cout << "Podaj wartosc:" << std::endl;
                            std::cin >> element;

                            if( std::cin.fail() ) 
                                throw CinFail();

                            list.push_front( element );
                            break;

                        case 2:

                            std::cout << "Podaj wartosc:" << std::endl;
                            std::cin >> element;

                            if( std::cin.fail() ) 
                                throw CinFail();

                            list.push_back( element );
                            break;

                        case 3:
                            std::cout << "Podaj wartosc:" << std::endl;
                            std::cin >> element;

                            if( std::cin.fail() ) 
                                throw CinFail();

                            list.pushInFirstEmpty( element );
                            break;

                        default:
                            std::cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << std::endl;
                            break;
                    }
                    break;

            	case 2:
                    std::cout << "===================================================================" << std::endl;
                    std::cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer" << std::endl;
                    std::cout << "1. Usunac element z poczatku listy" << std::endl;
                    std::cout << "2. Usunac element z konca listy" << std::endl;
                    std::cout << "3. Usunac element o podanej wartosci ( usuwa pierszy znaleziony element o tej wartosci )" << std::endl;
                    std::cout << "===================================================================" << std::endl;

                    std::cin >> choice;

                    if( std::cin.fail() ) 
                        throw CinFail();

                    switch( choice ) {
                        case 1:
                            list.pop_front();
                            break;

                        case 2:
                            list.pop_back();
                            break;

                        case 3:
                            std::cout << "Podaj wartosc elementu: " << std::endl;
                            std::cin >> element;

                            if( std::cin.fail() ) 
                                throw CinFail();

                            result = list.search( element );
                            list.erase( result );
                            break;

                        default:
                            std::cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << std::endl;
                            break;
                    }
                    break;

            	case 3:
                    std::cout << std::endl << "Liczba wezlow w liscie: " << list.size(); 
                    std::cout << std::endl;
                    break;

            	case 4:
            		std::cout << std::endl << "Liczba wszystkich elementow: " << list.sizeElementsInArrays(); 
                    std::cout << std::endl;
                    break;

            	case 5:
                    list.printList();
                    break;

            	case 6:
                    std::cout << "Podaj wartosc szukanego elementu: " << std::endl;
                    std::cin >> element;

                    if( std::cin.fail() ) 
                        throw CinFail();

                    result = list.search( element );
                    std::cout << "Znaleziono element " << (*result) << std::endl;
            		break;

            	case 7:
                    for(int i = -10; i < 100; ++i)
                        list.push_back(i);
                    break;

                case 8:
                    std::cout << "Czy na pewno chcesz wyczyscic baze?" << std::endl;
                    std::cout << "Jezeli tak, podaj '1', jezeli chcesz anulowac ta operacje podaj dowolny inny znak" << std::endl;
                    std::cin >> choice;

                    if( std::cin.fail() ) 
                        throw CinFail();

                    switch( choice ) {
                        case 1:
                            list.clear();
                            break;
                        default:
                            break;
                    }
                    break;

                case 9:
                    menu = false;
                    break;

            	default:
            		std::cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << std::endl;
                    break;
            } //switch
        } //try

        catch( CinFail &e ) {
            std::cerr << e.what();
        }
        catch( std::bad_alloc &e ) {
            std::cerr << e.what();
        }
        catch( EmptyList &e ) {
            std::cerr << e.what();
        }
        catch( LackElement &e) {
            std::cerr << e.what();
        }
        catch( ... ) {
            std::cerr << "Niespodziewany wyjatek";
        }
	} // while( menu )
} //main
