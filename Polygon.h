#pragma once

#include "Shape.h"
#include "Point.h"
#include <iostream>
#include <vector>
//#include "Cimg.h"

using namespace std;

class Polygon : public Shape
{
public:
	Polygon(const string& type, const string& name);//constructor  set the type and name 
	virtual ~Polygon();

	// override functions if need (virtual + pure virtual)
	virtual void move(const Point& other);//move the points

protected:
	vector<Point> _points;
};