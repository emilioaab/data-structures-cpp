#pragma once
#include "Lion.h"

class Zoo{
private:
    Animal* animals[200];
    int animalCount;
    Mobile* mobileAnimals[100];
    int mobileCount;
    Lion* lions[100];
    int lionCount;
public:
    Zoo();
    ~Zoo();
    void AddAnimal(Animal* animal);
    void Feed();
    void Show();
    void Fitness();
    void LionShow();



};



