#pragma once
#include <iostream>
#include <string>
#include "Exception.h"
using namespace std;

class Rectangle {

private:
	int x1, y1, x2, y2;

public:
	Rectangle();
	Rectangle(int, int, int, int);
	Rectangle(const Rectangle &other);

	void SetRectangle(int, int, int, int);

	int GetX1() const;
	int GetX2() const;
	int GetY1() const;
	int GetY2() const;
	string GetCoordinates();

	void MoveRectungle(int, int);
	void ResizeRectungle(int);

	Rectangle operator =(const Rectangle &other);

	Rectangle & operator ++ ();
	Rectangle & operator ++ (int value);
	Rectangle & operator -- ();
	Rectangle & operator -- (int value);

	Rectangle operator + (const Rectangle &other);
	Rectangle operator - (const Rectangle &other);

	Rectangle operator += (const Rectangle &other);
	Rectangle operator -= (const Rectangle &other);
};
