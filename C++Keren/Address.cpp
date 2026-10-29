#include "Address.h"

void Address::setStreet(char *street) {
    delete[] this->street;
    this->street = new char[strlen(street) + 1];
    strcpy(this->street, street);
}

void Address::setCity(char *city) {
    delete[] this->city;
    this->city = new char[strlen(city) + 1];
    strcpy(this->city, city);
}

Address::Address(char *street, int houseNumber, char *city) : street(NULL), city(NULL) {
    setNumber(houseNumber);
    setCity(city);
    setStreet(street);

    cout << "In Address:Address for ";
    show();
}

Address::Address(const Address &other) : street(NULL), city(NULL) {
    setNumber(other.houseNumber);
    setCity(other.city);
    setStreet(other.street);

    cout << "In Address:Address(copy) for ";
    show();
}

Address::~Address() {
    cout << "In Address:~Address for ";
    show();
    delete[] street;
    delete[] city;
}

void Address::show() const {
    cout << houseNumber << " " << street << ".st " << city << endl;
}