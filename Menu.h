#pragma once
#include "Circle.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CImg.h"
#include <vector>
#include <iostream>
#include <sstream>


class Menu
{
public:

	Menu();
	~Menu();
	void mainLoop();
	Point getPoint(int n);//get from the user a point information
	void addShape();
	int optionMenu() const;
	void getName()const;
	// more functions..
	void modifyShapes();
private: 
	vector<Shape*>  _shapes;
	cimg_library::CImg<unsigned char>* _board;
	cimg_library::CImgDisplay* _disp;
};

