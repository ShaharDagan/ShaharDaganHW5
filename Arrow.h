#pragma once
#include "Polygon.h"

class Arrow : public Shape
{
public:
	Arrow(const Point& a, const Point& b, const string& type, const string& name);//contstructor create an arrow from point a to b with type and name
	~Arrow();//destructor
	virtual double getArea() const;//return 0
	virtual double getPerimeter() const;//return the perimeter
	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	virtual void move(const Point& other);
	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
	

private:
	Point _p1;//point 1
	Point _p2;//point 2
};