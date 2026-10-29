#include "ComplexArray.h"

ComplexArray::ComplexArray() {
    arr = nullptr;
    size = 0;
}


ComplexArray::ComplexArray(int arrSize) {
    size = arrSize;
    arr = new Complex[size];
}

ComplexArray::ComplexArray(const Complex *const arr, int arrSize) {
    size = arrSize;
    this->arr = new Complex[size];
    for (int i = 0; i < size; i++) {
        this->arr[i] = arr[i];
    }
}

ComplexArray::ComplexArray(const ComplexArray &other) {
    size = other.size;
    arr = new Complex[size];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

ComplexArray::~ComplexArray() {
    if (!arr)
        delete[] arr;
}



string ComplexArray::toString() const {
    string str = "[";
    for (int i = 0; i < size; i++) {
        str += arr[i].toString();
        if (i != size - 1) {
            str += ", ";
        }
    }
    str += "]";
    return str;
}

const ComplexArray &ComplexArray::operator=(const ComplexArray &other) {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        arr = new Complex[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

bool ComplexArray::operator==(const ComplexArray &other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }
    return true;
}

bool ComplexArray::operator!=(const ComplexArray &other) const {
    return !(*this == other);
}

Complex &ComplexArray::operator[](int index) const {
    return index < 0 ? arr[size + index] : arr[index];
}

ComplexArray ComplexArray::operator+(const ComplexArray &other) const {
    ComplexArray temp(size + other.size);
    for (int i = 0; i < size; i++) {
        temp.arr[i] = arr[i];
    }
    for (int i = 0; i < other.size; i++) {
        temp.arr[i + size] = other.arr[i];
    }
    return temp;
}

ComplexArray &ComplexArray::operator+=(const ComplexArray &other) {
    ComplexArray temp = *this + other;
    *this = temp;
    return *this;
}

ComplexArray ComplexArray::operator+(const Complex &complexNumber) const {
    ComplexArray temp(size + 1);
    for (int i = 0; i < size; i++) {
        temp.arr[i] = arr[i];
    }
    temp.arr[size] = complexNumber;
    return temp;
}

ComplexArray &ComplexArray::operator+=(const Complex &complexNumber) {
    ComplexArray temp = *this + complexNumber;
    *this = temp;
    return *this;
}

Complex
ComplexArray::operator!() const { //we do here a sum of complex nums, and we do it with the + operator of the complex class
    Complex sum = 0.2f;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

istream &operator>>(istream &in, ComplexArray &complexArray) {
    if (complexArray.size == 0) {
        cout << "Enter size: ";
        in >> complexArray.size;
        complexArray.arr = new Complex[complexArray.size];
    }
    for (int i = 0; i < complexArray.size; i++) {
        cout << "Enter complex number " << i + 1 << ": ";
        in >> complexArray.arr[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const ComplexArray &complexArray) {
    out << complexArray.toString();
    return out;
}

