#include "Polygon.h"

Polygon::Polygon(const string & type, const string & name):Shape(name,type)
{
}

Polygon::~Polygon()
{
}

void Polygon::move(const Point & other)
{
	//add the each point other paramater
	for (int i = 0; i < (int)this->_points.size(); i++)
	{
		this->_points[i] += other;
	}
}

