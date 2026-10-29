#include "List.h"

template<typename T>
List<T>::List() :data(nullptr), size(0) {}

template<typename T>
List<T>::List(const List<T> &other) throw(std::bad_alloc) {
    try {
        if (data)
            delete[] data;
        data = new T[other.size];
        size = other.size;
        for (unsigned int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    catch (std::bad_alloc &ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        throw;
    }
}

template<typename T>
List<T>::~List() {
    if (data)
        delete[] data;
}

template<typename T>
void List<T>::clear() {
    if (data)
        delete[] data;
    data = nullptr;
    size = 0;
}

template<typename T>
const unsigned int List<T>::count(const T &value) const {
    unsigned int counter = 0;
    for (unsigned int i = 0; i < size; i++)
        if (data[i] == value)
            counter++;
    return counter;
}

template<typename T>
List<T> &List<T>::append(const T &value) throw(std::bad_alloc) {
    try {
        T *temp = new T[size + 1];
        for (unsigned int i = 0; i < size; i++)
            temp[i] = data[i];
        temp[size] = value;
        if (data)
            delete[] data;
        data = temp;
        size++;
        return *this;
    }
    catch (std::bad_alloc &ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        throw;
    }
}

template<typename T>
List<T> &List<T>::extend(const List<T> &other) throw(std::bad_alloc) {
    try {
        T *temp = new T[size + other.size];
        for (unsigned int i = 0; i < size; i++)
            temp[i] = data[i];
        for (unsigned int i = 0; i < other.size; i++)
            temp[size + i] = other.data[i];
        if (data)
            delete[] data;
        data = temp;
        size += other.size;
        return *this;
    }
    catch (std::bad_alloc &ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        throw;
    }
}

template<typename T>
const unsigned int &List<T>::index(const T &value) const {
    for (unsigned int i = 0; i < size; i++)
        if (data[i] == value)
            return i;
    throw std::exception("No such element");
}

template<typename T>
List<T> &List<T>::remove(int &index) throw(std::out_of_range) {
    if (index < 0)
        index += size;
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    T *temp = new T[size - 1];
    for (unsigned int i = 0; i < index; i++)
        temp[i] = data[i];
    for (unsigned int i = index + 1; i < size; i++)
        temp[i - 1] = data[i];
    if (data)
        delete[] data;
    data = temp;
    size--;
    return *this;
}

template<typename T>
List<T> &List<T>::operator=(const List<T> &other) throw(std::bad_alloc) {
    try {
        if (data)
            delete[] data;
        data = new T[other.size];
        size = other.size;
        for (unsigned int i = 0; i < size; i++)
            data[i] = other.data[i];
        return *this;
    }
    catch (std::bad_alloc &ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        throw;
    }
}

template<typename T>
List<T> List<T>::operator+(const List<T> &other) throw(std::bad_alloc) {
    try {
        List<T> temp(*this);
        temp.extend(other);
        return temp;
    }
    catch (std::bad_alloc &ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        throw;
    }
}

template<typename T>
List<T> &List<T>::operator+=(const List<T> &other) throw(std::bad_alloc) {
    try {
        this->extend(other);
        return *this;
    }
    catch (std::bad_alloc &ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        throw;
    }
}

template<typename T>
T &List<T>::operator[](int &index) throw(std::out_of_range) {
    if (index < 0)
        index += size;
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
List<T> List<T>::operator[](std::string &index) throw(std::out_of_range, std::invalid_argument) {
    if (index.find(':') == std::string::npos)
        throw std::invalid_argument("Invalid argument");

    int start = std::stoi(index.substr(0, index.find(':')));
    int end = std::stoi(index.substr(index.find(':') + 1));
    if (start < 0)
        start += size;
    if (end < 0)
        end += size;
    if (start < 0 || start >= size || end < 0 || end >= size)
        throw std::out_of_range("Index out of range");
    List<T> temp;
    for (int i = start; i < end; i++)
        temp.append(data[i]);
    return temp;
}