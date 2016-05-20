#include <cassert>
//#include "Node.hpp"
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
	int size() { return count; }
	bool empty() const { return count == 0; };
	void clear();
	
	Node< T >& front() {
		assert ( head != nullptr );
		return head;
	}
	Node< T >& back() {
		assert ( tail != nullptr );
		return tail;
	}

	 iterator< T > begin();
	 iterator< T > end();
	//const_iterator cbegin() const { return head; };
	//const_iterator cend() const { return tail; };
	//reverse_iterator rbegin() { return reverse_iterator( end() ); }
	//const_reverse_iterator crbegin() const { return const_reverse_iterator( end() ); }
	//reverse_iterator rend() { return reverse_iterator( begin() ); }
	//const_reverse_iterator crend() const { return const_reverse_iterator( begin() ); }
	//size_type size() const { return size_type( end() - begin() ); }
	//size_type max_size() const { return size_type() / sizeof( T ); } 
	//bool empty() const { return begin() == end() }
};

template < class T >
 iterator< T > SinglyLinkedList< T >::begin() {
	return iterator< T >( head ); 
}

template < class T >
 iterator< T > SinglyLinkedList< T >::end() {
	return iterator< T >( tail ); 
}


/*template < class T >
typename SinglyLinkedList< T >::iterator& SinglyLinkedList< T >::iterator::begin() {
	iterator it;
	it.ptr = head;
	return it;
}*/

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

	assert( head != nullptr );

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

	assert( tail != nullptr );

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
