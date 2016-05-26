extern const int ARRAY_MAX_SIZE;

template < class T >
class Node {
	private:
		T* elements;
		Node* next;
		int elementsInArray;
	public:
		Node< T >( Node< T >* n = nullptr ) {
			next = n; 
			elementsInArray = 0;
			elements = new T[ ARRAY_MAX_SIZE ];
		}
		~Node< T >() {
			delete elements;
			
		}
		Node< T >* getNextNode();
		T& getData( int = 0 );
		void setNextNode( Node< T >* = nullptr );
		void setDataInArray( T&, int = 0 );
		int getAmountOfElements();
};

template < class T >
Node< T >* Node< T >::getNextNode() {
	return next;
}
template < class T >
T& Node< T >::getData( int numberInArray ) {
	return  elements[numberInArray] ;
}

template < class T >
void Node< T >::setNextNode( Node< T >* n ) {
	next = n;
}

template < class T >
void Node< T >::setDataInArray( T& d, int place ) {
	elements[place] = d;
	++elementsInArray;
}

template < class T >
int Node< T >::getAmountOfElements() {
	return elementsInArray;
}