#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Complex {

private:
    double real; //real number
    double imaginary; //imaginary number

public:
    //methods
    Complex(); //default constructor without parameters initializes the object in zeros
    Complex(double real); //constructor with one parameter(real number)
    Complex(double real, double imaginary); //constructor with two parameters(real and imaginary numbers)
    ~Complex(); //destructor

    //setters
    void setReal(double real); //
    void setImaginary(double imaginary); //setters are methods that change the object

    //getters
    double getReal() const;

    double getImaginary() const; //const means that the method does not change the object
    // all the comments here are applied also on the ComplexArray methods.
    string toString() const; //string representation of the complex number
    Complex &operator=(const Complex &other); //assignment Complex a=b=c=d;
    bool operator==(const Complex &other) const; //equal
    bool operator!=(const Complex &other) const; //not equal

    Complex operator+(const Complex &) const; //complex number if(a+b == 0)  Complex a= b+c //why we dont return in refernece? because we create a new temporary object and it will be destroyed after the method is done beacuse of the stack
    Complex operator+(double real) const; //real number
    Complex &operator+=(const Complex &); //complex number a+=b+=c
    Complex &operator+=(double real); //real number
    Complex &operator++(); //prefix ++a
    Complex operator++(int); //postfix a++
    double operator!() const; //length from (0,0) |z| absolute value
    operator const double() const; //cast to double
    friend ostream &operator<<(ostream &out, const Complex &complex); //output
    friend istream &operator>>(istream &in, Complex &complex); //input


};


