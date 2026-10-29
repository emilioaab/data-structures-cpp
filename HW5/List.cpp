#include "List.h"

template<typename T>
List<T>::List() {
    size = 0;
    data = nullptr;
}

template<typename T>
List<T>::~List() {
    delete[] data;
}

template<typename T>
void List<T>::clear() {
    if (data != nullptr)
        delete[] data;
    data = nullptr;
    size = 0;
}

template<typename T>
int List<T>::count(const T &element) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == element)
            count++;
    }
    return count;
}

template<typename T>
List<T> &List<T>::append(const T &element) {
    try {
        T *temp = new T[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        temp[size] = element;
        size++;
        delete[] data;
        data = temp;
    }
    catch (bad_alloc &ba) {
        cout << "bad allocation caught: " << ba.what() << endl;
    }
    return *this;
}

template<typename T>
List<T> &List<T>::extend(const List<T> &elements) {
    try {
        T *temp = new T[size + elements.size];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        for (int i = 0; i < elements.size; i++) {
            temp[size + i] = elements.data[i];
        }
        size += elements.size;
        delete[] data;
        data = temp;
    }
    catch (bad_alloc &ba) {
        cout << "bad allocation caught: " << ba.what() << endl;
    }
    return *this;
}

template<typename T>
int List<T>::index(const T &element) {
    for (int i = 0; i < size; i++) {
        if (data[i] == element)
            return i;
    }
    throw "Element not found";
}

template<typename T>
List<T> &List<T>::remove(int index) {
    if (index < 0) {
        index += size;
    }

    if (index < 0 || index >= size)
        throw "Index out of range";
    T *temp = new T[size - 1];
    for (int i = 0; i < index; i++) {
        temp[i] = data[i];
    }
    for (int i = index + 1; i < size; i++) {
        temp[i - 1] = data[i];
    }
    size--;
    delete[] data;
    data = temp;
    return *this;
}