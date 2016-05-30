#include <iostream>
#include "Iterator.hpp"
#include "MyExceptions.hpp"
#include "Node.hpp"

const int ARRAY_MAX_SIZE = 8;

template < typename T >
class SList {

	private:
		Node< T >* head_;
		Node< T >* tail_;
		int NodesCount_;

	public:
		SList() : head_( nullptr ), tail_( nullptr ), NodesCount_( 0 ) {}
		SList( const SList< T >& );
		SList< T >& operator = ( SList< T >& );
		~SList() { clear(); };
		Iterator< T > begin();
		Iterator< T > end();
		int size() const;
		int sizeElementsInArrays() const;
		bool empty() const;
		void printList(); 
		void push_back( const T& );
		void push_front( const T& );
		void pop_back();
		void pop_front();
		void erase( Iterator< T > );
		void clear();
		void pushInFirstEmpty( const T& );
		Iterator< T > search( const T& );		
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
Iterator< T > SList< T >::begin() {
	return Iterator< T >( head_ );
}

template < typename T >
Iterator< T > SList< T >::end() {
	return Iterator< T >( tail_, (tail_->getAmountOfElements()-1) );
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
		current = ( current-> getNextNode() );
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
	
	for( ; it != nullptr ;  ++it  ) 
		std::cout << *it << std::endl;
}

template < typename T >
void SList< T >::push_back( const T& d ) {
	if ( empty() ) {
		Node< T >* newTail_ = new Node< T >();
		newTail_-> setDataInArray( d );
		head_ = newTail_;
		tail_ = newTail_;
		++NodesCount_;
		return;
	}
	if ( tail_ -> getAmountOfElements() < ARRAY_MAX_SIZE ) 
		tail_-> setDataInArray( d, tail_-> getAmountOfElements() );
	else {
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
		T dataCurrent = *current;
		T dataPrevious = d;
		// *current = d;

		while( current.getNode() == head_ ) {
			dataCurrent = *current;
			*current = dataPrevious;
			++current;

			dataPrevious = dataCurrent;
			
			
			

		}
		pushInFirstEmpty( dataPrevious );
	}
}

template < typename T >
void SList< T >::pop_back() {
	if ( empty() )
		throw EmptyList();
	if( begin() == end() ) {
		delete tail_;
		head_ = nullptr;
		tail_ = nullptr;
		--NodesCount_;
	}
	else if ( tail_-> deleteElement( *end() ) == 0 ) {
		Node< T >* current = head_;
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

	if( position == end() ) 
		pop_back();	
	else  {
		Node< T >* positionNode = position.getNode();

		if ( positionNode-> getAmountOfElements() == 1 ) {
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

    Node< T >* oldHead_;

	for( ; head_ != nullptr; ) {
		oldHead_ = head_;

		if ( this-> size() == 1 ) {
			head_ = nullptr;
			tail_ = nullptr;
		}
		else
			head_ = head_-> getNextNode();

		delete oldHead_;
	}
	NodesCount_ = 0;	
}

template < typename T >
void SList< T >::pushInFirstEmpty( const T& d ) {
	Node< T >* current = head_;

	while( ( current != nullptr ) && ( current-> getAmountOfElements() == ARRAY_MAX_SIZE ) ) {
		current = current-> getNextNode();
	}
	if ( current == nullptr ) 
		push_back( d );
	else
		current-> setDataInArray( d, current-> getAmountOfElements() );
}

template < typename T >
Iterator< T > SList< T >::search( const T& demanded ) {
	if( empty() )
        throw EmptyList();

	Iterator< T > it = begin(); 
	
	for( ; it != nullptr; ++it ) { 
		if( *it == demanded ) {
			return it;
		}
	}

	throw LackElement(); //if element doesn't exist
}