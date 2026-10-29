#include "Queue.h"

template<class T>
Queue<T>::Queue() {
}

template<class T>
Queue<T>::~Queue() {
}

template<class T>
Queue<T> &Queue<T>::enqueue(T data) {
    List<T>::append(data);
    return *this;
}

template<class T>
T Queue<T>::dequeue() {
    T temp = List<T>::[0];
    List<T>::remove(0);
    return temp;
}

template<class T>
bool Queue<T>::isEmpty() const {
    return length() > 0;
}

template<class T>
const T &Queue<T>::peek() const {
    return List<T>::[0];
}