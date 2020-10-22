#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle()
{
	this->x1 = 0;
	this->y1 = 0;
	this->x2 = 0;
	this->y2 = 0;
}

Rectangle::Rectangle(int _x1, int _y1, int _x2, int _y2)
{
	try
	{
		if (_x1 < 0 || _x2 < 0 || _y1 < 0 || _y2 < 0)
			throw RException("Figure must ot have unpositive values of subjects.");
		else
		{
			(_x1 < _x2) ? (x1 = _x1, x2 = _x2) : (x1 = _x2, x2 = _x1);
			(_y1 < _y2) ? (y1 = _y1, y2 = _y2) : (y1 = _y2, y2 = _y1);
		}
	}

	catch (RException& exception)
	{
		cout << exception.what();
	}
}

Rectangle::Rectangle(const Rectangle & other)
{
	this->x1 = other.x1;
	this->x2 = other.x2;
	this->y1 = other.y1;
	this->y2 = other.y2;
}

void Rectangle::SetRectangle(int _x1, int _y1, int _x2, int _y2)
{
	(_x1 < _x2) ? (x1 = _x1, x2 = _x2) : (x1 = _x2, x2 = _x1);
	(_y1 < _y2) ? (y1 = _y1, y2 = _y2) : (y1 = _y2, y2 = _y1);
}

int Rectangle::GetX1() const
{
	return x1;
}

int Rectangle::GetX2() const
{
	return x2;
}

int Rectangle::GetY1() const
{
	return y1;
}

int Rectangle::GetY2() const
{
	return y2;
}

string Rectangle::GetCoordinates() 
{
	return (" A(" + to_string(this->x1) + "," + to_string(this->y1) + "); B(" + to_string(this->x1) + "," + 
		to_string(this->y2) + "); C(" 	+ to_string(this->x2) + "," + to_string(this->y1) + "); D(" + to_string(this->x2) + "," + to_string(this->y2) + ");\n\n\n");
}

void Rectangle::MoveRectungle(int dx,int dy)
{
	x1 += dx;
	x2 += dx;
	y1 += dy;
	y2 += dy;
}

void Rectangle::ResizeRectungle(int AmountOfTimes)
{
	int Temp;
	AmountOfTimes > 0 ? Temp = AmountOfTimes : Temp = 1;
	x2*= Temp;
}

Rectangle Rectangle::operator=(const Rectangle & other)
{
	x1 = other.x1;
	x2 = other.x2;
	y1 = other.y1;
	y2 = other.y2;
	return *this;
}

Rectangle & Rectangle::operator++()
{
	this->x2++;
	this->y2++;
	return *this;
}

Rectangle & Rectangle::operator++(int value)
{
	Rectangle temp(*this);
	this->x2++; this->y2++;
	return temp;
}

Rectangle & Rectangle::operator--()
{
	this->x2--;
	this->y2--;
	return *this;
}

Rectangle & Rectangle::operator--(int value)
{
	Rectangle temp(*this);
	this->x2--; this->y2--;
	return temp;
}

Rectangle Rectangle::operator+(const Rectangle & other)
{
	Rectangle temp;
	other.x1 <= this->x1 ? temp.x1 = other.x1 : temp.x1 = this->x1;
	other.x2 >= this->x2 ? temp.x2 = other.x2 : temp.x2 = this->x2;
	other.y1 <= this->y1 ? temp.y1 = other.y1 : temp.y1 = this->y1;
	other.y2 >= this->y2 ? temp.y2 = other.y2 : temp.y2 = this->y2;

	return temp;
}

Rectangle Rectangle::operator-(const Rectangle & other)
{
	int k = 0;

	if (other.x1 > this->x2 || other.x2<this->x1 || other.y1>this->y2 || other.y2 < this->y1) k = 1;

	if (k == 0)
	{
		int _y1 = (this->y1 >= other.y1) ? this->y1 : other.y1; 
		int _y2 = (this->y2 <= other.y2) ? this->y2 : other.y2; 
		int _x1 = (this->x1 <= other.x1) ? other.x1 : this->x1; 
		int _x2 = (this->x2 >= other.x2) ? other.x2 : this->x2; 
		return Rectangle(_x1, _y1, _x2, _y2);
	}
	else
	{
		cout << "\t\tRectangles don't intersect!\n";
		return Rectangle(0, 0, 0, 0);
	}

}

Rectangle Rectangle::operator+=(const Rectangle & other)
{
	
	other.x1 <= this->x1 ? this->x1 = other.x1 : this->x1 = this->x1;
	other.x2 >= this->x2 ? this->x2 = other.x2 : this->x2 = this->x2;
	other.y1 <= this->y1 ? this->y1 = other.y1 : this->y1 = this->y1;
	other.y2 >= this->y2 ? this->y2 = other.y2 : this->y2 = this->y2;

	return *this;
}

Rectangle Rectangle::operator-=(const Rectangle & other)
{
	*this = *this - other;
	return *this;
}

