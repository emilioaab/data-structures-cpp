#include "Wolf.h"


Wolf::Wolf():Predators("Wolf", "Rabbit") {}

Wolf::~Wolf() {}

void Wolf::inner_view() const {
    cout << "Joyful running and flapping their tail." << endl;
}



