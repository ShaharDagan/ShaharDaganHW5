#pragma once
#include "Polygon.h"

class Triangle : public Polygon
{
public:
	Triangle(const Point& a, const Point& b, const Point& c, const string& type, const string& name);//constructor of the triangle created by the 3 points with name and type
	virtual ~Triangle();
	virtual double getArea() const; //get the area of triangle
	virtual double getPerimeter() const;// get the permieter of the triangle
	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
};