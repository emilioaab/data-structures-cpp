//
// Created by Emil Abdumalikov on 11/07/2023.
//

#ifndef LAB2CPP_HEADER_H
#define LAB2CPP_HEADER_H
#endif //LAB2CPP_HEADER_H

using namespace std;

class Rational {
private:
    int numerator;   // above "/"
    int denominator; // under "/"

public:
    int getNumerator() ;

    int getDenominator();

    void setNumerator();

    void setDenominator();

    Rational ReduceFrac();

    Rational GetRationalFrac();

    int GCD(int a, int b);

};


