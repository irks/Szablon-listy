/*void myAssert( int a, const string& msg )
{
    if( !a )
    {
        cerr << msg << " ... Press 'Enter' to exit ... " << flush;
        cin.clear(); cin.sync(); cin.get(); exit(1);
    }
}*/

template < class T > class Iter;
template < class T > class SinglyLinkedList;
template < class T > class Node;

template < class T >
class Iter {

public:
    Iter() : current( NULL ) {}

    // return T value at Node of this Iter  ...
    T operator * () const {
        assert( current != NULL);
        return current-> data;
    }
    T& operator * () {
        assert( current != NULL);
        return current-> data;
    }
    // pre ++ ...
    Iter& operator ++ () {
        assert( current != NULL);
        current = current-> next;
        return *this;
    }
    // post ++ ...
    Iter& operator ++ ( int anIntDummyHereToIndicatePostPP ) {
        assert( current != NULL);
        current = current-> next;
        return *this;
    }
    
    bool operator == ( Iter< T > it ) const { return current == it.current; }
    bool operator != ( Iter< T > it ) const { return current != it.current; }

private:
    Node< T >* current;
    friend class List< T >;
};













template < class T >

class SinglyLinkedList {

public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type* iterator;
	typedef const value_type* const_iterator;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef reverse_iterator< const_iterator > const_reverse_iterator;
	typedef reverse_iterator< iterator > reverse_iterator;


private:
	class Node {
		friend class SinglyLinkedList< T >;
		friend class Iter< T >;

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

	iterator begin() { return head };
	const_iterator cbegin() const { return head; };
	iterator end() { return tail };
	const_iterator cend() const { return tail; };
	reverse_iterator rbegin() { return reverse_iterator( end() ); }
	const_reverse_iterator crbegin() const { return const_reverse_iterator( end() ); }
	reverse_iterator rend() { return reverse_iterator( begin() ); }
	const_reverse_iterator crend() const { return const_reverse_iterator( begin() ); }
	size_type size() const { return size_type( end() - begin() ); }
	size_type max_size() const { return size_type() / sizeof( T ); }
	//bool empty() const { return begin() == end() }




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

template < class T >
void SinglyLinkedList< T >::push_back( T d ) {
	Node* newTail = newNode( d, NULL );

	if ( this-> empty() ) 
		head = newTail;
	else 
		tail-> next = newTail;
	tail = newTail;
	++count;
}

template < class T >
void SinglyLinkedList< T >::pop_back() {

	assert( tail != NULL );

	Node* oldTail = tail;

	if( this-> size() == 1 ) {
		head = NULL;
		tail = NULL;
	}
	else {
		Node* current = head;
		while( current-> next != tail)
			current = current-> next;
		current-> next = NULL;
		tail = current;
	}

	delete oldTail;
	--count;
}

template < class T >
SinglyLinkedList< T >::~SinglyLinkedList() {
	while( ! this-> empty )
		this-> pop_front();
}

template < class T >
SinglyLinkedList< T >::SinglyLinkedList( const SinglyLinkedList< T >& source ) : count( 0 ), head( NULL ), tail( NULL ) {
	Node* current = source.head;
	while( current != NULL ) {
		this-> push_back( current-> data )
		current = current-> next;
	}
}

template < class T >
SinglyLinkedList& SinglyLinkedList< T >::operator = ( const SinglyLinkedList < T > & source ) {
	if ( this != &source ) {
		//wyczysc
		for( Node< T )
	}
	return *this;
}