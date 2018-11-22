#pragma once
#include <iostream>
#include "Point.h"
#include "CImg.h"

using namespace std;

class Shape 
{
public:
	Shape(const string& name, const string& type);/*Constructor set 2 string to the properties*/
	

	virtual double getArea() const = 0;//pure virtual function for the area 
	virtual double getPerimeter() const = 0;//pure virtual function for the perimeter
	virtual void draw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board) = 0;
	virtual void move(const Point& other) = 0; // add the Point to all the points of shape
	void printDetails() const;//print the type and the name
	string getType() const;//return the type property 
	string getName() const;//return the name property

	virtual void clearDraw(cimg_library::CImgDisplay& disp, cimg_library::CImg<unsigned char>& board) = 0;

private:
	string _name;//name of shape
	string _type;//type of shape

protected:
	
	std::vector<cimg_library::CImg<unsigned char>> _graphicShape;
};