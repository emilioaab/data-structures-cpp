#include "HorseFamily.h"

HorseFamily::HorseFamily() : Vegeterians("HorseFamily") {}

HorseFamily::~HorseFamily() {}

HorseFamily::HorseFamily(string type) : Vegeterians(type) {}

void HorseFamily::inner_fitness() const {
    cout << "Running fast in circles." << endl;
}

