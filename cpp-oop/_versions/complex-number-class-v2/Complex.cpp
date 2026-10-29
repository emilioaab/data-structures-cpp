#include "Complex.h"

Complex::Complex() { //default constructor without parameters initializes the object in zeros
    real = 0; //real is the real of the object
    imaginary = 0; //imaginary is the imaginary of the object
}

Complex::Complex(double real) { //constructor with one parameter(real number)
    this->real = real; //this->real is the real of the object
    imaginary = 0; //imaginary is the imaginary of the object
}

Complex::Complex(double real, double imaginary) { //constructor with two parameters(real and imaginary numbers)
    this->real = real; //this->real is the real of the object
    this->imaginary = imaginary; //imaginary is the imaginary of the object
}

Complex::~Complex() { //destructor

}

void Complex::setReal(double real) { //setters are methods that change the object
    this->real = real; //this->real is the real of the object
}

void Complex::setImaginary(double imaginary) { //setters are methods that change the object
    this->imaginary = imaginary; //imaginary is the imaginary of the object
}

double Complex::getReal() const { //const means that the method does not change the object
    return this->real; //return the real of the object
}

double Complex::getImaginary() const { //const means that the method does not change the object
    return this->imaginary; //return the imaginary of the object
}


string Complex::toString() const { //string representation of the complex number


    return to_string(real) + (imaginary == 0 ? "" : (imaginary > 0 ? "+" : "") + to_string(imaginary) +
                                                    "i"); //return the string representation of the object
}

Complex &Complex::operator=(const Complex &other) {
    this->real = other.real; //this->real is the real of the object
    this->imaginary = other.imaginary; //imaginary is the imaginary of the object
    return (*this); //return the object
}

bool Complex::operator==(const Complex &other) const { //const means that the method does not change the object
    return real == other.real && imaginary ==
                                 other.imaginary; //return true if the real and imaginary of the object are equal to the real and imaginary of the other object
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this ==
             other); //return true if the real and imaginary of the object are not equal to the real and imaginary of the other object
}

Complex Complex::operator+(const Complex &other) const { //
    return Complex(real + other.real, imaginary +
                                      other.imaginary);//return the sum of the real and imaginary of the object and the real and imaginary of the other object
}


Complex Complex::operator+(double real) const { //
    return Complex(this->real + real, imaginary); //
}


Complex &Complex::operator+=(const Complex &other) { //
    real += other.real;//
    imaginary += other.imaginary;
    return (*this);
}


Complex &Complex::operator+=(double real) {//real number
    this->real += real;
    return (*this);
}

Complex &Complex::operator++() {//prefix
    real++;
    return (*this);
}

Complex Complex::operator++(int) {//postfix
    Complex temp = *this;
    real++;
    return temp;
}


double Complex::operator!() const {//length
    return sqrt(real * real + imaginary * imaginary);
}

Complex::operator const double() const {//cast to double
    return real + imaginary;
}

ostream &operator<<(ostream &out, const Complex &complex) {//output
    return out << complex.toString();//print the string representation of the object and return the output
}

istream &operator>>(istream &in, Complex &complex) { //input
    string str; //create a string
    in >> str;  //get the input
    int pos = str.find(':'); //find the position of the :
    complex.real = stod(str.substr(0, pos)); //convert the string to double
    complex.imaginary = stod(str.substr(pos + 1)); //convert the string to double
    return in; //return the input
}
