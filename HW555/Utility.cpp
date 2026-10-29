#include "Utility.h"

template<class T>
List<T> doTwice(const List<T> &list) {
    List<T> result;
    for (int i = 0; i < list.size(); i++) {
        result.append(list[i]);
        result.append(list[i]);
    }
    return result;
}

template<class T>
Queue<T> mergeQueue(Queue<T> q1, Queue<T> q2) {
    Queue<T> result;
    if (q1.length() != q2.length())
        return result;
    while (!q1.isEmpty()) {
        result.enqueue(q1.dequeue());
        result.enqueue(q2.dequeue());
    }
    return result;
}

template<class T>
const T &maxT(const T *&arr, const int &size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}