#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
	
}

void Menu::show(){
	std::cout << "\t\t\t\t\t\tClapa Lucian, Group 913\n";
	std::cout << "\t\t\tWELCOME!!!\n";
	std::cout << "\tPress 1 to show the ballons\n";
	std::cout << "\tPress 2 to solve the problem using dynamic vector\n";
	std::cout << "\tPress 3 to solve the problem using binary search tree:\n";
	std::cout << "\tPress -1 to exit\n" << std::endl;
}
Menu::~Menu()
{
}
