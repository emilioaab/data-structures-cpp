#include <iostream>
#include <exception>
#include <string>

template<typename T>
class List {
    T *data;
    unsigned int size;

public:
    List();

    List(const List<T> &other) throw(std::bad_alloc);

    ~List();

    void clear();

    const unsigned int count(const T &value) const;

    List<T> &append(const T &value) throw(std::bad_alloc);

    List<T> &extend(const List<T> &other) throw(std::bad_alloc);

    const unsigned int &index(const T &value) const;//maybe exception
    List<T> &remove(int &index) throw(std::out_of_range);

    inline const unsigned int &length() const { return size; }

    List<T> &operator=(const List<T> &other) throw(std::bad_alloc);

    List<T> operator+(const List<T> &other) throw(std::bad_alloc);

    List<T> &operator+=(const List<T> &other) throw(std::bad_alloc);

    T &operator[](int &index) throw(std::out_of_range);

    List<T> operator[](std::string &index) throw(std::out_of_range, std::invalid_argument);

    friend std::ostream &operator<<(std::ostream &os, const List<T> &list) {
        os << "[";
        for (unsigned int i = 0; i < list.size; i++) {
            os << list.data[i];
            if (i != list.size - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }
};