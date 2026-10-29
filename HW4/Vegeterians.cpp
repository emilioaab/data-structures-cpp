#include "Vegeterians.h"

Vegeterians::Vegeterians() : Mobile("Vegeterians") {}

Vegeterians::Vegeterians(string type) : Mobile(type) {}

Vegeterians::~Vegeterians() {}

void Vegeterians::inner_feed() const {
    cout << "Eating grass." << endl;
}

void Vegeterians::inner_view() const {
    cout << "Bored staring at the guests." << endl;
}