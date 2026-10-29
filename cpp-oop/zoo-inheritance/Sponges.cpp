#include "Sponges.h"

Sponges::Sponges():NotMobile("Sponges") {}

Sponges::~Sponges() {}

void Sponges::inner_feed()const {
    cout << "Filtering water flow to obtain food." << endl;
}

