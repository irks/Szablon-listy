template < class T >
class Node {
	private:
		T data;
		Node* next;
		
	public:
		Node( T d, Node* n = NULL ) : data( d ), next( n ) {}
		Node* nextN() {
			return next;
		}	
		T& dataN() {
			return data;
		}
};