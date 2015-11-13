#pragma once
#include "SortedListOverDV.h"
#include "SortedListOverBST.h"
#include "Balloon.h"
#include <iostream>
#include "Repository.h"

class Controller
{
public:
	/*Description: the constructor that injects a Repository pointer to object 
	Data: - repository
	Precondition: - repository is of type Repository pointer
	Postcondition: -
	Result: - 
	*/
	Controller(Repository* repository);

	/*Description: the destructor
	Data: - 
	Precondition: -
	Postcondition: -
	Result: -
	*/
	~Controller();

	/*Description: function that solves the problem using the representation over
	               Dynamic Vector.
				   The ideea of the function is that the balloons are sorted
				   by the left side of them. We go through each balloon in repesentation
				   and we check if the rightSide > leftSide of the next balloon. If yes, we 
				   delete the bigger balloon
	Data: - nonCollinsisonBalloons
	Precondition: - nonCollinsisonBalloons is a copy of the balloons list
	Postcondition: - nonCollinsisonBalloons returns a list with the balloons that do not colide
	Result: - the problem is solved, retunrs a list of noncolisions
	*/
	SortedListOverDV<Balloon>*  solveBallonsDV();

	/*Description: function that solves the problem using the representation over
	Binary search tree.
	The ideea of the function is that the balloons are sorted
	by the left side of them. We go through each balloon in repesentation
	and we check if the rightSide > leftSide of the next balloon. If yes, we
	delete the bigger balloon
	Data: - nonCollinsisonBalloons
	Precondition: - nonCollinsisonBalloons is a copy of the balloons list
	Postcondition: - nonCollinsisonBalloons returns a list with the balloons that do not colide
	Result: - the problem is solved, retunrs a list of noncolisions
	*/
	SortedListOverBST<Balloon, int>* solveBalloonsBST();

	/*Description: returns pointer tot the sortedListOverDV
	*/
	SortedListOverDV<Balloon>* getSsortedListOverDV();

private:
	/*private field repository pointer*/
	Repository* repository;
};

