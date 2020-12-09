#ifndef LINKED_LIST
#define LINKED_LIST

#include "list.h"
#include "node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>{
	Node<ItemType>* headPtr; 
	int itemCount;
	Node<ItemType>* getNodeAt(int position) const; 
public:
	//constructors
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	//functions
	bool isEmpty() const;
	int getLength() const;
	bool insert(int position, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const;
	ItemType replace(int position, const ItemType& newEntry);
	//deconstructor
	virtual ~LinkedList();
};
#include "linkedlist.cpp"
#endif