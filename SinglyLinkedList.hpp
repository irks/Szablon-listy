#include "Iterator.hpp"
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
	int size() const;
	bool empty() const;
	void clear();
	Node< T >& front() const; 
	Node< T >& back() const;
	iterator< T > begin();
	iterator< T > end();
};

template < class T >
 iterator< T > SinglyLinkedList< T >::begin() {
	return iterator< T >( head ); 
}

template < class T >
 iterator< T > SinglyLinkedList< T >::end() {
	return iterator< T >( tail ); 
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
SinglyLinkedList< T >::~SinglyLinkedList() {
	while( ! this-> empty() )
		this-> pop_front();
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
	return head;
}

template < class T >
Node< T >& SinglyLinkedList< T >::back() const {
	return tail;
}

//erase
//insert
