#ifndef NODE
#define NODE

template<class ItemType>
class Node{
	ItemType item;
	Node<ItemType>* next;
public:
	//constructors
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	//getters
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
	//setters
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
}; 
#include "node.cpp"
#endif