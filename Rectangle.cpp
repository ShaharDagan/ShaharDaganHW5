#include "Rectangle.h"

void myShapes::Rectangle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char WHITE[] = { 255, 255, 255 };
	board.draw_rectangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(), WHITE, 100.0f).display(disp);
}

void myShapes::Rectangle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0};
	board.draw_rectangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(), BLACK, 100.0f).display(disp);
}

myShapes::Rectangle::Rectangle(const Point & a, double length, double width, const string & type, const string & name):Polygon(type,name)
{
	//add the points of the rectangle
	Point b = Point(a.getX() + width, a.getY());
	Point c = Point(a.getX(), a.getY() + length);	
	Point d= Point(a.getX() + width, a.getY() + length);
	this->_points.push_back(a);
	this->_points.push_back(b);
	this->_points.push_back(c);
	this->_points.push_back(d);
}

myShapes::Rectangle::~Rectangle()
{
}

double myShapes::Rectangle::getArea() const
{
	int width = this->_points[1].getX() - this->_points[0].getX();
	int height = this->_points[2].getY() - this->_points[1].getY();
	return width * height;
}

double myShapes::Rectangle::getPerimeter() const
{
	int width = this->_points[1].getX() - this->_points[0].getX();
	int height = this->_points[2].getY() - this->_points[1].getY();
	return width*2+height*2;
}
