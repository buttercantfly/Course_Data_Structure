/**
 *  A LockDList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

#include <iostream>
#include "LockDList.h"

using namespace std;

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
template<typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, LockDListNode<T>* prev, LockDListNode<T>* next){
	return new LockDListNode<T>(item, prev, next);
}

/**
 *  LockDList() constructor for an empty LockDList.
 */
template<typename T>
LockDList<T>::LockDList() {
	head->next = head;
	head->prev = head;
	size = 0;
	//  Your solution here.
}

/**
 *  isEmpty() returns true if this LockDList is empty, false otherwise.
 *  @return true if this LockDList is empty, false otherwise. 
 *  Performance:  runs in O(1) time.
 */
template<typename T>
bool LockDList<T>::isEmpty() {
	LockDListNode* C = head;
	size = 0;
	while(C->next != head){
		C = C->next;
		size++;
	}
	return size == 0;
}

/** 
 *  length() returns the length of this LockDList. 
 *  @return the length of this LockDList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
int LockDList<T>::length() {
	LockDListNode* C = head;
	size = 0;
	while(C->next != head){
		C = C->next;
		size++;
	}
	return size;
}

/**
 *  insertFront() inserts an item at the front of this LockDList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void LockDList<T>::insertFront(const T& item) {
	newnode(item,head,head->next);
	// Your solution here.
}

/**
 *  insertBack() inserts an item at the back of this LockDList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void LockDList<T>::insertBack(const T& item) {
	newnode(item,head->prev,head);
	// Your solution here.
}

/**
 *  front() returns the node at the front of this LockDList.  If the LockDList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the front of this LockDList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
LockDListNode<T>* LockDList<T>::front() {
	if (haed->next == head){
		return NULL;
	}
	else return head->next;
	// Your solution here.
}

/**
 *  back() returns the node at the back of this LockDList.  If the LockDList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the back of this LockDList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
LockDListNode<T>* LockDList<T>::back() {
	if (haed->prev == head){
		return NULL;
	}
	else return head->prev;
	// Your solution here.
}

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
template<typename T>
LockDListNode<T>* LockDList<T>::next(LockDListNode<T>* node) {
	if (node->next == this->head){
		return NULL;
	}
	else if (node){
		return node->next;
	}
	else{
		return NULL;
	}
	// Your solution here.
}

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
template<typename T>
LockDListNode<T>* LockDList<T>::prev(LockDListNode<T>* node) {
	if (node->prev == this->head){
		return NULL;
	}
	else if (node){
		return node->prev;
	}
	else{
		return NULL;
	}
	// Your solution here.
}

/**
 *  insertAfter() inserts an item in this LockDList immediately following "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item after.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void LockDList<T>::insertAfter(const T& item, LockDListNode<T>* node) {
	if (node){
		newNode(item,node,node->prev);
	}
	// Your solution here.
}

/**
 *  insertBefore() inserts an item in this LockDList immediately before "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item before.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void LockDList<T>::insertBefore(const T& item, LockDListNode<T>* node) {
	if (node){
		newNode(item,node->next,node);
	}
	// Your solution here.
}

/**
 *  remove() removes "node" from this LockDList.  If "node" is null, do nothing.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void LockDList<T>::remove(LockDListNode<T>* node) {
	if (node){
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
	}
	// Your solution here.
}

/**
 *  toString() prints a string representation of this LockDList.
 *
 *  DO NOT CHANGE THIS METHOD.
 *
 *  Performance:  runs in O(n) time, where n is the length of the list.
 */
template<typename T>
void LockDList<T>::toString() {
	cout << "  ListNode     Item   " << endl;
	cout << "----------------------" << endl;
	LockDListNode < T > *current = head->next;
	int i = 1;
	while (current != head) {
		cout << i++ << "        " << current->item << endl;
		current = current->next;
	}
}
