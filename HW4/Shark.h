#pragma once
#include "Predators.h"

class Shark:public Predators{
protected:
    virtual void inner_view() const;

public:
    Shark();
    ~Shark();

};

