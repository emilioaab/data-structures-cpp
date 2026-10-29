#pragma once
#include "Mobile.h"

class Vegeterians : public Mobile {
protected:
    virtual void inner_feed() const;

    virtual void inner_view() const;

    virtual void inner_fitness() const = 0;

    public:
    Vegeterians();
    Vegeterians(string type);
    ~Vegeterians();

};
