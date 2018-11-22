#include "Menu.h"


Menu::Menu() 
{
	this->_board  = new cimg_library::CImg<unsigned char>(700, 700, 1, 3, 1);
	this->_disp = new cimg_library::CImgDisplay(*this->_board, "Super Paint");
	
}

Menu::~Menu()
{
	this->_disp->close();
	delete _board;
	delete _disp;
}
void Menu::addShape() 
{
	int option = 5;
	while (option > 3 || option < 0)
	{
		cout << "Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\n";
		cout << "Enter 3 to add a rectangle.\n";
		cin >> option;
	}
	double radius = 0;
	std::string type= "";
	std::string name = "";
	Point a,b,c;
	if (option == 0)
	{
		a = getPoint(-1);
		cout << "Please enter radius:\n";
		cin >> radius;
		getName();
		cin >> name;
		type = "Circle";
		Circle circle = Circle(a, radius, type, name);
		this->_shapes.push_back(&circle);
		circle.draw(*this->_disp, *this->_board);
	}
	else if (option == 1) 
	{
		a = getPoint(0);
		b = getPoint(1);
		getName();
		cin >> name;
		type = "Arrow";
		Arrow arrow = Arrow(a, b,type,name);
		this->_shapes.push_back(&arrow);
		arrow.draw(*this->_disp, *this->_board);
	}
	else if (option == 2)
	{
		a = getPoint(1);
		b = getPoint(2);
		c = getPoint(3);
		getName();
		cin >> name;
		type = "Triangle";
		Triangle  triangle = Triangle(a, b, c,type , name);
		this->_shapes.push_back(&triangle);
		triangle.draw(*this->_disp, *this->_board);
	}
	else if (option == 3) 
	{

		int x = 0,y =0;
		int length =0,width=0;
		cout << "Enter the X of the to left corner:";
		cin >> x;
		cout << "Enter the Y of the to left corner:";
		cin >> y;
		cout << "Please enter the length of the shape:";
		cin >> length;
		cout << "Please enter the width of the shape:";
		cin >> width;
		getName();
		cin >> name;
		type = "Rectangle";
		myShapes::Rectangle rect = myShapes::Rectangle(Point(x, y), length, width, type, name);
		(this->_shapes).push_back(&rect);
		rect.draw(*this->_disp, *this->_board);

	}

}

void Menu::mainLoop()
{
	int option=0;
	while (option != 3) 
	{
		option = optionMenu();
		switch (option)
		{
		case 0:
			addShape();
			break;
		case 1:
			modifyShapes();
			break;
		case 2:
			break;
		}
	}
}

void Menu::modifyShapes()
{
	Point p;
	int n = 0;
	int option2 = 0;
	for (int i = 0; i < this->_shapes.size(); i++)
	{
		cout << "Enter " << i << " for " << "Bug2 "<< "(" << "Bug" << ")";
	}
	cin >> n;
	int x, y = 0;
	cout << "Enter 0 to move the shape\nEnter 1 to get its details.\nEnter 2 to remove the shape.";
	cin >>option2;
	switch (option2)
	{
	case 0:
		cout << "Please enter the X moving scale:\n";
		cin >> x;
		cout << "Please enter the Y moving scale:\n";
		cin >> y;
		p = Point(x, y);
		this->_shapes[n]->move(p);
		break;
	case 1:
		this->_shapes[n]->printDetails();
		cout << this->_shapes[n]->getArea() << this->_shapes[n]->getPerimeter();
		break;
	case 2:
		this->_shapes[n]->clearDraw(*this->_disp, *this->_board);
		this->_shapes.erase(_shapes.begin() + n);
		
		break;
	}
	
}
int Menu::optionMenu() const
{
	int option = 5;
	while (option > 3 || option < 0)
	{
		cout << "Enter 0 to add new shape.\nEnter 1 to modify or get information from a current shape.";
		cout << "\nEnter 2 to delete all of the shapes.\nEnter 3 to exit.\n";
		cin >> option;
	}
	return option;
}
void Menu::getName() const
{
	std::string name = "";
	cout << "Please enter the name of the shape:\n";
	
}

Point Menu::getPoint(int n)
{
	int x = 0, y = 0;
	(n != -1) ? cout <<"Enter the X of point number: " << n<<"\n":cout<<"Please enter X:\n";
	cin >> x;
	(n != -1) ? cout << "Enter the Y of point number: " << n <<"\n": cout << "Please enter Y:\n";
	cin >> y;
	return Point(x,y);
}

