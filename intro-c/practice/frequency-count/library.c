#include <stdio.h>
#define MAX  10000
int count_elements_with_multiple_occurrences(int arr[], int size) {
    int count = 0;
     // assuming array elements are within range 0-9999
    int frequency[MAX] = {0}; // array to store the frequency of each element
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }
    for (int i = 0; i < MAX; i++) {
        if (frequency[i] > 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int my_array[] = {5, 3, 1, 3, 15, 3, 5};
    int size = sizeof(my_array) / sizeof(my_array[0]);
    int result = count_elements_with_multiple_occurrences(my_array, size);
    printf("Number of elements with multiple occurrences: %d\n", result);
    return 0;
}
