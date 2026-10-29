#pragma once
#include "Complex.h"
class ComplexArray
{
private:
	Complex* _arr;
	int _size;
public:
	ComplexArray();
	ComplexArray(int size);
	ComplexArray(const Complex* arr, int size);
	ComplexArray(const ComplexArray& other);
	~ComplexArray();

	//getters


	//setters


	string toString()const;
	ComplexArray& operator=(const ComplexArray& other);
	bool operator==(const ComplexArray& other)const;
	bool operator!=(const ComplexArray& other)const;
	Complex& operator[](int index);
	ComplexArray operator+(const ComplexArray& other)const;
	ComplexArray& operator +=(const ComplexArray& other);
	ComplexArray& operator +=(const Complex& complex);
	Complex operator!()const;
	friend ostream& operator<<(ostream&output, const ComplexArray& ComplexArray);
	friend istream& operator>>(istream& input, ComplexArray& ComplexArray);
};

