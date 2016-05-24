#include "Iterator.hpp"
#include <iostream>

template < class T >
class SinglyLinkedList {
private:
	Node< T >* head;
	Node< T >* tail;
	int count;	
public:
	SinglyLinkedList() : head( nullptr ), tail( nullptr ), count( 0 ) {}
	SinglyLinkedList< T >& operator = ( const SinglyLinkedList< T >& );
	SinglyLinkedList( const SinglyLinkedList< T >& );
	~SinglyLinkedList();
	void push_front( T& );
	void pop_front();
	void push_back( T& );
	void pop_back();
	void insert_after( Iterator< T >, const T & );
	void erase_after( Iterator< T > position );
	int size() const;
	bool empty() const;
	void clear();
	Node< T >& front() const; 
	Node< T >& back() const;
	Iterator< T > begin();
	Iterator< T > end();
	void printList();
};

template < class T >
SinglyLinkedList< T >::~SinglyLinkedList() {
	clear();
	delete this;
}

template < class T >
Iterator< T > SinglyLinkedList< T >::begin() {
	return Iterator< T >( head ); 
}

template < class T >
Iterator< T > SinglyLinkedList< T >::end() {
	return Iterator< T >( tail ); 
}

template < class T >
void SinglyLinkedList< T >::push_front( T& d ) {
	Node< T >* newHead = new Node< T >( d, head );

	if ( this-> empty() ) {
		head = newHead;
		tail = newHead;
	}
	else 
		head = newHead;
	++count;
}	

template < class T >
void SinglyLinkedList< T >::pop_front() {


	Node< T >* oldHead = head;

	if ( this-> size() == 1 ) {
		head = nullptr;
		tail = nullptr;
	}
	else
		head = head-> getNext();
	delete oldHead;
	--count;
}

template < class T >
void SinglyLinkedList< T >::push_back( T& d ) {
	Node< T >* newTail = new Node< T >( d, nullptr );

	if ( this-> empty() ) 
		head = newTail;
	else 
		tail->setNextNode( newTail );
	tail = newTail;
	++count;
}

template < class T >
void SinglyLinkedList< T >::pop_back() {


	Node< T >* oldTail = tail;

	if( this-> size() == 1 ) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node< T >* current = head;
		while( current-> getNext() != tail)
			current = current-> getNext();
		current->setNextNode( nullptr );
		tail = current;
	}

	delete oldTail;
	--count;
}

template < class T >
SinglyLinkedList< T >::SinglyLinkedList( const SinglyLinkedList< T >& source ) : count( 0 ), head( NULL ), tail( NULL ) {
	Node< T >* current = source.head;
	while( current != nullptr ) {
		this-> push_back( current-> data );
		current = current-> getNext();
	}
}

template < class T >
SinglyLinkedList< T >& SinglyLinkedList< T >::operator = ( const SinglyLinkedList < T > & source ) {
	if ( this != &source ) {
		clear();
		for( Node< T >* current = source.head; current != nullptr; current = current-> getNext() )
			push_back( current-> data );
	}
	return *this;
}

template < class T >
void SinglyLinkedList< T >::clear() {
	for( ; head != nullptr; ) 
		pop_front();
}

template < class T > 
bool SinglyLinkedList< T >::empty() const {
	return count == 0; 
}

template < class T >
int SinglyLinkedList< T >::size() const {
	return count;
}

template < class T >
Node< T >& SinglyLinkedList< T >::front() const {
	return *head;
}

template < class T >
Node< T >& SinglyLinkedList< T >::back() const {
	return *tail;
}

template < class T >
void SinglyLinkedList< T >::insert_after( Iterator< T > position, const T & value ) {
	Node< T >* newNode = new Node< T >( value, position.ptr-> getNext );
	if ( position == end() )
		tail = newNode;
	position.ptr-> setNextNode( newNode );
}

template < class T >
void SinglyLinkedList< T >::erase_after( Iterator< T > position ) {
	if ( position == end() )
		return;
	Node< T >* toDelete = ++position.ptr;
	Node< T >* nextOfDeleted = toDelete-> getNext();
	position.ptr-> setNextNode( nextOfDeleted );
	if( toDelete == back() )
		tail = position.ptr;
	delete toDelete;
}

template < class T >
void SinglyLinkedList< T >::printList() {
	Iterator< T > it; 
	it = begin();
	for( ; it != end(); ++it ) {
		std::cout << *it << std::endl;
	}
	std::cout << *it << std::endl;
	return;
}