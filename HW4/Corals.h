#pragma once
#include "NotMobile.h"

class Corals :public NotMobile{
protected:
    virtual void inner_feed()const;
public:
    Corals();
    virtual ~Corals();
};




