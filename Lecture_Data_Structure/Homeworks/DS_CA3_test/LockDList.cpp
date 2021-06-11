
#include <iostream>

#include "LockDList.h"
#include "LockDListNode.h"

using namespace std;

template<typename T>
void LockDList<T>::lockNode(DListNode<T> *node) {
	LockDListNode tmp();
	tmp->item = node->item;
	tmp->prev = node->prev;
	tmp->next = node->next;
}

template<typename T>
LockDList<T>::LockDList(){
	head = this;
	head->prev = *this;
	head->next = *this;
}

template<typename T> void LockDList<T>::insertFront(const T& item){
	if (item != NULL){
		this->newNode(item,this->head,(this->head)->next);
		head->next = *item;
		head->next->prev = *item;
	}
}

template<typename T> void LockDList<T>::insertBack(const T& item){
	if (item != NULL){
		this->newNode(item,(this->head)->prev,this->head);
		head->prev = *item;
		head->next->prev = *item;
	}
}
