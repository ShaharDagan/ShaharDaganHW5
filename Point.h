#pragma once
#include <vector>
//#include "CImg.h"

class Point
{
public:
	Point();
	Point(int x, int y);//constructor to create point with x and y
	Point(const Point& other);//constructor to create point from an exsiting point
	virtual ~Point();
	
	Point operator+(const Point& other) const; //return a new point with the coordinates added
	Point& operator+=(const Point& other);//change the current point and increase it

	int getX() const;//get the x coord of point
	int getY() const;//get the y coord of point

	double distance(const Point& other) const;//calcualte the distance between the current point and other point
private:
	int _x;//the x coord property
	int _y;//the y coord property
	
};