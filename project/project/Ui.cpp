#include "stdafx.h"
#include "Ui.h"


Ui::Ui(Controller* controller)
{
	this->controller = controller;
	this->menu = new Menu();
}

void Ui::run(){
	menu->show();
	int answer = 0;
	do{
		std::cout << " >";
		std::cin >> answer;
		if (!std::cin.fail()){
			if (answer == 1){
				showBalloons();
			}
			else if (answer == 2){
				solveWithDV();
			}
			else if (answer == 3){
				solveWithTree();
			}
			else if (answer == -1){

			}
			else{
				std::cout << "Wrong input!" << std::endl;
			}
		}
		else{
			std::cin.clear(); /*In case a string is given as input beside int*/
			std::cout << "Wrong number!" << std::endl;
			answer = 0;
			std::cin.ignore();
		}
	} while (answer != -1);
}

void Ui::showBalloons(){

	auto iter = controller->getSsortedListOverDV()->getIterator();
	
	std::cout << "\nAll balloons are (left-right side):\n ";
	while (iter.hasNext()){
		auto element = iter.getCurrent();
		std::cout << element.getLeft() << "-" << element.getRight() << "  ";
	}
	std::cout << std::endl;
	iter = controller->getSsortedListOverDV()->getIterator();
	while (iter.hasNext()){
		auto element = iter.getCurrent();
		unsigned int i = 0;
		for (i; i < element.getLeft(); i++){
			std::cout << " ";
		}
		for (unsigned int j = i; j < element.getRight(); j++){
			std::cout << "-";
		}
		std::cout << std::endl;
	}
}
void Ui::solveWithDV(){
	clock_t tStart = clock();
	auto nonCollisioList = controller->solveBallonsDV();
	printf("Time taken to solve the problem: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	auto iter = nonCollisioList->getIterator();
	std::cout << "\nThe balloons that not collide are: \n";
	while (iter.hasNext()){
		auto element = iter.getCurrent();
		std::cout << element.getLeft() << "-" << element.getRight() << "  ";
	}
	std::cout << std::endl;
	iter = nonCollisioList->getIterator();
	while (iter.hasNext()){
		auto element = iter.getCurrent();
		unsigned int i = 0;
		for (i; i < element.getLeft(); i++){
			std::cout << " ";
		}
		for (unsigned int j = i; j < element.getRight(); j++){
			std::cout << "-";
		}
		std::cout << std::endl;
	}
}
void Ui::solveWithTree(){
	clock_t tStart = clock();
	auto nonCollisioList = controller->solveBalloonsBST();
	printf("Time taken to solve the problem: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	auto iter = nonCollisioList->getIterator();
	std::cout << "\nThe balloons that not collide are: \n";
	while (iter.hasNext()){
		auto element = iter.getCurrent();
		std::cout << element.getLeft() << "-" << element.getRight() << "  ";
	}
	std::cout << std::endl;
	iter = nonCollisioList->getIterator();
	while (iter.hasNext()){
		auto element = iter.getCurrent();
		unsigned int i = 0;
		for (i; i < element.getLeft(); i++){
			std::cout << " ";
		}
		for (unsigned int j = i; j < element.getRight(); j++){
			std::cout << "-";
		}
		std::cout << std::endl;
	}
}


Ui::~Ui()
{
	delete menu;
}
