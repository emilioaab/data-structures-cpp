#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename T> //class template  //typename is a keyword for class template

class List {
private:
    T *data;
    int size;
public:
    List<T>();
    List(const List<T>& copiedList);
    ~List();



    //methods
    void clear();
    int count(const T& element) const;
    List<T>& append(const T& element);
    List<T>& extend(const List<T>& elements);
    int index(const T& element );
    List<T>& remove(int index);
    int length() const {return size;}

    //operators
    List<T>& operator=(const List<T>& copiedList);
    List<T> operator+(const List<T>& list) const;
    List<T>& operator+=(const List<T>& list);
    T& operator[](int index);
    List<T> operator[](string boundry) const;
    friend ostream& operator<<(ostream& out, const List<T>& list){
        for(int i = 0; i < list.size; i++){
            out << list.data[i] << " ";
        }
        return out;
    }





};

