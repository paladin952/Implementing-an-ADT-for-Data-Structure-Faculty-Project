#pragma once
#include <iostream>



class Balloon
{
private:
	unsigned int left;
	unsigned int right;

public:
	/*Description: - the constructor
	Data: - 
	Precondition: -
	Postcondition: -
	Result: - 
	*/

	Balloon();
	/*Description: - the custom cunstructor that sets value for left and right side of the balloon
	Data: - left, right
	Precondition: - left and irght are unsigned int
	Postcondition: - a new object is created
	*/
	Balloon(unsigned int left, unsigned int right);
	
	/*Description: - the destructor
	Data: -
	Precondition: -
	Postcondition: -
	Result: -
	*/
	~Balloon();

	/*Description: -getters for left and right fields
	Data: -
	Precondition: -
	Postcondition: - left/right are unsigned int
	Result: - returns the left or right side of the balloon
	*/
	unsigned int getLeft(){ return left; };
	unsigned int getRight(){ return right; };

	/*Description: -overload the < operator to check the left side of the balloon
	Data: - someValue
	Precondition: - someValue is of type Balloon
	Postcondition: - 
	Result: - the operator is overloaded
	*/
	inline bool operator<(const Balloon& someValue) const {
		return left < someValue.left;
	}


	/*Description: -overload the > operator to check the left side of the balloon
	Data: - someValue
	Precondition: - someValue is of type Balloon
	Postcondition: -
	Result: - the operator is overloaded
	*/
	inline bool operator>(const Balloon& someValue) const {
		return left > someValue.left;
	}

	inline bool operator <= (const Balloon& someValue) const {
		return left <= someValue.left;
	}

	inline bool operator >= (const Balloon& someValue) const {
		return left >= someValue.left;
	}

	inline bool operator == (const Balloon& someValue) const {
		return left == someValue.left;
	}

	inline friend std::ostream& operator <<(std::ostream& os, const Balloon& dt);
};

std::ostream& operator <<(std::ostream& os, const Balloon& balloon)
{
	os << balloon.left << "-" << balloon.right;
	return os;
}