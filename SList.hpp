// Wrobel Ireneusz, Informatyka, grupa 2I5
// Implementation of template class used to representing forward list
// Memory is allocated in blocks

// Class, which contains functions used to do operatons on the list
// It has pointer to the first Node, the last Node and a number which represents number of Nodes in the list

#include <iostream>
#include "Iterator.hpp"
#include "MyExceptions.hpp"
#include "Node.hpp"

const int ARRAY_MAX_SIZE = 10;

template < typename T >
class SList {

	private:
		Node< T >* head_;
		Node< T >* tail_;
		int NodesCount_;

	public:
		SList() : head_( nullptr ), tail_( nullptr ), NodesCount_( 0 ) {}
		SList( const SList< T >& ); // copy constructor
		SList< T >& operator = ( SList< T >& );
		~SList();
		Iterator< T > begin(); 
		Iterator< T > end();
		int size() const;
		int sizeElementsInArrays() const; // sum of number of elements in all Nodes
		bool empty() const;
		void printList(); 
		void push_back( const T& );
		void push_front( const T& );
		void pop_back();
		void pop_front();
		void erase( Iterator< T > ); // erase element pointed by Iterator 
		void clear();
		void pushInFirstEmpty( const T& );
		Iterator< T > search( const T& ); // return Iterator to first found element	
};

template < typename T >
SList< T >::SList( const SList< T >& source ) : NodesCount_( 0 ), head_( nullptr ), tail_( nullptr ) {
	Iterator< T > it;
	it = source.head_;
	for ( ; it != nullptr; ++it )
		this-> push_back( *it );
}

template < typename T >
SList< T >& SList< T >::operator = ( SList < T > & source ) { 
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
SList< T >::~SList() {
	if ( ! empty() ) 
		clear();
}

template < typename T >
Iterator< T > SList< T >::begin() {
	return Iterator< T >( head_ );
}

template < typename T >
Iterator< T > SList< T >::end() {
	return Iterator< T >();
}

template < typename T >
int SList< T >::size() const {
	return NodesCount_;
}

template < typename T >
int SList< T >::sizeElementsInArrays() const {
	Node< T >* current = head_;
	int elementsCount = 0;

	while( current != nullptr ) {
		elementsCount += current-> getAmountOfElements();
		current = current-> getNextNode(); //getting next Node until there is end of list
	}
	return elementsCount;
}

template < typename T >
bool SList< T >::empty() const {
	return NodesCount_ == 0;
}

template < typename T >
void SList< T >::printList() {
    if( empty() )
        throw EmptyList();

	Iterator< T > it = begin();
	
	for( ; it != end() ;  ++it  ) 
		std::cout << *it << std::endl;
}

template < typename T >
void SList< T >::push_back( const T& d ) {
	if ( empty() ) {
		Node< T >* newTail = new Node< T >();
		newTail-> setDataInArray( d );
		head_ = newTail;
		tail_ = newTail;
		++NodesCount_;
		return;
	}
	if ( tail_ -> getAmountOfElements() < ARRAY_MAX_SIZE ) // if there is space in the existing array 
		tail_-> setDataInArray( d, tail_-> getAmountOfElements() ); //add to first free positon in the array
	else { // if there isn't free space in the existing array
		Node< T >* newTail_ = new Node< T >();
		tail_ -> setNextNode( newTail_ );
		
		newTail_-> setDataInArray( d );
		tail_ = newTail_;
		++NodesCount_;
	}
}

template < typename T >
void SList< T >::push_front( const T& d ) {
	if ( empty() ) {
		Node< T >* newTail_ = new Node< T >();
		newTail_-> setDataInArray( d );
		head_ = newTail_;
		tail_ = newTail_;
		++NodesCount_;
		return;
	}
	else {
		Iterator< T > current = begin();
		T dataCurrent = *current; //getting value of the first element
		T dataPrevious = d; //getting value which will be put in the first position

		while( current.getNode() == head_ ) {
			dataCurrent = *current;
			*current = dataPrevious;
			++current; //going through all elements in the first Node 
						//shifting all elements in the first Node to the right ( one position to the right )

			dataPrevious = dataCurrent;
		}
		pushInFirstEmpty( dataPrevious ); //adding the last element from the array in the first Node to the first empty place

	}
}

template < typename T >
void SList< T >::pop_back() {
	if ( empty() )
		throw EmptyList();

	if( sizeElementsInArrays() == 1 ) { //if there is only one element in the whole list
		delete tail_;
		head_ = nullptr;
		tail_ = nullptr;
		--NodesCount_;
	}
	else if ( ( tail_-> deleteElement( *Iterator< T >( tail_, tail_->getAmountOfElements() - 1 ) ) == 0 ) ) { //if there is more than 1 element in the list
		Node< T >* current = head_;																	// but only one in the last Node
		Node< T >* previous = nullptr;

		while ( current != tail_ ) {
			previous = current;
			current = current-> getNextNode();
		}
		delete tail_;
		tail_ = previous;
		tail_-> setNextNode( nullptr );
		--NodesCount_;
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

	Node< T >* positionNode = position.getNode();

	if ( positionNode-> getAmountOfElements() == 1 ) { //if there is only one element in the Node
		Node< T >* current = head_;
		Node< T >* previous = nullptr;

		while ( current != positionNode ) {
			previous = current;
			current = current-> getNextNode();
		}
		previous-> setNextNode( positionNode-> getNextNode() );
		delete positionNode;
		--NodesCount_;
	}
	else { // if there are more than one element in the Node
		Iterator< T > current = position;
		++current;
		Iterator< T > previous = position;

		while( current.getNode() == positionNode ) {
			previous = current;
			++current;
		}
		*position = *previous; //setting in the place of the element to erase, the last element in the same array
		positionNode-> deleteElement( *previous ); //cleaning the last element in the array
	}
}

template < typename T >
void SList< T >::clear() {
    if( empty() ) 
        throw EmptyList();

    Node< T >* oldHead;

	for( ; head_ != nullptr; ) {
		oldHead = head_;

		if ( this-> size() == 1 ) {
			head_ = nullptr;
			tail_ = nullptr;
		}
		else
			head_ = head_-> getNextNode();

		delete oldHead;
	}
	NodesCount_ = 0;	
}

template < typename T >
void SList< T >::pushInFirstEmpty( const T& d ) {
	Node< T >* current = head_;

	while( ( current != nullptr ) && ( current-> getAmountOfElements() == ARRAY_MAX_SIZE ) ) {
		current = current-> getNextNode(); //searching for the first array that isn't full
	}
	if ( current == nullptr ) //if there isn't any non full array
		push_back( d );
	else
		current-> setDataInArray( d, current-> getAmountOfElements() );
}

template < typename T >
Iterator< T > SList< T >::search( const T& demanded ) {
	if( empty() )
        throw EmptyList();

	Iterator< T > it = begin(); 
	
	for( ; it != end(); ++it ) { 
		if( *it == demanded ) {
			return it;
		}
	}

	throw LackElement(); //if element doesn't exist
}