#pragma once
#include "SortedListOverDV.h"
#include "Balloon.h"
#include "Menu.h"
#include "Controller.h"
#include <time.h>
class Ui
{
public:
	Ui(Controller* controller);
	~Ui();
	void run();
private:
	void showBalloons();
	void solveWithDV();
	void solveWithTree();

private:
	Controller* controller;
	Menu* menu;
};

