#include "Node.hpp"

template < class T >
class iterator {
		
	public:
		iterator< T >( Node< T >* pointer = nullptr ) : ptr( pointer ) {}
		iterator< T >& operator ++ ();
		iterator< T >& operator ++ ( T );
		const bool operator != ( const iterator& );
		const bool operator == ( const iterator& );
		T& operator * ();
		
	private:
		Node< T >* ptr;
};

template < class T >
iterator< T >& iterator< T >::operator ++() {
	ptr = ptr-> getNext(); 
	return *this;
}
template < class T >
iterator< T >& iterator< T >::operator ++ ( T ) {
	ptr = ptr-> getNext(); 
	return *this;
}

template < class T >
const bool iterator< T >::operator != ( const iterator& it2 ) {
	return ptr != it2.ptr;
}

template < class T >
const bool iterator< T >::operator == ( const iterator& it2 ) {
	return ptr == it2.ptr;
}

template < class T >
T& iterator< T >::operator * () {
	return ptr-> getData();
}


