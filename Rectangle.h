#pragma once
#include "Polygon.h"

namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
	public:
		// There's a need only for the top left corner 
		Rectangle(const Point& a, double length, double width, const string& type, const string& name);//rectangle constructor receive the point and the length and width with type and name
		virtual ~Rectangle();
		virtual double getArea() const;//return the area of the rectangle
		virtual double getPerimeter() const;//return the perimeter
		virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);
		// override functions if need (virtual + pure virtual)
		virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board);//draw the rectangle
	};
}