#include "Animal.h"

Animal::Animal() : type("Animal") {} //DEFAULT CONSTRUCTOR

Animal::Animal( string type ) : type(type) {}

Animal::~Animal() {} //DESTRUCTOR

void Animal::feed()const {
    cout << type << endl;
    inner_feed();
}

void Animal::view()const {
    cout << type << endl;
    inner_view();
}


