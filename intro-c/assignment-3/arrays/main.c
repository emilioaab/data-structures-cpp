/* Assignment: 3
Campus: Beer Sheva
Author: Emil Abdumalikov, ID: 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int ArrNumCount(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) { //input by user
        scanf("%d", &arr[i]);
    }

    for (int i = 0; arr[i] < size; i++) {

        for (int j = i + 1; j < size; j++) {

            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }

    printf("There are %d repeated numbers", count);

    return 0;
}

int main() {
    int size, arr[100], count = 0;

    printf("Enter size of the array:\n");
    scanf("%d", &size);

    printf("Enter %d integer numbers into the array to count how many numbers repeat itself more then once:\n", size);

    ArrNumCount(arr, size);


    return 0;
}