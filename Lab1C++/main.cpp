#include <iostream>
#include <iomanip>

using namespace std;

int *createArray(int size) { //function to initiate the arrays
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
        if(i>0 && (*(arr+i)>=*(arr+(i-1))||*(arr+i)==*(arr+(i-1)))){

            cout<<"Invalid input. Please enter a number greater than the previous number and that is not repeating."<<endl;
        }
    }

    return arr;
}

void printArray(int *arr, int size) { //function to print the arrays
    for (int i = 0; i < size; i++)
        cout << arr[i];

    cout << endl;
}

int *mergeArrays(int *arr1, int size1, int *arr2, int size2) { //function that merges the two arrays

    int *arr3 = new int[size1+size2];



}

int main() {


    return 0;
}

