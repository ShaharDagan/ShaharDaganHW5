#include "Triangle.h"

void Triangle::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char GREEN[] = { 0, 255, 0 };
	board.draw_triangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(),
		_points[2].getX(), _points[2].getY(), GREEN, 100.0f).display(disp);
}

void Triangle::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };
	board.draw_triangle(_points[0].getX(), _points[0].getY(),
		_points[1].getX(), _points[1].getY(),
		_points[2].getX(), _points[2].getY(), BLACK, 100.0f).display(disp);
}

Triangle::Triangle(const Point & a, const Point & b, const Point & c, const string & type, const string & name):Polygon(type,name)
{
	this->_points.push_back(a);
	this->_points.push_back(b);
	this->_points.push_back(c);
}

Triangle::~Triangle()
{
	this->_points.clear();
}

double Triangle::getArea() const
{
	double area = 0.0;
	int j = this->_points.size() - 1;
	for (int i = 0; i < _points.size(); i++)
	{
		area += (this->_points[j].getX() + this->_points[i].getX()) * (this->_points[j].getY() - this->_points[i].getY());
		j = i;  // j is previous vertex to i 
	}
	return abs(area / 2.0);
}

double Triangle::getPerimeter() const
{
	double side1 = this->_points[0].distance(this->_points[1]);
	double side2 = this->_points[0].distance(this->_points[2]);
	double side3 = this->_points[1].distance(this->_points[2]);
	return side1+side2+side3;
}
