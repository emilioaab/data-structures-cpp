#pragma once

#include "Complex.h"

//note for life: every method is a function but not every function is a method
class ComplexArray { //class ComplexArray
private: //private members
    Complex *arr; //arr is a pointer to a Complex object
    int size; //size of the array

public: //public members

    ComplexArray(); //default constructor without parameters initializes the object in zeros
    ComplexArray(int arrSize); //constructor with one parameter(size of the array)
    ComplexArray(const Complex* const arr, int arrSize); //constructor with two parameters(array and size of the array)
    ComplexArray(const ComplexArray &other); //copy constructor
    ~ComplexArray(); // destructor


    string toString() const; //return a string of the array
    const ComplexArray &operator=(const ComplexArray &other);//assignment operator //why we do reference here? because we want to return the object itself and make concatonation possible
    bool operator==(const ComplexArray &other) const; //why reference? to avoid copying the object / to avoid having a temporary object.
    bool operator!=(const ComplexArray &other) const;// same same
    Complex &operator[](int index) const;
    ComplexArray operator+(const ComplexArray &other) const;
    ComplexArray &operator+=(const ComplexArray &other); // reference is for concatonation and to avoid of temp objects
    ComplexArray operator+(const Complex &complexNumber) const;
    ComplexArray &operator+=(const Complex &complexNumber); // reference is for concatonation and to avoid of temp objects
    Complex operator!() const;
    friend istream &operator>>(istream &in, ComplexArray &complexArray);
    friend ostream &operator<<(ostream &out, const ComplexArray &complexArray);


};

