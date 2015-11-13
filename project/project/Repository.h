#pragma once
#include <string>
#include "SortedList.h"
#include "SortedListOverBST.h"
#include "SortedListOverDV.h"
#include "Balloon.h"
#include <sstream>
#include <fstream>
class Repository
{
public:
	/*Description: the constructor that allocates the objects sortedListDV and sortedListBFS
				   and calls the loadFromFile function that stores in memory the positions of the balloons

	Data: - sortedListDV,  sortedListBST, path
	Precondition: - sortedListDV and  sortedListBST are of type SortedList, path is the path in system of the balloons.txt where ballons are stored
	Postcondition: - 
	Result: - the sortedListDV,  sortedListBST contain the balloons read from file
	*/
	Repository(std::string path);
	
	/*Description: the destructor
	Data: -
	Precondition: -
	Postcondition: -
	Result: -
	*/
	~Repository();
	/*Description: function that load from file in memory the balloons
	Data: - 
	Precondition: -
	Postcondition: -
	Result: - the balloons are stored in memory in sortedListDV, and sortedListBFT
	*/
	void loadFromFile(std::string path);

	/*Description: function that return pointer to sortedListDV
	Data: -
	Precondition: - 
	Postcondition: - the sortedListDV is of type SortedList
	Result: - 
	*/
	SortedListOverDV<Balloon>* getSortedListOverDV();

	/*Description: function that return pointer to sortedListBFS
	Data: -
	Precondition: -
	Postcondition: - the sortedListDV is of type SortedList
	Result: -
	*/
	SortedListOverBST<Balloon, int>* getSortedListOverBST();
private:
	/*private fields*/
	SortedListOverDV<Balloon>*sortedListDV;
	SortedListOverBST<Balloon, int>* sortedListBST;
};

