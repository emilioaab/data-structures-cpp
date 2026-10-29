#pragma once
#include "Mobile.h"

class Predators : public Mobile {
private:
    string favouriteFood;
protected:
    virtual void inner_view() const = 0;
    virtual void inner_feed() const;
    virtual void inner_fitness() const;
public:
    Predators();
    Predators(string type, string favouriteFood);
    ~Predators();

};

