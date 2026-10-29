#include <iostream>
#include <iomanip>

using namespace std;

//example 1
/*
int size;
char str[20];
cout << "Enter a string: \n";
//cin >> str; // prints until the space
cin.getline(str, sizeof(str)); //this prints the whole line
cout << str << endl;
*/


//lab1.1
/*
int* BuildArray(int size) {

    int* arr = new int[size];
    if(!arr){
        cout << "Error allocating memory!" << endl;
        return 0;
    }
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]: ";
        cin >> arr[i];

    }
    return arr;
}

void printArray(int* arr, int size){ //do something 

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* newArray(int* arr1, int* arr2, int size1, int size2){ //merges two arrays and make them in ascending order and without repetitions

int* arr3 = new int[size1 + size2];
    if(!arr3){
        cout << "Error allocating memory!" << endl;
        return 0;
    }
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else if (arr2[j] < arr1[i]) {
            arr3[k++] = arr2[j++];
        }
        else {
            arr3[k++] = arr1[i++];
            j++;
        }
    }
    while (i < size1) {
        arr3[k++] = arr1[i++];
    }
    while (j < size2) {
        arr3[k++] = arr2[j++];
    }
    return arr3;


}

int main() {
    int size1, size2;
    cout << "Enter the size of the first array: \n";
    cin >> size1;
    int* arr1 = BuildArray(size1);
    cout << "Enter the size of the second array: \n";
    cin >> size2;
    int* arr2 = BuildArray(size2);
    int* arr3 = newArray(arr1, arr2, size1, size2);
    printArray(arr3, size1 + size2);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;


    return 0;
}

*/

#include <iostream>
using namespace std;


int& add(int x, int y) {
    int z = x + y;
    return z;
    //warning C4172 : returning address of local variable or temporary : z
}
void f1(int x) { //f1(int&x) error
    x++;
}
int main() {
    int const x1(3);
    f1(x1);
    int const *  p1(&x1);
    p1++;
    //	*p1 = 8; error

    int x2(3);
    int  * const p2(&x2);
    //p++; error
    *p2 = 8;
    int x(1);
    const int& y(x);
    cout << &x << " " << &y << endl;
    // y = 3; error
    int& rx(add(3, 4));
    rx = 8;
    cout << rx << endl;

    int a1 = 10;
    const int &  pc(a1);
    //pc=8;
    a1 = 8;
    return 0;
}
