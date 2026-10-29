#include "Complex.h"

Complex::Complex():_real(0),_imagine(0)
{
}

Complex::Complex(double real):_real(real),_imagine(0)
{
}

Complex::Complex(double real, double image)
{
	this->_real = real;
	this->_imagine = image;
}

Complex::~Complex()
{
}

string Complex::toString() const
{
	if (!_real && !_imagine)
		return "0";
	string str = "";
	if(_real != 0.)
		str+=to_string(_real);

	if (_imagine < 0.)
		str += _imagine == -1. ? "-" : to_string(_imagine);
	else if(_imagine > 0.)
	{
		if (_real != 0.)
			str += "+";
		if (_imagine != 1.)
			str += to_string(_imagine);
	}
	
	if (_imagine != 0.)
		str += "i";

	return str;
}

Complex& Complex::operator=(const Complex& other)
{
	this->_real = other._real;
	this->_imagine = other._imagine;
	return (*this);
}

bool Complex::operator==(const Complex& other) const
{
	return this==&other || (this->_real==other._real && this -> _imagine==other._imagine) ;
}

bool Complex::operator!=(const Complex& other) const
{
	return !this->operator==(other);
}

Complex Complex::operator+(const Complex& other) const
{
	return Complex(this->_real+other._real,this->_imagine+other._imagine);
}

Complex Complex::operator+(double r) const
{
	return Complex(_real+r,_imagine);
}

Complex& Complex::operator+=(const Complex& other)
{
	*this = *this + other;
	return *this;
}

Complex& Complex::operator+=(double r)
{
	_real+= r;
	return *this;
}

Complex& Complex::operator++()
{
	++_real;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex temp = *this;
	(_real)++;
	return temp;
}

double Complex::operator!() const
{

	return sqrt(pow(_real,2)+pow(_imagine,2));
}

Complex::operator const double() const
{
	return _real + _imagine;
}

ostream& operator<<(ostream& output, const Complex& c)
{
	return output << c.toString();////////////////////////////////////////////////
}

istream& operator>>(istream& input, Complex& c)
{
	cout <<"enter real part:";
	input >> c._real;
	cout << " enter imagine part:";
	input >> c._imagine;
	return input;

}
