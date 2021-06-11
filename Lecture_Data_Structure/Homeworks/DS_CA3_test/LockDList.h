#include "DList.h"

template<typename T>
class LockDList: public DList<T> {

protected:
	virtual DListNode<T>* newNode(const T& item, DListNode<T>* prev,DListNode<T>* next);

public:
	void lockNode(DListNode<T>*node);

	LockDList();

	void insertFront(const T& item);

	void insertBack(const T& item);
};