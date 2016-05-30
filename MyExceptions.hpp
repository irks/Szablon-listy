#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class EmptyList : public std::logic_error {
    public:
        EmptyList( std::string const &s = "Lista jest pusta") : std::logic_error(s) {}
};

class LackElement : public std::logic_error {
    public:
        LackElement( std::string const &s = "Taki element nie istnieje" ) : std::logic_error(s) {}
};
#endif