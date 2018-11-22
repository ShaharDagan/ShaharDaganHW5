#include "Point.h"

Point::Point()
{
}

Point::Point(int x, int y)
{
	//Constructor to create point from x and y coords
	this->_x = x;
	this->_y = y;
}

Point::Point(const Point & other)
{
	//create point from other point
	this->_x = other.getX();
	this->_y = other.getY();
}

Point::~Point()
{
}

Point Point::operator+(const Point & other) const
{
	//add the coordinates of points
	return Point(this->_x + other.getX(),this->_y+other.getY());
}

Point & Point::operator+=(const Point & other)
{
	//add point
	this->_x += other.getX();
	this->_y += other.getY();
	return (*this);
}

int Point::getX() const
{
	//get x property
	return this->_x;
}

int Point::getY() const
{
	return this->_y;
}

double Point::distance(const Point & other) const
{
	//get distance between 2 points
	return sqrt(pow(other.getX() - this->_x,2)+pow(other.getY()-this->_y,2));
}
