#include "Zoo.h"

Zoo::Zoo()
{
    animalCount = 0;
    mobileCount = 0;
    lionCount = 0;

    for(int i = 0; i < 200; i++)
    {
        animals[i] = nullptr;
    }
    for(int i = 0; i < 100; i++)
    {
        mobileAnimals[i] = nullptr;
        lions[i] = nullptr;
    }

}

Zoo::~Zoo(){

for(int i = 0; i < animalCount; i++)
        delete animals[i];
}

void Zoo::AddAnimal(Animal* animal){
    if (animalCount < 200){
        animals[animalCount++]=animal;

        if (dynamic_cast<Mobile*>(animal)){ //RTTI
            mobileAnimals[mobileCount++]=dynamic_cast<Mobile*>(animal);
        }
        if(dynamic_cast<Lion*>(animal)){ //RTTI
            lions[lionCount++]=dynamic_cast<Lion*>(animal);
        }
    }
}

void Zoo::Feed(){
    for(int i = 0; i < animalCount; i++)
        animals[i]->feed();
}

void Zoo::Show(){
    for(int i = 0; i < animalCount; i++)
        animals[i]->view();
}

void Zoo::Fitness(){
    for(int i = 0; i < mobileCount; i++)
        mobileAnimals[i]->fitness();
}

void Zoo::LionShow(){
    for(int i = 0; i < lionCount; i++)
        lions[i]->LionShow();
}
