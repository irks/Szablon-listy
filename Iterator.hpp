#include "Node.hpp"

template < class T >
class Iterator {
		
	public:
		Iterator< T >( Node< T >* pointer = nullptr ) : ptr( pointer ) {}
		//Iterator< T >( Iterator< T >& );
		Iterator< T >& operator ++ ();
		Iterator< T >& operator ++ ( T );
		void operator = ( const Iterator& );
		const bool operator != ( const Iterator& );
		const bool operator == ( Iterator& );
		T& operator * () const;
		T& operator -> () const;
		
	private:
		Node< T >* ptr;
};

template < class T >
void Iterator< T >::operator = ( const Iterator< T >& source ) {
	ptr = source.ptr;
}

template < class T >
Iterator< T >& Iterator< T >::operator ++() {
	ptr = ptr-> getNext(); 
	return *this;
}
template < class T >
Iterator< T >& Iterator< T >::operator ++ ( T ) {
	ptr = ptr-> getNext(); 
	return *this;
}

template < class T >
const bool Iterator< T >::operator != ( const Iterator& it2 ) {
	return ptr != it2.ptr;
}

template < class T >
const bool Iterator< T >::operator == ( Iterator& it2 ) {
	return ptr == it2.ptr;
}

template < class T >
T& Iterator< T >::operator * () const {
	return ptr-> getData();
}

template < class T >
T& Iterator< T >::operator -> () const {
	return ptr-> getData();
}


