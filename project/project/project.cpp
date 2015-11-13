// project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include "SortedListOverDV.h"
#include "Balloon.h"
#include <string>
#include <sstream>
#include <fstream>
#include "Ui.h"
#include "Controller.h"
#include "BST.h"
#include "SortedListOverBST.h"
#include "Repository.h"
#include <string>
#include "Tests.h"
void readFromFile(SortedListOverDV<Balloon>* sortedList);
void  solveBallons(SortedListOverDV<Balloon>*sortedList);
void readFromFile(SortedListOverBST<int, Balloon>* sortedListOverBST);
int _tmain(int argc, _TCHAR* argv[])
{

	/*
		The problem is solved in a MVC design pattern
		The datastructures are stored in repository
		The Constructor solves the problem and returns the reuslt
		The ui prints the result
	*/
	//testing

	Tests* tests = new Tests();
	tests->testAll();
	delete tests;
	std::cout << "The tests were successfully!" << std::endl;


	std::string path = "balloons.txt";
	Repository* repository = new Repository(path);
	Controller* controller = new Controller(repository);
	Ui* ui = new Ui(controller);
	ui->run();

	delete repository;
	delete controller;
	delete ui;

	return 0;
}



