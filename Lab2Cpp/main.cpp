#include <iostream>

using namespace std;

class Rational {
private:
    int numerator;   // above "/"
    int denominator; // under "/"

public:
    int getNumerator() {
        cout << "Please insert a numerator:" << endl;
        cin >> numerator;
        return numerator;
    };

    int getDenominator() {
        cout << "Please insert a denominator:" << endl;
        cin >> denominator;
        return denominator;
    };

    void setNumerator(int num) {
        numerator = num;
        cout << numerator << endl;
    };

    void setDenominator(int num) {
        denominator = num;
        cout << denominator << endl;
    };


};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
