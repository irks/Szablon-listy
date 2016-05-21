template < class T >
class Node {
	private:
		T data;
		Node* next;
	public:
		Node( T d, Node< T >* n = nullptr ) : data( d ), next( n ) {}
		Node< T >* getNext();
		T& getData();
		void setNextNode( Node< T >* = nullptr );
};

template < class T >
Node< T >* Node< T >::getNext() {
	return next;
}
template < class T >
T& Node< T >::getData() {
	return data;
}

template < class T >
void Node< T >::setNextNode( Node< T >* n ) {
	next = n;
}