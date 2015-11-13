#include "stdafx.h"
#include "Controller.h"


Controller::Controller(Repository* repository)
{
	this->repository = repository;
}


SortedListOverBST<Balloon, int>* Controller::solveBalloonsBST(){
	SortedListOverBST<Balloon, int>*nonCollisionBalloons = new SortedListOverBST<Balloon, int>();
	auto iter = repository ->getSortedListOverBST()->getIterator();
	while (iter.hasNext()){
		nonCollisionBalloons->insert(iter.getCurrent());
	}

	iter = repository->getSortedListOverBST()->getIterator();
	while (iter.hasNext()){
		auto elem = iter.getCurrent();
		//std::cout << elem.getLeft() << "--" << elem.getRight() << std::endl;
	}

	//std::cout << nonCollisionBalloons->getSize();
	int size = nonCollisionBalloons->getSize();
	
	for (int i = 0; i < nonCollisionBalloons->getSize() - 1; i++){
		auto elem1 = nonCollisionBalloons->getElement(i);
		auto elem2 = nonCollisionBalloons->getElement(i + 1);
		if (elem1.getRight() > elem2.getLeft()){
			if (elem1.getRight() - elem1.getLeft() >= elem2.getRight() - elem2.getLeft()){
				nonCollisionBalloons->deleteElement(i);
			}
			else{
				nonCollisionBalloons->deleteElement(i + 1);
			}
			i--;
			
		}
	}


	//return the list with the balloons that do not collide
	return nonCollisionBalloons;
}

SortedListOverDV<Balloon>* Controller::solveBallonsDV(){
	SortedListOverDV<Balloon>*nonCollisionBalloons = new SortedListOverDV<Balloon>();
	//make a copy of the vector and work on that copy
	auto iter = repository->getSortedListOverDV()->getIterator();
	while (iter.hasNext()){
		nonCollisionBalloons->insert(iter.getCurrent());
	}

	//parse the vector and search for collisions
	//if collision found, remove one balloon
	for (int i = 0; i < nonCollisionBalloons->getSize() - 1; i++){
		auto elem1 = nonCollisionBalloons->getElement(i);
		auto elem2 = nonCollisionBalloons->getElement(i + 1);
		if (elem1.getRight() > elem2.getLeft()){
			if (elem1.getRight() - elem1.getLeft() >= elem2.getRight() - elem2.getLeft()){
			nonCollisionBalloons->deleteElement(i);
			}
			else{
				nonCollisionBalloons->deleteElement(i + 1);
			}
			i--;
		}
	}

	//return the list with the balloons that do not collide
	return nonCollisionBalloons;
}

SortedListOverDV<Balloon>* Controller::getSsortedListOverDV(){
	return repository->getSortedListOverDV();
}


Controller::~Controller()
{
}
