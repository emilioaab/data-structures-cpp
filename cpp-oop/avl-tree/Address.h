#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    char* street;
    int houseNumber;
    char* city;

public:
    Address(char* street, int houseNumber, char* city);
    Address(const Address& address);
    ~Address();

    void setStreet(char* street);
    void setCity(char* city);
    void setNumber(int houseNumber) {this->houseNumber = houseNumber;}
    const char* getStreet() const {return street;}
    const char* getCity() const {return city;}
    int getNumber() const {return houseNumber;}

    void show() const;
};

