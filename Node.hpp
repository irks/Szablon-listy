extern const int ARRAY_MAX_SIZE;

template < typename T >
class Node {

	private:
		T* elements_;
		Node* next_;
		int elementsInArray_;

	public:
		Node< T >( Node< T >* = nullptr );
		~Node< T >() noexcept { delete[] elements_; }
		Node< T >& operator = ( const Node< T >& );
		Node< T >* getNextNode() const;
		T& getData( const int = 0 ) const;
		void setNextNode( Node< T >* = nullptr );
		void setDataInArray( const T&, const int = 0 );
		int getAmountOfElements() const;
		int deleteElement( T& );
};

template < typename T >
Node< T >::Node( Node< T >* n ) : next_( n ), elementsInArray_( 0 ) {
	elements_ = new T[ ARRAY_MAX_SIZE ];
}

template < typename T >
Node< T >& Node< T >::operator = ( const Node< T >& source ) {
	elementsInArray_ = source.elementsInArray_;
	next_ = nullptr;
	elements_ = source.elements_;
	return *this;
}

template < typename T >
Node< T >* Node< T >::getNextNode() const {
	return next_;
}

template < typename T >
T& Node< T >::getData( const int numberInArray ) const {
	return  elements_[ numberInArray ] ;
}

template < typename T >
void Node< T >::setNextNode( Node< T >* n ) {
	next_ = n;
}

template < typename T >
void Node< T >::setDataInArray( const T& d, const int place ) {
	elements_[ place ] = d;
	++elementsInArray_;
}

template < typename T >
int Node< T >::getAmountOfElements() const {
	return elementsInArray_;
}

template < typename T >
int Node< T >::deleteElement( T& element ) {
	element = 0;
	--elementsInArray_;
	return elementsInArray_;
}