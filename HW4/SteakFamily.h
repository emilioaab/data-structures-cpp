#pragma once
#include "Vegeterians.h"

class SteakFamily: public Vegeterians {

protected:
        virtual void inner_fitness() const;
public:
        SteakFamily();
        SteakFamily(string type);
        ~SteakFamily();
};

