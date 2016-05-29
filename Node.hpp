extern const int ARRAY_MAX_SIZE;

template < typename T >
class Node {

	private:
		T* elements;
		Node* next;
		int elementsInArray;

	public:
		Node< T >( Node< T >* = nullptr );
		~Node< T >() noexcept { delete[] elements; }
		Node< T >& operator = ( const Node< T >& );
		Node< T >* getNextNode() const;
		T& getData( const int = 0 ) const;
		void setNextNode( Node< T >* = nullptr );
		void setDataInArray( const T&, const int = 0 );
		int getAmountOfElements() const;
		int deleteElement( T& );
};

template < typename T >
Node< T >::Node( Node< T >* n ) : next( n ), elementsInArray( 0 ) {
	elements = new T[ ARRAY_MAX_SIZE ];
}

template < typename T >
Node< T >& Node< T >::operator = ( const Node< T >& source ) {
	elementsInArray = source.elementsInArray;
	next = nullptr;
	elements = source.elements;
	return *this;
}

template < typename T >
Node< T >* Node< T >::getNextNode() const {
	return next;
}

template < typename T >
T& Node< T >::getData( const int numberInArray ) const {
	return  elements[ numberInArray ] ;
}

template < typename T >
void Node< T >::setNextNode( Node< T >* n ) {
	next = n;
}

template < typename T >
void Node< T >::setDataInArray( const T& d, const int place ) {
	elements[ place ] = d;
	++elementsInArray;
}

template < typename T >
int Node< T >::getAmountOfElements() const {
	return elementsInArray;
}

template < typename T >
int Node< T >::deleteElement( T& element ) {
	element = 0;
	--elementsInArray;
	return elementsInArray;
}