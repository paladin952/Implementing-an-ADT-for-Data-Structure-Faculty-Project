#include "stdafx.h"
#include <string>
#include <iostream>
#include <assert.h>
#include "SortedListOverBST.h"
#include "SortedListOverDV.h"
#include "Balloon.h"
#include "Vector.h"
#include "BST.h"
#include <fstream>
#include <sstream>
#include "Repository.h"
#include "Controller.h"
using namespace std;

class Tests{

private:
	SortedListOverDV<int>*sortedListDV;
	SortedListOverBST<Balloon, int>* sortedListBST;
	Vector<int>* vector;
	Repository* repository;
	Controller* controller;
	BST<Balloon, int>* bst;

public:
	Tests(){
		sortedListBST = new SortedListOverBST<Balloon, int>();
		sortedListDV = new SortedListOverDV<int>();
		vector = new Vector < int > ;
		repository = new Repository("test1.txt");
		controller = new Controller(repository);
		bst= new BST<Balloon, int>();
	}

	~Tests(){
		delete sortedListDV;
		delete sortedListBST;
		delete vector;
		delete repository;
		delete controller;
		delete bst;
	}

	void testBalloons(){
		Balloon bal1(2, 3);
		assert(bal1.getLeft() == 2);
		assert(bal1.getRight() == 3);

		Balloon bal2(3, 3);
		assert(bal1 < bal2);
	}

	void testDV(){
		sortedListDV->insert(1);
		assert(sortedListDV->getSize() == 1);
		assert(sortedListDV->getElement(0) == 1);

		sortedListDV->insert(3);
		assert(sortedListDV->getSize() == 2);
		assert(sortedListDV->getElement(1) == 3);

		sortedListDV->deleteElement(0);
		assert(sortedListDV->getSize() == 1);
		assert(sortedListDV->getElement(0) == 3);
	}

	void testSortedListBFS(){
		Balloon bal1(2, 3);
		sortedListBST->insert(bal1);
		assert(sortedListBST->getSize() == 1);
		assert(sortedListBST->getElement(0).getLeft() == 2);

		Balloon bal2(5, 10);
		sortedListBST->insert(bal2);
		assert(sortedListBST->getSize() == 2);
		assert(sortedListBST->getElement(1).getRight() == 10);
		
		sortedListBST->deleteElement(0);
		assert(sortedListBST->getSize() == 1);
		assert(sortedListBST->getElement(0).getRight() == 10);
	}

	void testVectorClass(){
		vector->addLast(1);
		vector->addLast(2);
		assert(vector->getSize() == 2);
		vector->insert(0, 100);
		assert(vector->getElement(0) == 100);
		

		vector->remove(0);
		assert(vector->getSize() == 2);	
	}

	void testExecutionTime(){
		std::cout << "Time testing: ";
		clock_t tStart = clock();
		controller->solveBallonsDV();
		printf("Time taken to solve the problem with DV: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	
	
		std::cout << "Time testing: ";
		tStart = clock();
		controller->solveBallonsDV();
		printf("Time taken to solve the problem with BFS: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	
	}


	void testBFSClass(){
		Balloon bal1(1, 2);
		Balloon bal2(1, 4);
		bst->AddNode(bal1, NULL);
		bst->AddNode(bal2, NULL);
		assert(bst->GetRoot()->GetKey().getLeft() == 1);
		bst->DeleteNode(bal1);
		assert(bst->GetRoot()->GetKey().getLeft() == 1);
		//bst->DeleteNode(bal2);
		//bst->Walk(bst->GetRoot());
		
	}

	void testAll(){
		testDV();
		testBalloons();
		testSortedListBFS();
		testVectorClass();
		testExecutionTime();
		testBFSClass();
	}

	
};