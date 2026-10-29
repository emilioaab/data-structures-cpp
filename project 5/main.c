/*
Asisignment : 5
Author : Emil Abdumalikov
id: 
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int even_uneven_difference(int num) {
    if (num == 0) return 0;
    int digit = num % 10;
    int difference = (digit % 2 == 0) ? digit : -digit;
    return difference + even_uneven_difference(num / 10);
}

void binary_representation(int number, char *binary, int i) {
    if (number == 0) {
        binary[i] = '\0';
        return;
    }
    binary[i] = number % 2 + '0';
    binary_representation(number / 2, binary, i + 1);
}


int all_even(int arr[], int size) {
    if (size == 0) {
        return 1;
    }
    if (arr[size - 1] % 2 == 0) {
        return all_even(arr, size - 1);
    } else {
        return 0;
    }
}

int has_uneven_digit(int n) {
    if (n < 10) {
        return n % 2 != 0;
    } else {
        if (n % 2 != 0) {
            return 1;
        } else {
            return has_uneven_digit(n / 10);
        }
    }
}


int passed_grades(int arr[], int size) {
    if (size == 0) {
        return 0;
    } else {
        if (arr[size - 1] >= 56) {
            return 1 + passed_grades(arr, size - 1);
        } else {
            return passed_grades(arr, size - 1);
        }
    }
}

int count_char(char *str, char c, int i) {
    if (str[i] == '\0') {
        return 0;
    } else {
        if (str[i] == c) {
            return 1 + count_char(str, c, i + 1);
        } else {
            return count_char(str, c, i + 1);
        }
    }
}


int main() {
    //function 1
    int number;
    printf("Please enter a positive integer number: \n\n");
    scanf("%d", &number);
    printf("The sum of even digits minus uneven digits is: %d\n\n", even_uneven_difference(number));

    //function 2
    int num;
    printf("Please enter a positive integer number:\n\n");
    scanf("%d", &num);
    char binary[100];
    binary_representation(num, binary, 0);
    unsigned long len = 0;
    len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
    printf("The binary representation of %d is: %s\n\n", num, binary);

    //function 3
    int size;
    int *arr;
    printf("Please enter the size of the array: ");
    scanf("%d", &size);
    arr = (int *) malloc(sizeof(int) * size);
    printf("Please enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    if (all_even(arr, size)) {
        printf("All elements in the array are even\n");
    } else {
        printf("Not all elements in the array are even\n");
    }
    free(arr);


    //function 4
    int numbre;
    printf("Please enter a positive integer number: ");
    scanf("%d", &numbre);
    if (has_uneven_digit(numbre)) {
        printf("The number has an uneven digit '1'\n");
    } else {
        printf("The number does not have an uneven digit ""0""\n");
    }


    //function 5

    int sizez;
    int *arrr;
    printf("Please enter the size of the array: ");
    scanf("%d", &size);
    arr = (int *) malloc(sizeof(int) * size);
    printf("Please enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Number of passed grades: %d\n", passed_grades(arr, size));
    free(arr);


    //function 6
    char *str;
    char c;
    int i = 0;
    printf("Please enter a string: ");
    scanf("%s", str);
    printf("Please enter a character: ");
    scanf(" %c", &c);
    printf("Number of '%c' in the string: %d\n", c, count_char(str, c, i));


    return 0;
}
