#pragma once
#include "Predators.h"

class Lion:public Predators {
protected:
    virtual void inner_view() const;

public:
    Lion();
    ~Lion();
    void LionShow();

};


