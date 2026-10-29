/* Assignment: 4.1
Author: Emil Abdumalikov, ID: 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SumsFunc(float *arr, int size, int *SumIntReturn, float *SumFloatReturn) {
    int sumInt=0;
    float sumFloat = 0;
    int curInt;
    float curFloat;

    for (int i=0; i<size; i++) {
        //printf("%f", arr[i]);
        // arr[i] == *(arr+i)

        curInt = (int)(arr[i]);
        sumInt+=curInt;

        curFloat = arr[i]-(float)curInt;
        sumFloat+=curFloat;
    }
    *SumIntReturn = sumInt;
    *SumFloatReturn = sumFloat;
}

int main(){
    int size;
    float *array;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = malloc(size * sizeof(float));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%f", &array[i]);
    }

    // Call the Sums function and store the result in two variables
    int int_part_sum;
    float dec_part_sum;
    SumsFunc(array, size, &int_part_sum, &dec_part_sum);

    // Print the results
    printf("Sum of integer parts: %d\n", int_part_sum);
    printf("Sum of decimal parts: %f\n", dec_part_sum);

    return 0;
}