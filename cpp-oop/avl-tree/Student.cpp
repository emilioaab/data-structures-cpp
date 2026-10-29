#include "Student.h"

Student::Student(char *name, const Address& school, const Address& home) : schoolAddress(&school), homeAddress(home) {
    cout << "In Student:Student for " << name << endl;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

}

Student::Student(const Student &other) : schoolAddress(other.schoolAddress), homeAddress(other.homeAddress) {
    cout << "In Student:Student(copy)\n ";
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Student::~Student() {
    cout << "In Student::~Student for " << name << endl;
    delete[] name;
}

void Student::show() const {
    cout << name << " lives at ";
    homeAddress.show();
    cout << "and studies at ";
    schoolAddress->show();
}