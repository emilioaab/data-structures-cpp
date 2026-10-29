#include "SteakFamily.h"
SteakFamily::SteakFamily() : Vegeterians("HorseFamily") {}

SteakFamily::~SteakFamily() {}

SteakFamily::SteakFamily(string type) : Vegeterians(type) {}

void SteakFamily::inner_fitness() const {
    cout << "Walking slowly in the garden." << endl;
}
