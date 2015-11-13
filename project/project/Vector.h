#pragma once


//dynamically allocated vector
template<typename T>
class Vector
{
private:
	unsigned int capacity; // the capacity of the vector
	unsigned int size; // the current size
	T* elements; //the list of elements

public:
	/*Description: the constructor of the vector
	Data: -
	Precondition: -
	Postcondition: -
	*/
	Vector();

	/*Description: the destructor of the vector
	Data: -
	Precondition: -
	Postcondition: -
	*/
	~Vector();

	/*Description: the constructor of the vector
	Data: - size
	Precondition: - size is unsigned int
	Postcondition: - size is unsigned int
	Result: - return the size
	*/
	unsigned int		getSize(); 

	/*Description: add element to the end of vector
	Data: - elem
	Precondition: - elem is of type T
	Postcondition: - the vector has a new element
	*/
	void				addLast(T elem); //function that add T element to the end of the vector
	
	/*Description: removes one element from vector by position
	Data: - position
	Precondition: - position is of type unsigned int
	Postcondition: - the vector lost one element
	*/
	void				remove(unsigned int position); //function that removes element by position
	
	/*Description: insert element in vector by position
	Data: - position, newElem
	Precondition: - position is unsigned int, newElem is of type T
	Postcondition: - the vector has a new element
	*/
	void				insert(unsigned int position, T newElem); //function that inserts an element in a given position
	
	/*Description: change the value of an element by position
	Data: - position, newElem
	Precondition: - position is unsigned int, newElem is of type T
	Postcondition: - the vector's element = newElem
	*/
	void				update(unsigned int position, T newElem); //change the value of an element
	
	/*Description: return the hole vector
	Data: - 
	Precondition: - 
	Postcondition: - 
	Return: - pointer to vector
	*/
	T*					getAll(); //function that return the hole list of elements
	
	/*Description: return an element from vector by position
	Data: - position
	Precondition: - position is of type unsigned int
	Postcondition: - 
	Return: - return element from vector
	*/
	T					getElement(unsigned int position); //function that return an element bases by position

private:
	/*Description: reallocate memmory in vector if is full
	Data: - 
	Precondition: - size of vector must be equal with capacity
	Postcondition: - capacity is increasead
	*/
	void				reallocate(); //private function that reallocates the vector when it is full
};

template<typename T>
unsigned int Vector<T>::getSize(){
	return size;
}

template<typename T>
void Vector<T>::update(unsigned int position, T newElem){
	elements[position] = newElem;
}

template<typename T>
void Vector<T>::addLast(T elem){
	if (size >= capacity)
		reallocate();
	elements[size] = elem;
	size++;

}
template<typename T>
void Vector<T>::insert(unsigned int position, T newElem){
	if (size >= capacity)
		reallocate();
	
	for (unsigned int i = size; i > position; i--){
		elements[i] = elements[i - 1];
	}
	elements[position] = newElem;
	size++;
	

}

template<typename T>
void Vector<T>::remove(unsigned int position){
	for (unsigned int i = position; i < size - 1; i++){
		elements[i] = elements[i + 1];
	}
	size--;
}

template<typename T>
Vector<T>::Vector()
{
	capacity = 20;
	elements = new T[capacity];
	size = 0;
}


template<typename T>
void Vector<T>::reallocate(){
	capacity += capacity / 2;
	T* newElements = new T[capacity];
	for (unsigned int i = 0; i < getSize(); i++){
		newElements[i]=elements[i];
	}
	delete []elements;
	elements = newElements;
}

template<typename T>
T* Vector<T>::getAll(){
	return elements;
}

template<typename T>
T Vector<T>::getElement(unsigned int position){
	return elements[position];
}

template<typename T>
Vector<T>::~Vector()
{
	delete []elements;
}
