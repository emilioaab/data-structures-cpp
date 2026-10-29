#pragma once
#include "Animal.h"

class NotMobile:public Animal {
protected:
    virtual void inner_feed()const = 0;
    virtual void inner_view()const;
public:
    NotMobile();
    NotMobile( string type );
    virtual ~NotMobile();
};




