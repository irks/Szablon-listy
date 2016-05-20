#include "Node.hpp"

template < class T >
class iterator {
		
	public:
		iterator< T >& operator ++ () { ptr = ptr-> getNext(); return *this; }
		iterator< T >& operator ++ ( T ) { ptr = ptr-> getNext(); return *this; }
		const bool operator != ( const iterator& it2 ) { return ptr != it2.ptr; }
		const bool operator == ( const iterator& it2 ) { return ptr == it2.ptr; }
		//const T operator * () { return ptr-> data(); }
		T& operator * () { return ptr-> data(); }
		iterator< T >( Node< T >* pointer = nullptr ) : ptr( pointer ) {}
	private:
		Node< T >* ptr;
	};


