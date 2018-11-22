#include "Arrow.h"



Arrow::Arrow(const Point & a, const Point & b, const string & type, const string & name):Shape(name,type)
{
	//set the points poperties
	this->_p1 = Point(a);
	this->_p2 = Point(b);
}

Arrow::~Arrow()
{
}

void Arrow::draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char RED[] = { 255, 0, 0 };

	board.draw_arrow(this->_p1.getX(),this-> _p1.getY(),
		this->_p2.getX(), this->_p2.getY(), RED, 100.0f).display(disp);
}
void Arrow::clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board)
{
	unsigned char BLACK[] = { 0, 0, 0 };

	board.draw_arrow(_p1.getX(), _p1.getY(),
		_p2.getX(), _p2.getY(), BLACK, 100.0f).display(disp);
}
void Arrow::move(const Point& other) 
{
	this->_p1 += other;
	this->_p2 += other;
}
double Arrow::getArea() const
{
	//return 0
	return 0.0;
}

double Arrow::getPerimeter() const
{
	//call the distance function
	return this->_p1.distance(this->_p2);
}



