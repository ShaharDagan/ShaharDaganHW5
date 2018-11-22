#include "Shape.h"

Shape::Shape(const string & name, const string & type)
{
	//set name and type to the attriubutes of the class
	this->_name= name;
	this->_type = type;
}

void Shape::printDetails() const
{
	//print the type and the name 
	cout << this->_type.c_str()<<"  " << this->_name.c_str() << "\t";
}

string Shape::getType()const 
{
	return this->_type;
}
string Shape::getName() const
{
	return this->_name;
}
