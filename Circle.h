#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>
#define PI 3.14

class Circle : public Shape
{
public:
	//constructor 
	Circle(const Point& center, double radius, const string& type, const string& name);//constructor receive the center point and the radius of the circle
	~Circle();

	virtual double getArea() const;//return the area of the circle 
	virtual double getPerimeter() const;//return the perimeter
	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	virtual void move(const Point& other);//move the circle 

	const Point& getCenter() const;//return the center point of the circle
	double getRadius() const;//return the radius of the circle

private:
	double _radius;
	Point _center;
};