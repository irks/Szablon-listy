// Wrobel Ireneusz, Informatyka, grupa 2I5
// Implementation of template class used to representing forward list
// Memory is allocated in blocks

// Iterator is used to move easier in the list.
// This class has pointer to Node in which this Iterator is.
// Also it has number representing position in array in which this Iterator is.
// 											( array is an attribute of Node )

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"

extern const int ARRAY_MAX_SIZE ;

template < typename T >
class Iterator {

	private:
		Node< T >* pointer_;
		int positionInArray_;

	public:
		Iterator< T >( Node< T >* = nullptr, const int = 0 );
 		Iterator< T >( const Iterator< T >& );
 		void operator = ( const Iterator& );
 		bool operator != ( const Iterator& ) const;
 		bool operator == ( const Iterator& ) const;
		Iterator< T >& operator ++ ();
 		Iterator< T > operator ++ ( int );
		T& operator * (); // operator * is returning T value
		T operator * () const;
		Node< T >* getNode() const;
};

template < typename T >
Iterator< T >::Iterator( Node< T >* ptr, const int position ) : pointer_( ptr ), positionInArray_( position ) {}

template < typename T >
Iterator< T >::Iterator( const Iterator< T >& source ) : pointer_( source.pointer_ ), positionInArray_( source.positionInArray_ ) {}

template < typename T >
void Iterator< T >::operator = ( const Iterator< T >& source ) {
	pointer_ = source.pointer_;
	positionInArray_ = source.positionInArray_;
}

template < typename T >
bool Iterator< T >::operator != ( const Iterator& it2 ) const {
	bool pointersEqual = pointer_ == it2.pointer_;
	bool positionsEqual = positionInArray_ == it2.positionInArray_;
	return ( ! ( pointersEqual && positionsEqual ) );
}

template < typename T >
bool Iterator< T >::operator == ( const Iterator& it2 ) const {
	return ( pointer_ == it2.pointer_ ) && ( positionInArray_ == it2.positionInArray_);
}

template < typename T >
Iterator< T >& Iterator< T >::operator ++() {
	if( positionInArray_ < ( pointer_->getAmountOfElements() - 1 ) ) //if Iterator isn't pointing to the last element in the array
		++positionInArray_;
	else { // if Iterator is pointing to the last element in the array
		pointer_ = pointer_-> getNextNode();
		positionInArray_ = 0;
 	}
	return *this;
}

template < typename T >
Iterator< T > Iterator< T >::operator ++ ( int ) { //post-increment
	Iterator< T > tmp(*this);
	operator++();
	return tmp;
}

template < typename T >
T& Iterator< T >::operator * () {
	return pointer_-> getData( positionInArray_ );
}

template < typename T >
T Iterator< T >::operator * () const {
	return pointer_-> getData( positionInArray_ );
}

template < typename T >
Node< T >* Iterator< T >::getNode() const {
	return pointer_;
}
#endif