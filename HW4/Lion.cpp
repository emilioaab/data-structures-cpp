#include "Lion.h"

Lion::Lion():Predators("Lion", "Gnu") {}

Lion::~Lion() {}

void Lion::inner_view() const {
    cout << "Royal walking in the garden." << endl;
}

void Lion::LionShow() {
    cout << "Hunting!" << endl;
}