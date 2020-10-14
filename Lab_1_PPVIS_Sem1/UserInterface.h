#pragma once

#include "Rectangle.h"
#include <iostream>
using namespace std;

class FiguresOperator
{
public:
	FiguresOperator();

	void toProcessRectangle();
};

class Lists
{
public:
	void PrintermainMenuList();
};

class UserInterface
{
private:
	FiguresOperator commander;
	Lists mainMenu;

public:
	UserInterface();

	void confirm();
	void Menu();
};