#pragma once
#include "NotMobile.h"

class Sponges:public NotMobile {
protected:
    virtual void inner_feed()const;
public:
    Sponges();
    virtual ~Sponges();

};
