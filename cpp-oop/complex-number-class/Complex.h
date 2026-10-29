#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Complex
{
private:
	double _real;
	double _imagine;
public:
	Complex();
	Complex(double real);
	Complex(double real, double image);
	~Complex();

	//setter
	void setReal(double r) { this->_real = r; }
	void setImagine(double i) { this->_imagine = i; }
	//getter
	double getReal()const { return this->_real; }
	double getImagine()const { return this->_imagine; }

	string toString()const;
	Complex& operator=(const Complex& other);
	bool operator==(const Complex&)const;
	bool operator!=(const Complex&)const;
	Complex operator+(const Complex&)const;
	Complex operator+(double r)const;
	Complex& operator +=(const Complex&);
	Complex& operator +=(double r);
	Complex& operator++();//prefix ++a
	Complex operator++(int);//postfix a++
	double operator!()const;
	operator const double()const;
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);

};


