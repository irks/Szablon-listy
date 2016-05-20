template < class T >
class Node {
	private:
		T data;
		Node* next;
		
	public:
		Node( T d, Node< T >* n = nullptr ) : data( d ), next( n ) {}
		Node< T >* getNext() {
			return next;
		}	
		T& getData() {
			return data;
		}
		void setNextNode( Node< T >* n = nullptr ) {
			next = n;
		}
};
