#include "Mobile.h"

Mobile::Mobile():Animal("Mobile") {}

Mobile::Mobile(string type):Animal(type) {}

Mobile::~Mobile() {}

void Mobile::fitness() const{
    cout << type << endl;
    inner_fitness();
}

