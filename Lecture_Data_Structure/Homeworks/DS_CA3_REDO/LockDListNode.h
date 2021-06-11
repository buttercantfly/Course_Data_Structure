/**
 *  A LockDListNode is a node in a LockDList (doubly-linked list).
 */

#ifndef LockDListNODE_H
#define LockDListNODE_H

template<typename T>
class LockDList;

template<typename T>
class LockDListNode : public DListNode {
	/**
	 *  item references the item stored in the current node.
	 *  prev references the previous node in the LockDList.
	 *  next references the next node in the LockDList.
	 *
	 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
	 */

protected:
	LockDListNode<T>* prev;
	LockDListNode<T>* next;
	friend class LockDList<T>;

public:
	T item;
};

#endif
