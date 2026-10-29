#include "Corals.h"

Corals::Corals() :NotMobile("Corals") {
}

Corals::~Corals() {
}

void Corals::inner_feed() const {
    cout << "Feeding on a variety of small sea-organisms." << endl;
}

