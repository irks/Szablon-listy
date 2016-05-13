template < class T >

class SinglyLinkedList {

private:
	class Node {
		friend class SinglyLinkedList< T >;

		private:
			T data;
			Node* next;
		public:
			Node( T d, Node* n = NULL ) : data( d ), next( n ) {}
	};

	Node* head;
	Node* tail;
	int count;

public:

	SinglyLinkedList() : head( NULL ), tail( NULL ), count( 0 ) {}

	T& front() {
		assert ( head != NULL );
		return head-> data;
	}

	T& back() {
		assert ( tail != NULL );
		return tail-> data;
	}

	int size() {
		return count;
	}

	bool empty() {
		return count == 0;
	}

};

template < class T >
void SinglyLinkedList< T >::push_front( T d ) {
	Node* newHead = new Node( d, head );

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

	assert( head != NULL );

	Node* oldHead = head;

	if ( this-> size() == 1 ) {
		head = NULL;
		tail = NULL;
	}
	else
		head = head-> next;
	delete oldHead
	--count;
}

template< class T >
void SinglyLinkedList< T >::push_back( T d ) {
	Node* newTail = newNode( d, NULL );

	if ( this-> empty() ) 
		head = newTail;
	else 
		tail-> next = newTail;
	tail = newTail;
	++count;
}