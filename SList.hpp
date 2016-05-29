#include <iostream>
#include "Iterator.hpp"
#include "MyExceptions.hpp"
const int ARRAY_MAX_SIZE = 8;
template < typename T >
class SList {

	private:
		Node< T >* head;
		Node< T >* tail;
		int NodesCount;

	public:
		SList() : head( nullptr ), tail( nullptr ), NodesCount( 0 ) {}
		SList( const SList< T >& );
		SList< T >& operator = ( SList< T >& );
		~SList() noexcept { clear(); };
		Iterator< T > begin();
		Iterator< T > end();
		int size() const;
		int sizeElementsInArrays() const;
		bool empty() const;
		void printList(); //do while
		void push_back( const T& );
		void pop_back();
		void pop_front();
		void erase( Iterator< T > );
		void clear();
		void pushInFirstEmpty( const T& );
		Iterator< T > search( const T& );		
};

template < typename T >
SList< T >::SList( const SList< T >& source ) : NodesCount( 0 ), head( nullptr ), tail( nullptr ) {
	Iterator< T > it;
	it = source.head;
	for ( ; it != nullptr; ++it )
		this-> push_back( *it );
}

template < typename T >
SList< T >& SList< T >::operator = ( SList < T > & source ) { //ZLE DZIALA JEZELI JEST COS USUNIETE Z SRODKA
	if ( this != &source ) {
		clear();
		Iterator< T > it;
		it = source.begin();
		for ( ; it != nullptr; ++it ) {
			this-> push_back( *it );
		}
	}
	return *this;
}

template < typename T >
Iterator< T > SList< T >::begin() {
	return Iterator< T >( head );
}

template < typename T >
Iterator< T > SList< T >::end() {
	return Iterator< T >( tail, (tail->getAmountOfElements()-1) );
}

template < typename T >
int SList< T >::size() const {
	return NodesCount;
}

template < typename T >
int SList< T >::sizeElementsInArrays() const {
	Node< T >* current = head;
	int elementsCount = 0;
	while( current != nullptr ) {
		elementsCount += current-> getAmountOfElements();
		current = ( current-> getNextNode() );
	}
	return elementsCount;
}

template < typename T >
bool SList< T >::empty() const {
	return NodesCount == 0;
}

template < typename T >
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

template < typename T >
void SList< T >::push_back( const T& d ) {
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

template < typename T >
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

template < typename T >
void SList< T >::pop_front() {
	erase( begin() );
}

template < typename T >
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

template < typename T >
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

template < typename T >
void SList< T >::pushInFirstEmpty( const T& d ) {
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

template < typename T >
Iterator< T > SList< T >::search( const T& demanded ) {
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