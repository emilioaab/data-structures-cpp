#include "Utility.h"
#include "Utility.cpp"

using namespace std;

int main() {
    cout << "<<< List<int> >>>" << endl;
    List<int> list1;
    cout << "list1: " << list1 << endl;
    cout << "append{1,2,3}: " << list1.append(1).append(2).append(3) << endl;
    cout << "length(): " << list1.length() << endl;
    List<int> list2(list1);
    cout << "list2(list1): " << list2 << endl;
    cout << "list1.extend(list2).remove(0): "
         << list1.extend(list2).remove(0) << endl;;
    cout << "count(3): " << list1.count(3) << endl;
    list2 = list1;
    cout << "list2=list1: " << list2 << endl;
    list2[0] = 100;
    list2[-1] = 200;
    cout << "list2{[0]=100,[-1]=200}: " << list2 << endl;
    cout << "index(2): " << list2.index(2) << endl;
    cout << "list2 slicing: " << list2["2:"] + list2[":3"] +
                                 list2["1:-1"] << endl;
    cout << "list1: " << list1 << endl;
    list1 += list2["2:"];
    cout << "list1{+= & slicing}: " << list1 << endl;
    list1.clear();
    cout << "list1.clear(): " << list1 << endl;
    cout << "\n<<< List<string> >>>" << endl;
    List<string> list3, list4, list5;
    cout << "list3,list4,list5: " << list3 << "," << list4 << "," << list5 << endl;
    cout << "list3.append(): " << list3.append("London").append("is").
            append("the").append("capital").append("of") << endl;
    cout << "list4.append(): "
         << list4.append("Great").append("Britian") << endl;
    cout << "list5.append(): "
         << list5.append("Paris").append("France") << endl;
    list3 += list4;
    cout << "list3 += list4: " << list3 << endl;
    cout << "slicing & [index]:" << endl;
    cout << list3 << endl << list3[":4"] << endl << list3["-2:"]
         << " - " << list3[0] << endl;
    cout << list5[":1"] + list3["1:-2"] + list5["1:"] << endl;
    cout << "\n<<< Queue<int> >>>" << endl;
    Queue<int> queue1;
    cout << "queue1: " << queue1 << endl;
    cout << "enqueue{1,2,3,4,5}: " << queue1.enqueue(1).enqueue(2).
            enqueue(3).enqueue(4).enqueue(5) << endl;
    cout << "peek(): " << queue1.peek() << ", " << queue1 << endl;
    cout << "dequeue X 2: " << queue1.dequeue() << ", " <<
         queue1.dequeue() << ", " << queue1 << endl;
    queue1.enqueue(100);
    cout << "enqueue(100): " << queue1 << endl;
    cout << "\n<<< Functions >>>" << endl;
    cout << "list2,doTwice(list2): " << list2 << "," << doTwice(list2) << endl;
    cout << "list5,doTwice(list5): " << list5 << "," << doTwice(list5) << endl;
    Queue<int> queue2;
    queue2.enqueue(15).enqueue(16).enqueue(17).enqueue(18);
    cout << "queue1,queue2: " << queue1 << "," << queue2 << endl;
    cout << "mergeQueue(queue2,queue1):" << mergeQueue(queue2, queue1) << endl;
    cout << "queue1,queue2: " << queue1 << "," << queue2 << endl;
    Queue<int> queue3;
    queue3.enqueue(100).enqueue(200).enqueue(300);
    cout << "queue2,queue3: " << queue2 << "," << queue3 << endl;
    cout << "mergeQueue(queue2,queue3):" << mergeQueue(queue2, queue3) << endl;
    int arr1[] = {7, 2, 14, 5, 10};
    cout << "maxT<int>: " << maxT(arr1, 5) << endl;
    string arr2[] = {"aaa", "abcd", "aaaaa", "qwerty", "qaz"};
    cout << "maxT<string>: " << maxT(arr2, 5) << endl;
    Point arr3[] = {Point(1, 0), Point(), Point(7, 2), Point(3, 12),
                    Point(5, 6)};
    cout << "maxT<Point>: " << maxT(arr3, 5).toString() << endl;
    return 0;
}

//Point.h
class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    string toString() {
        return "Point(" + to_string(x) + "," + to_string(y) + ")";
    }

    bool operator>=(Point &obj) {
        return (x + y) >= (obj.x + obj.y);
    }
};