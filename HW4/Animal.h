#pragma once
#include <string>
#include <iostream>

using namespace std;

class Animal {
protected:
     const string type;

    virtual void inner_feed()const = 0;
    virtual void inner_view()const = 0;
public:
    Animal();
    Animal( string type );
    virtual ~Animal();

    void feed()const;
    void view()const;

};



