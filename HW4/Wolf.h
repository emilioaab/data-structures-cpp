#pragma once
#include "Predators.h"

class Wolf : public Predators {
protected:
    virtual void inner_view() const;

public:
    Wolf();
    ~Wolf();
};



