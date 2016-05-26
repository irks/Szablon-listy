#include <iostream>

#include "Iterator.hpp"
#include "MyExceptions.hpp"

const int ARRAY_MAX_SIZE = 5;

template < class T >
class SList {
private:
	Node< T >* head;
	Node< T >* tail;
	int NodesCount;
public:
	SList() : head( nullptr ), tail( nullptr ), NodesCount( 0 ) {}
// 	SList< T >& operator = ( const SList< T >& );
// 	SList( const SList< T >& );
	~SList() noexcept { 
		clear();
	}
// 	void push_front( T& );
// 	void pop_front();
	void push_back( T& );
	// void pop_back();
// 	void insert_after( Iterator< T >, const T & );
// 	void erase_after( Iterator< T > position );
	int sizeElementsInArrays() const;
	int size() const;
	bool empty() const;
	// void test();
	void clear();
// 	Node< T >& front() const; //do usuniecia
// 	Node< T >& back() const;
	Iterator< T > begin();
	Iterator< T > end();
	void printList();
};
// template < class T >
// void SList< T >::test() {
// 	Iterator< T > it;
// 	it = begin();
// 	std::cout << (it != end()) << std::endl;
// 	while(!(it==end())) {
// 		std::cout << !(it == end()) << std::endl;
// 		++it;
// 	}

// 	head = new Node< T >( );
// 	head -> setNextNode( new Node< T >( ) );
// 	Iterator< T > it;
// 	it = Iterator< T >( head );
// 	++it;
// 	std::cout << *it << std::endl;
// }
// template < class T >
// SList< T >::~SList() noexcept {
// 	clear();
// 	delete this;
// }

template < class T >
Iterator< T > SList< T >::begin() {
	return Iterator< T >( head );
}

template < class T >
Iterator< T > SList< T >::end() { // nullptr
	return Iterator< T >( tail, (tail->getAmountOfElements()-1) );
}

template < class T >
int SList< T >::sizeElementsInArrays() const {
	Node< T >* current = head;
	int elementsCount = 0;
	while( current != nullptr ) {
		elementsCount += current-> getAmountOfElements();
		current = (current-> getNextNode());
	}
	return elementsCount;
}

// template < class T >
// void SList< T >::push_front( T& d ) {
// 	Node< T >* newHead = new Node< T >( d, head );

// 	if ( this-> empty() ) {
// 		head = newHead;
// 		tail = newHead;
// 	}
// 	else
// 		head = newHead;
// 	++count;
// }

// template < class T >
// void SList< T >::pop_front() {

//     if( empty() )
//         throw EmptyList();

// 	Node< T >* oldHead = head;

// 	if ( size() == 1 ) {
// 		head = nullptr;
// 		tail = nullptr;
// 	}
// 	else
// 		head = head-> getNext();
// 	delete oldHead;
// 	--count;
// }

template < class T >
void SList< T >::push_back( T& d ) {
	if ( this-> empty() ) {
		Node< T >* newTail = new Node< T >();
		newTail-> setDataInArray( d );
		head = newTail;
		tail = newTail;
		
		++NodesCount;
		return;
	}
	if ( tail -> getAmountOfElements() < ARRAY_MAX_SIZE ) {
		tail-> setDataInArray( d, tail-> getAmountOfElements() );
		
	}
	else {
		Node< T >* newTail = new Node< T >();
		tail -> setNextNode( newTail );
		
		newTail-> setDataInArray( d );
		tail = newTail;
		++NodesCount;
	}
	

// 	if ( this-> empty() )
// 		head = newTail;

// 	tail = newTail;
// 	++count;
}

// template < class T >
// void SList< T >::pop_back() {

// 	Node< T >* oldTail = tail;

// 	if( begin() == end() ) {
// 		head = nullptr;
// 		tail = nullptr;
// 	}
// 	else {
// 		Node< T >* current = head;
// 		while( current-> getNext() != tail)
// 			current = current-> getNext();
// 		current->setNextNode( nullptr );
// 		tail = current;
// 	}

// 	delete oldTail;
// 	--count;
// }

// template < class T >
// SList< T >::SList( const SList< T >& source ) : count( 0 ), head( NULL ), tail( NULL ) {
// 	Node< T >* current = source.head;
// 	while( current != nullptr ) {
// 		this-> push_back( current-> data );
// 		current = current-> getNext();
// 	}
// }

// template < class T >
// SList< T >& SList< T >::operator = ( const SList < T > & source ) {
// 	if ( this != &source ) {
// 		clear();
// 		for( Node< T >* current = source.head; current != nullptr; current = current-> getNext() )
// 			push_back( current-> data );
// 	}
// 	return *this;
// }

template < class T >
void SList< T >::clear() {
    if( empty() ) 
        throw EmptyList();
    Node< T >* oldHead;
	for( ; head != nullptr; ) {
		oldHead = head;
		if ( this-> size() == 1 ) {
			head = nullptr;
			tail = nullptr;
		}
		else
			head = head-> getNextNode();
		delete oldHead;
	}
	NodesCount = 0;
		
}

template < class T >
bool SList< T >::empty() const {
	return NodesCount == 0;
}

template < class T >
int SList< T >::size() const {
	return NodesCount;
}

// template < class T >
// Node< T >& SList< T >::front() const {
// 	return *head;
// }

// template < class T >
// Node< T >& SList< T >::back() const {
// 	return *tail;
// }

// template < class T >
// void SList< T >::insert_after( Iterator< T > position, const T & value ) {
// 	Node< T >* newNode = new Node< T >( value, position.ptr-> getNext );
// 	if ( position == end() )
// 		tail = newNode;
// 	position.ptr-> setNextNode( newNode );
// }

// template < class T >
// void SList< T >::erase_after( Iterator< T > position ) {
// 	if ( position == end() )
// 		return;
// 	Node< T >* toDelete = ++position.ptr;
// 	Node< T >* nextOfDeleted = toDelete-> getNext();
// 	position.ptr-> setNextNode( nextOfDeleted );
// 	if( toDelete == back() )
// 		tail = position.ptr;
// 	delete toDelete;
// }

template < class T >
void SList< T >::printList() {
    if( empty() )
        throw EmptyList();

	Iterator< T > it;
	it = begin();
	
	for( ; it != end() ;  ++it  ) 
		std::cout << *it << std::endl;
	std::cout << *it << std::endl;
	return;
}

// //search
