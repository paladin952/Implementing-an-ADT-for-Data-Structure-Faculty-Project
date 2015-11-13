#pragma once

template<typename T>
class SortedList
{

public:
	class Iterator;
	/*Description: the constructor of the vector
	Data: - 
	Precondition: - 
	Postcondition: - 
	*/
	SortedList(){ };
	

	/*Description: check if the list is empty
	Data: - 
	Precondition: - 
	Postcondition: - 
	Result: - returns true or false
	*/
	virtual bool isEmpty() = 0;

	/*Description: insert element in correct order
	Data: - element
	Precondition: - element of type T
	Postcondition: - vector has a new element
	*/
	virtual void insert(T element) = 0;

	/*Description: get the current size of the list
	Data: - 
	Precondition: - 
	Postcondition: - size is unsigned int
	Result: - return the size
	*/
	virtual int getSize() = 0;

	/*Description: delete element from vector by position
	Data: - position
	Precondition: - position is unsigned int
	Postcondition: - size of vector is decreassed
	*/
	virtual void deleteElement(int position) = 0;

	/*Description: get element from vector by position
	Data: - pos
	Precondition: - pos is unsigned int
	Postcondition: - 
	Result: - return the element from position pos
	*/
	virtual T getElement(int pos) = 0;

	/*Description: return an iterator of the class
	Data: - iterator
	Precondition: - iterator is of type Iterator
	Postcondition: - iterator is of type Iterator
	Result: -
	*/
	


};

