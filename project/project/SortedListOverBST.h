#pragma once
#include "BST.h"
#include <iostream>
#include <stack>
#include "SortedList.h"
#include <vector>
template<typename K, typename E>
class SortedListOverBST: public SortedList<K>
{
	/*forward declaration for iterator class*/
	class Iterator;

private:
	BST<K, E>* bst; //binary search tree
	Iterator iterator;
	std::vector<Node<K, E>*> orderedNodes;
private:
	void inOrder(Node<K, E>* node, int& currentPosition, int pos, E& balloon);
	void setOrderedNodes();
public:
	BST<K, E>* getBST(){ return bst; };
	/*the contructor*/
	SortedListOverBST();

	/*checks if the list is empty*/
	bool isEmpty();

	/*function  that inserts in correct order*/
	void insert(K element);

	/*get the current size*/
	int getSize();


	/*remove element by position*/
	void deleteElement(int position);

	/*get the element T by position pos*/
	K getElement(int pos);

	/*destructor*/
	~SortedListOverBST();

	/*returns an interator*/
	Iterator getIterator(){
		iterator.reset();
		return iterator;
	}

};



template <typename K, typename E>
SortedListOverBST<K, E>::SortedListOverBST()
	: iterator(this)
{
	bst = new BST<K, E>();
}
template <typename K, typename E>
SortedListOverBST<K, E>::~SortedListOverBST(){
	delete bst;
}


/*checks if the list is empty*/
template <typename K, typename E>
bool SortedListOverBST<K, E>::isEmpty(){
	return getSize() == 0 ? true : false;
	
}
template <typename K, typename E>
int SortedListOverBST<K, E>::getSize(){
	//setOrderedNodes();
	return orderedNodes.size();
}

/*function  that inserts in correct order*/
template <typename K, typename E>
void SortedListOverBST<K, E>::insert(K element){
	bst->AddNode(element, NULL);
	setOrderedNodes();
}


/*
get the element T by position pos
the algorithm is based on in-order traversing
*/
template <typename K, typename E>
void SortedListOverBST<K, E>::setOrderedNodes(){
	orderedNodes.clear();
	std::stack<Node<K, E>*> parentsStack;
	Node<K, E>* node = bst->GetRoot();
	while (!parentsStack.empty() || node != NULL){
		if (node != NULL){
			parentsStack.push(node);
			node = node->GetLeft();
		}
		else{
			node = parentsStack.top();
			parentsStack.pop();
			orderedNodes.push_back(node);
			node = node->GetRight();
		}
	}
}

template <typename K, typename E>
K SortedListOverBST<K, E>::getElement(int pos){
	return orderedNodes.at(pos)->GetKey();
}


template <typename K, typename E>
void SortedListOverBST<K, E>::deleteElement(int position){
	orderedNodes.erase(orderedNodes.begin() + position);

}

template<typename K, typename E>
class SortedListOverBST<K, E>::Iterator{
private:
	SortedListOverBST* parent;
	int currentPosition;
	/*moves to next element*/
	void next(){
		currentPosition++;
	}
public:
	Iterator(SortedListOverBST* sortedList) :
		parent(sortedList)
	{
		currentPosition = 0;
		
	}

	void reset(){
		currentPosition = 0;
	}

	/*check if there is a next element*/
	bool hasNext(){
		if (currentPosition < parent->getSize()){
			return true;
		}
		else{
			return false;
		}
	}

	/*returns the current element and increments the position*/
	K getCurrent(){
		next();
		return parent->getElement(currentPosition - 1);
	}

};