#include <iostream>

#include "Node.hpp"
#include "MyExceptions.hpp"
extern const int ARRAY_MAX_SIZE ;

template < class T >
class Iterator {

	public:
		Iterator< T >( Node< T >* ptr = nullptr, int position = 0 ) {
			pointer = ptr;
			positionInArray = position;

		}
// 		//Iterator< T >( Iterator< T >& );
		Iterator< T > operator ++ ();
// 		Iterator< T >& operator ++ ( T );
		void operator = ( const Iterator& );
		bool operator != ( const Iterator& ) const;
		bool operator == ( Iterator& );
		T& operator * () const;
// 		T& operator -> () const;

	private:
		Node< T >* pointer;
		int positionInArray;
};

template < class T >
void Iterator< T >::operator = ( const Iterator< T >& source ) {
	pointer = source.pointer;
	positionInArray = source.positionInArray;
}

// //odroznic post i pre

template < class T >
Iterator< T > Iterator< T >::operator ++() {
    // if( pointer-> getNextNode() == nullptr ) {
    //     throw IteratorIndex();
    // }
	if( positionInArray < ( pointer->getAmountOfElements() - 1 ) ) {
		// if ( pointer-> getNextNode() == nullptr  )
			// return Iterator< T >();
		++positionInArray;
		
	}
	else {
		std::cout << "------" << std::endl;
		pointer = pointer-> getNextNode();
		positionInArray = 0;
 	}
// 	ptr = ptr-> getNext();
	return *this;
}
// template < class T >
// Iterator< T >& Iterator< T >::operator ++ ( T ) {
// 	ptr = ptr-> getNext();
// 	return *this;
// }

template < class T >
bool Iterator< T >::operator != ( const Iterator& it2 ) const {
	bool pointers = (pointer == it2.pointer);
	bool positions = (positionInArray == it2.positionInArray);
	return ( ! ( ( pointer == it2.pointer ) && ( positionInArray == it2.positionInArray ) ) );
}

template < class T >
bool Iterator< T >::operator == ( Iterator& it2 ) {
	return ( pointer == it2.pointer ) && ( positionInArray == it2.positionInArray);
}

template < class T >
T& Iterator< T >::operator * () const {
	return pointer-> getData( positionInArray );
}

// template < class T >
// T& Iterator< T >::operator -> () const {
// 	return ptr-> getData();
// }


