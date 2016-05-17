#include "Node.hpp"

template < class T >
class iterator {
		//friend class SinglyLinkedList< T >;
	public:
		iterator& operator ++ () { ptr = ptr-> nextN(); return *this; }
		iterator& operator ++ ( int dummy ) { ptr = ptr-> nextN(); return *this; }
		bool operator != ( const iterator& it2 ) const { return ptr != it2.ptr; }
		T operator * () const { return ptr-> data(); }
		T& operator * () { return ptr-> data(); }
		iterator( Node* pointer = NULL ) : ptr( pointer ) {}
	private:
		Node* ptr;
	};

	template < class T >
SinglyLinkedList< T >::iterator SinglyLinkedList< T >::begin() {
	typename SinglyLinkedList< T >::iterator it;
	it.ptr = SinglyLinkedList::front();
	return it;
}

template < class T >
SinglyLinkedList< T >::iterator SinglyLinkedList< T >::end() {
	typename SinglyLinkedList< T >::iterator it;
	it.ptr = SinglyLinkedList::back();
	return it;
}

template < class T >
bool operator == ( iterator< T > it ) const { return current == it.current; }

template < class T >
bool operator != ( iterator< T > it ) const { return current != it.current; }