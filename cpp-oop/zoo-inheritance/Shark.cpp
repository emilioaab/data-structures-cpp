#include "Shark.h"

Shark::Shark():Predators("Shark", "Fish") {}

Shark::~Shark() {}

void Shark::inner_view() const {
    cout << "Water diving." << endl;
}
