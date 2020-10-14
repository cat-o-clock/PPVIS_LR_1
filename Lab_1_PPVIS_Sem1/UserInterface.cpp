#include "userInterface.h"

FiguresOperator::FiguresOperator(){}

void FiguresOperator::toProcessRectangle()
{
	int x1, y1, x2, y2;
	cout << "\n\t\t\t\t\t\tInput Rectangle...\n\t\t";
	cin >> x1 >> y1 >> x2 >> y2;

	Rectangle rectangle;
	rectangle.SetRectangle(x1, y1, x2, y2);

	cout << "\t\tThe coordinates of the vertices of the rectangle: ";
	cout << rectangle.GetCoordinates();

	int dx, dy;
	cout << "\t\t\tInput how much do you want to move in x-axis and y-axis\n\t\t";
	cout << "X:"; cin >> dx; cout << "\t\t";
	cout << "Y:"; cin >> dy; 
	rectangle.MoveRectungle(dx, dy);

	cout << "\t\tThe coordinates of the vertices of the rectangle: ";
	cout << rectangle.GetCoordinates();

	int dAmountOfTimes;
	cout << "\t\t\tInput how many times do you want to enlarge the rectangle\n\t\t";
	cin >> dAmountOfTimes;
	rectangle.ResizeRectungle(dAmountOfTimes);

	cout << "\t\tThe coordinates of the vertices of the rectangle:";
	cout << rectangle.GetCoordinates();

	int flag = 0;
	cout << "\t\t\t\t\t\t\tInput:\n\t\t(1) - if you want to increase the rectangle by 1\n\t\t(2) - if you want to decrease the rectangle by 1\n\t\t(0) - if you don't want to change the rectangle \n\t\t";
	cin >> flag;
	if (flag == 1)
	{
		++rectangle;

		cout << "\t\tThe coordinates of the vertices of the rectangle: ";
		cout << rectangle.GetCoordinates();
	}
	else if (flag == 2)
	{
		rectangle--;

		cout << "\t\tThe coordinates of the vertices of the rectangle: ";
		cout << rectangle.GetCoordinates();
	}
	else;

	flag = 0; 
	Rectangle otherRectugle;

	cout << "\t\t\t\t\t\t\tInput:\n\t\t(1) - if you want to summation a rectangle with another\n\t\t(2) - if you want to subtract a rectangle\n\t\t(0) - if you don't want to change the rectangle \n\t\t";
	cin >> flag;
	if (flag != 0) 
	{	
		cout << "\t\tInput Rectangle...\n\t\t";
		int _x1, _x2, _y1, _y2;
		cin >> _x1 >> _y1 >> _x2 >> _y2;
		otherRectugle.SetRectangle(_x1, _y1, _x2, _y2);
	}

	if (flag == 1)
	{
		rectangle += otherRectugle;

		cout << "\t\tThe coordinates of the vertices of the triangle: ";
		cout << rectangle.GetCoordinates();
	}
	else if (flag == 2)
	{
		rectangle = rectangle - otherRectugle;

		cout << "\t\tThe coordinates of the vertices of the triangle: ";
		cout << rectangle.GetCoordinates();
	}
	else;
}

void Lists::PrintermainMenuList()
{
	cout << "\n\n\n\t\t\t\t\t\tCommands\n\n";
	cout << "\t\t\t\t(1) To process some Rectangle\n\n";
	cout << "\t\t\t\t(0) To finish\n\n";
	cout << "\t\tCommand: ";
}

UserInterface::UserInterface()
{
	commander = FiguresOperator();
	mainMenu = Lists();
}

void UserInterface::confirm()
{
	std::cout << "\n\n\nEnter any key to continue...";

	char key;
	cin >> key;
}

void UserInterface::Menu()
{
	char userChoice;

	do
	{
		system("cls");
		mainMenu.PrintermainMenuList();
		cin >> userChoice;

		if (userChoice != '1')
			break;

		system("cls");

		switch (userChoice)
		{
		case '1':
			commander.toProcessRectangle();
			break;

		case '0':
			break;
		}
		confirm();
		
	} while (true);

}
