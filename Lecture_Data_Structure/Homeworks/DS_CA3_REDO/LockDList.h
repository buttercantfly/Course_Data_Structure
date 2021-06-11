/**
 *  A LockDList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

#ifndef LockDList_H
#define LockDList_H

#include "LockDListNode.h"
#include "DList.h"

template<typename T>
class LockDList:public DList {

	/**
	 *  head references the sentinel node.
	 *  size is the number of items in the list.  (The sentinel node does not
	 *       store an item.)
	 *
	 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
	 */

protected:
	LockDListNode<T>* head;
	int size;

	/* LockDList invariants:
	 *  1)  head != null.
	 *  2)  For any LockDListNode x in a LockDList, x.next != null.
	 *  3)  For any LockDListNode x in a LockDList, x.prev != null.
	 *  4)  For any LockDListNode x in a LockDList, if x.next == y, then y.prev == x.
	 *  5)  For any LockDListNode x in a LockDList, if x.prev == y, then y.next == x.
	 *  6)  size is the number of LockDListNodes, NOT COUNTING the sentinel,
	 *      that can be accessed from the sentinel (head) by a sequence of
	 *      "next" references.
	 */

	/**
	 *  newNode() calls the LockDListNode constructor.  Use this class to allocate
	 *  new LockDListNodes rather than calling the LockDListNode constructor directly.
	 *  That way, only this method needs to be overridden if a subclass of LockDList
	 *  wants to use a different kind of node.
	 *  @param item the item to store in the node.
	 *  @param prev the node previous to this node.
	 *  @param next the node following this node.
	 */
	DListNode<T>* newNode(const T& item, LockDListNode<T>* prev, LockDListNode<T>* next) override;

public:
	/**
	 *  LockDList() constructor for an empty LockDList.
	 */
	LockDList();

	void lockNode(DListNode* node);

	/**
	 *  isEmpty() returns true if this LockDList is empty, false otherwise.
	 *  @return true if this LockDList is empty, false otherwise. 
	 *  Performance:  runs in O(1) time.
	 */
	bool isEmpty();

	/** 
	 *  length() returns the length of this LockDList. 
	 *  @return the length of this LockDList.
	 *  Performance:  runs in O(1) time.
	 */
	int length();

	/**
	 *  insertFront() inserts an item at the front of this LockDList.
	 *  @param item is the item to be inserted.
	 *  Performance:  runs in O(1) time.
	 */
	void insertFront(const T& item);

	/**
	 *  insertBack() inserts an item at the back of this LockDList.
	 *  @param item is the item to be inserted.
	 *  Performance:  runs in O(1) time.
	 */
	void insertBack(const T& item);

	/**
	 *  front() returns the node at the front of this LockDList.  If the LockDList is
	 *  empty, return null.
	 *
	 *  Do NOT return the sentinel under any circumstances!
	 *
	 *  @return the node at the front of this LockDList.
	 *  Performance:  runs in O(1) time.
	 */
	LockDListNode<T>* front();

	/**
	 *  back() returns the node at the back of this LockDList.  If the LockDList is
	 *  empty, return null.
	 *
	 *  Do NOT return the sentinel under any circumstances!
	 *
	 *  @return the node at the back of this LockDList.
	 *  Performance:  runs in O(1) time.
	 */
	LockDListNode<T>* back();

	/**
	 *  next() returns the node following "node" in this LockDList.  If "node" is
	 *  null, or "node" is the last node in this LockDList, return null.
	 *
	 *  Do NOT return the sentinel under any circumstances!
	 *
	 *  @param node the node whose successor is sought.
	 *  @return the node following "node".
	 *  Performance:  runs in O(1) time.
	 */
	LockDListNode<T>* next(LockDListNode<T>* node);

	/**
	 *  prev() returns the node prior to "node" in this LockDList.  If "node" is
	 *  null, or "node" is the first node in this LockDList, return null.
	 *
	 *  Do NOT return the sentinel under any circumstances!
	 *
	 *  @param node the node whose predecessor is sought.
	 *  @return the node prior to "node".
	 *  Performance:  runs in O(1) time.
	 */
	LockDListNode<T>* prev(LockDListNode<T>* node);

	/**
	 *  insertAfter() inserts an item in this LockDList immediately following "node".
	 *  If "node" is null, do nothing.
	 *  @param item the item to be inserted.
	 *  @param node the node to insert the item after.
	 *  Performance:  runs in O(1) time.
	 */
	void insertAfter(const T& item, LockDListNode<T>* node);

	/**
	 *  insertBefore() inserts an item in this LockDList immediately before "node".
	 *  If "node" is null, do nothing.
	 *  @param item the item to be inserted.
	 *  @param node the node to insert the item before.
	 *  Performance:  runs in O(1) time.
	 */
	void insertBefore(const T& item, LockDListNode<T>* node);

	/**
	 *  remove() removes "node" from this LockDList.  If "node" is null, do nothing.
	 *  Performance:  runs in O(1) time.
	 */
	void remove(LockDListNode<T>* node);

	/**
	 *  toString() prints a string representation of this DList.
	 *
	 *  DO NOT CHANGE THIS METHOD.
	 *
	 *  Performance:  runs in O(n) time, where n is the length of the list.
	 */
	void toString();
};

#endif
