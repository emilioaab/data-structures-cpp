#pragma once
#include "Sponges.h"
#include "Corals.h"
#include "Lion.h"
#include "Shark.h"
#include "Wolf.h"
#include "Horse.h"
#include "Zebra.h"
#include "Sheep.h"
#include "Cows.h"
#include "Buffalo.h"
#include "Zoo.h"


class menu {
private:
    Zoo zoo;
    void addAnimal();

public:
    menu();
    ~menu();

    void InsertAnimals();
    void Menu();




};



