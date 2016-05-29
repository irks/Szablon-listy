#include <iostream>

#include "Node.hpp"
#include "MyExceptions.hpp"

extern const int ARRAY_MAX_SIZE ;

template < typename T >
class Iterator {

	private:
		Node< T >* pointer;
		int positionInArray;

	public:
		Iterator< T >( Node< T >* = nullptr, const int = 0 );
 		Iterator< T >( const Iterator< T >& );
 		void operator = ( const Iterator& );
 		bool operator != ( const Iterator& ) const;
 		bool operator == ( const Iterator& ) const;
		Iterator< T >& operator ++ ();
 		Iterator< T > operator ++ ( int );
		T& operator * ();
		T operator * () const;
		Node< T >* getNode() const;
};

template < typename T >
Iterator< T >::Iterator( Node< T >* ptr, const int position ) : pointer( ptr ), positionInArray( position ) {}

template < typename T >
Iterator< T >::Iterator( const Iterator< T >& source ) : pointer( source.pointer ), positionInArray( source.positionInArray ) {}

template < typename T >
void Iterator< T >::operator = ( const Iterator< T >& source ) {
	pointer = source.pointer;
	positionInArray = source.positionInArray;
}

template < typename T >
bool Iterator< T >::operator != ( const Iterator& it2 ) const {
	bool pointersEqual = pointer == it2.pointer;
	bool positionsEqual = positionInArray == it2.positionInArray;
	return ( ! ( pointersEqual && positionsEqual ) );
}

template < typename T >
bool Iterator< T >::operator == ( const Iterator& it2 ) const {
	return ( pointer == it2.pointer ) && ( positionInArray == it2.positionInArray);
}

template < typename T >
Iterator< T >& Iterator< T >::operator ++() {
	if( positionInArray < ( pointer->getAmountOfElements() - 1 ) ) 
		++positionInArray;
	else {
		pointer = pointer-> getNextNode();
		positionInArray = 0;
 	}
	return *this;
}

template < typename T >
Iterator< T > Iterator< T >::operator ++ ( int ) {
	Iterator< T > tmp(*this);
	operator++();
	return tmp;
}

template < typename T >
T& Iterator< T >::operator * () {
	return pointer-> getData( positionInArray );
}

template < typename T >
T Iterator< T >::operator * () const {
	return pointer-> getData( positionInArray );
}

template < typename T >
Node< T >* Iterator< T >::getNode() const {
	return pointer;
}