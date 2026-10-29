#pragma once
#include "Address.h"

class Student {
private:
    char* name;
    const Address* schoolAddress;
    Address homeAddress;
public:
    Student(char* name, const Address& school, const Address& home);
    Student(const Student& other);
    ~Student();

    const Address& getHomeAddress() const {return homeAddress;}
    Address& getHomeAddress() {return homeAddress;}

    void show() const;


};
