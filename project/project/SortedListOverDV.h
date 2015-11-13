#pragma once
#include <vector>
#include <iostream>
#include "Vector.h"
#include <iostream>
#include "SortedList.h"

/*sorted list over dynamic vector*/
template<typename T>
class SortedListOverDV : public SortedList<T> 
{
	/*forward declaration for iterator class*/
	class Iterator;

private:
	Vector<T>* dynamicVector; //the dynamic vector
	Iterator iterator;
public:
	/*the contructor*/
	SortedListOverDV();

	/*checks if the list is empty*/
	bool isEmpty();

	/*function  that inserts in correct order*/
	void insert(T element);

	/*get the current size*/
	int getSize();


	/*remove element by position*/
	void deleteElement(int position);

	/*get the element T by position pos*/
	T getElement(int pos);

	/*destructor*/
	~SortedListOverDV();

	/*returns an interator*/
	Iterator getIterator(){
		iterator.reset();
		return iterator;
	}

};

/*
**insertion function based on insertion sort algorithm
*/
//function that inserts element in sorted position
//algorithm based on insertion sord
template<typename T>
void SortedListOverDV<T>::insert(T element){
	int p;
	p = dynamicVector->getSize();
	dynamicVector->addLast(element);
	while (dynamicVector->getElement(p - 1)>element && p > 0)
	{
		dynamicVector->update(p, dynamicVector->getElement(p - 1));
		p--;
	}
	dynamicVector->update(p, element);
}

///delete element by its position
template<typename T>
void SortedListOverDV<T>::deleteElement(int position){
	dynamicVector->remove(position);
}

template<typename T>
SortedListOverDV<T>::~SortedListOverDV(){
	delete dynamicVector;
}

template<typename T>
T SortedListOverDV<T>::getElement(int pos){
	return dynamicVector->getElement(pos);	
}

template<typename T>
bool SortedListOverDV<T>::isEmpty(){
	if (getSize() == 0){
		return true;
	}
	else{
		return false;
	}
}

template<typename T>
SortedListOverDV<T>::SortedListOverDV()
	:iterator(this)
{
	dynamicVector = new Vector<T>();
}

template<typename T>
int SortedListOverDV<T>::getSize(){
	return dynamicVector->getSize();
}


template<typename T>
class SortedListOverDV<T>::Iterator{
private:
	SortedListOverDV* parent;
	int currentPosition;
	/*moves to next element*/
	void next(){
		currentPosition++;
	}
public:
	Iterator(SortedListOverDV* sortedList):
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
	T getCurrent(){
		next();
		return parent->getElement(currentPosition - 1);
	}

};

