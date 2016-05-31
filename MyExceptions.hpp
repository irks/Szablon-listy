// Wrobel Ireneusz, Informatyka, grupa 2I5
// Implementation of template class used to representing forward list
// Memory is allocated in blocks

// Exceptions classes

#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <limits>

class EmptyList : public std::logic_error {
    public:
        EmptyList( std::string const &s = "Lista jest pusta") : std::logic_error( s ) {}
};

class LackElement : public std::logic_error {
    public:
        LackElement( std::string const &s = "Taki element nie istnieje" ) : std::logic_error( s ) {}
};

class CinFail : public std::logic_error {
	public:
		CinFail( std::string const &s = "Musisz podac odpowiedni numer!") : std::logic_error( s ) {
			std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<int>::max(),'\n'); //clearing the cin buffer
		}
};
#endif