#ifndef MYEXCEPTIONS
#define MYEXCEPTIONS
class EmptyList : public std::logic_error {
    public:
        EmptyList( const std::string &s = "Lista jest pusta") : std::logic_error(s) {}
};

class LackElement : public std::logic_error {
    public:
        LackElement( const std::string &s = "Taki element nie istnieje" ) : std::logic_error(s) {}
};
#endif