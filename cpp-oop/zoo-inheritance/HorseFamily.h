#pragma once
#include "Vegeterians.h"

class HorseFamily :public  Vegeterians {
protected:
    virtual void inner_fitness() const;

public:

    HorseFamily();
    HorseFamily(string type);
    ~HorseFamily();

};

