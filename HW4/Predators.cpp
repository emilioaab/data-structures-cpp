#include "Predators.h"

Predators::Predators():Mobile("Predators")  { this -> favouriteFood = "meat"; }

Predators::Predators(string type, string favouriteFood):Mobile(type), favouriteFood(favouriteFood) {}

Predators::~Predators() {}

void Predators::inner_feed() const {
    cout << "Preying! Eating " << favouriteFood<< "! Yummy! " << endl;
}

void Predators::inner_fitness() const {
    cout << "Running after potential food." << endl;
}
