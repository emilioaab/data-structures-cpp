#pragma once

#include "Animal.h"

class Mobile : public Animal {
protected:
    virtual void inner_feed() const = 0;

    virtual void inner_view() const = 0;

    virtual void inner_fitness() const = 0;

public:
    void fitness() const;
    Mobile();
    Mobile(string type);
    ~Mobile();

};



