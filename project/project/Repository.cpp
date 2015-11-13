#include "stdafx.h"
#include "Repository.h"


Repository::Repository(std::string path)
{
	this->sortedListDV = new SortedListOverDV<Balloon>();
	this->sortedListBST = new SortedListOverBST<Balloon, int>();
	loadFromFile(path);
}

void Repository::loadFromFile(std::string path){
	std::string line;
	std::ifstream infile(path);

	while (std::getline(infile, line))
	{
		unsigned int left, right;
		std::istringstream iss(line);

		if (!(iss >> left >> right)) {
			break;
		}
		Balloon balloon(left, right);
		sortedListBST->insert(balloon);
		sortedListDV->insert(balloon);

	}
}

SortedListOverDV<Balloon>* Repository::getSortedListOverDV(){
	return this->sortedListDV;
}
SortedListOverBST<Balloon, int>* Repository::getSortedListOverBST(){
	return this->sortedListBST;
}

Repository::~Repository()
{
	delete sortedListBST;
	delete sortedListDV;
}
