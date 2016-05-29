#include <iostream>
#include "Iterator.hpp"
#include "MyExceptions.hpp"
const int ARRAY_MAX_SIZE = 8;
template < class T >
class SList {
private:
	Node< T >* head;
	Node< T >* tail;
	int NodesCount;
public:
	SList() : head( nullptr ), tail( nullptr ), NodesCount( 0 ) {}
	SList< T >& operator = ( SList< T >& );
	SList( const SList< T >& );
	~SList() ;
// 	void push_front( T& );
	void pop_front();
	void push_back( T& );
	void pop_back();
// 	void insert_after( Iterator< T >, const T & );
	void erase( Iterator< T > );
	int sizeElementsInArrays() const;
	int size() const;
	bool empty() const;
	void clear();
	Iterator< T > search( T& );
// 	Node< T >& front() const; //do usuniecia
// 	Node< T >& back() const;
	Iterator< T > begin();
	Iterator< T > end();
	void printList();
	void pushInFirstEmpty( T& );
};

template < class T >
SList< T >::~SList()  {
	clear();
}

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
	if ( tail -> getAmountOfElements() < ARRAY_MAX_SIZE ) 
		tail-> setDataInArray( d, tail-> getAmountOfElements() );
	else {
		Node< T >* newTail = new Node< T >();
		tail -> setNextNode( newTail );
		
		newTail-> setDataInArray( d );
		tail = newTail;
		++NodesCount;
	}
}

template < class T >
void SList< T >::pop_back() {
	if ( empty() )
		throw EmptyList();
	if( begin() == end() ) {
		delete tail;
		head = nullptr;
		tail = nullptr;
		--NodesCount;
	}
	else if ( tail-> deleteElement( *end() ) == 0 ) {
		Node< T >* current = head;
		Node< T >* previous = nullptr;
		while ( current != tail ) {
			previous = current;
			current = current-> getNextNode();
		}
		delete tail;
		tail = previous;
		tail-> setNextNode( nullptr );
		--NodesCount;
	}
}

template < class T >
SList< T >::SList( const SList< T >& source ) : NodesCount( 0 ), head( nullptr ), tail( nullptr ) {
	Iterator< T > it;
	it = source.head;
	for ( ; it != nullptr; ++it )
		this-> push_back( *it );
}

template < class T >
SList< T >& SList< T >::operator = ( SList < T > & source ) { //ZLE DZIALA JEZELI JEST COS USUNIETE Z SRODKA
	if ( this != &source ) {
		clear();
		Iterator< T > it;
		it = (source.begin());
		for ( ;it != nullptr; ++it ) {
			this-> push_back( *it );
		}
	}
	return *this;
}

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

template < class T >
Iterator< T > SList< T >::search( T& demanded ) {
	if( empty() )
        throw EmptyList();

	Iterator< T > it; 
	it =  begin();
	
	for( ; it != end(); ++it ) { //JEZELI NIE ZNAJDZIE 
		if( *it == demanded ) {
			return it;
		}
	}
	if( *it == demanded ) {
		return it;
	}
	else
		throw LackElement();
}

template < class T >
void SList< T >::pushInFirstEmpty( T& d ) {
	Node< T >* current = head;
	while( ( current != nullptr ) && ( current-> getAmountOfElements() == ARRAY_MAX_SIZE ) ) {
		current = (current-> getNextNode());
	}
	if ( current == nullptr ) 
		push_back( d );
	else
		current-> setDataInArray( d, current-> getAmountOfElements() );
	return;
}

template < class T >
void SList< T >::erase( Iterator< T > position ) {
	if ( empty() )
			throw EmptyList();
	if( position == end() ) 
		pop_back();	
	else  {
		Node< T >* positionNode = position.getNode();
		if ( positionNode-> getAmountOfElements() == 1 ) {
			Node< T >* current = head;
			Node< T >* previous = nullptr;
			while ( current != positionNode ) {
				previous = current;
				current = current-> getNextNode();
			}
			previous-> setNextNode( positionNode-> getNextNode() );
			delete positionNode;
			--NodesCount;
		}
		else {
			Iterator< T > current = position;
			++current;
			Iterator< T > previous = position;
			while( current.getNode() == positionNode ) {
				previous = current;
				++current;
			}
			*position = *previous;
			positionNode-> deleteElement( *previous );
		}
	}
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

template < class T >
void SList< T >::pop_front() {
	erase( begin() );
}

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