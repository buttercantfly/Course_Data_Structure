#include "DListNode.h"

template<typename T>
class LockDList;

template<typename T>
class LockDListNode: public DListNode<T> {

protected:
	friend class LockDList<T>;
	const DListNode<T>* next;
	const DListNode<T>* prev;
	const T item;

};