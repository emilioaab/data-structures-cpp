/* Assignment: 5
Author: Emil Abdumalikov, ID: 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ex1
int CheckNumber(int num) { // 8462

    if (num < 10) {
        if (num % 2 == 0) return 1; else return 0;
    }

    int lastDigit = num % 10; //2 6 4
    int remainingDigits = num / 10; //846 84 8
    if (lastDigit % 2 != 0) {
        return 0;
    }
    return CheckNumber(remainingDigits);
}

//ex2
int Equal(int number, int sum) { // 12345 15 | 1234 10 | 123 6 | 12 3 | 1 1 | 0 0

    if (number == 0) {
        if (sum == 0) return 1; else return 0;
    }

    int lastDigit = number % 10; //5 | 4 | 3 | 2 | 0
    int remainingDigits = number / 10; //1234 | 123 | 12 | 1 | 0

    return Equal(remainingDigits, sum - lastDigit); //1234 15-5=10 | 123 10-4=6 | 12 6-3=3 | 1 3-2=1 | 0 1-1=0


}

//ex3
int
Creator(int num) {   // num = 1234 | num%10/2==0 (4) yes num%10 = temp(4) num/10 (123)-> num%10/2==0 no num/10 = (12)
    //num%10/2 == 0 (2) yes num%10*10 + temp = 24  num/10 = 1 num%10/2 == 0 no num/10 = 0 return temp=24;


    if (num < 10 && num >= 0) {
        return num % 2 == 0 ? num : 0;
    } else if (num < 0) {
        return -Creator(-num);
    }

    int lastDigit = num % 10; //4  3  2
    int remainingDigits = num / 10; //123 12 1
    int temp = Creator(remainingDigits);
    if (lastDigit % 2 == 0) {
        temp = temp * 10 + lastDigit; //4
    }
    return temp;


}

void Reducing(char* str) {
    if (*str == '\0') {
        return;
    }

    Reducing(str + 1);

    if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
        printf("%c", *str);
    }
}


void MinMaxArray(int arr[], int size, int* min, int* max) {
    if (size == 1) {
        *min = *max = arr[0];
        return;
    }

    int subMin, subMax;
    MinMaxArray(arr, size - 1, &subMin, &subMax);

    if (arr[size - 1] < subMin) {
        *min = arr[size - 1];
    } else {
        *min = subMin;
    }

    if (arr[size - 1] > subMax) {
        *max = arr[size - 1];
    } else {
        *max = subMax;
    }
}

int CheckString(char* start, char* middle) {
    if (*middle == '\0') {
        return 1;
    }

    if ((*start != *middle) && (*start != *middle + 32) && (*start != *middle - 32)) {
        return 0;
    }

    return CheckString(start, middle + 1);
}

int Compare(char* str1, char* str2) {
    int count = 0;

    while (*str1 != '\0' && *str2 != '\0') {
        if ((*str1 == *str2) || (*str1 == *str2 + 32) || (*str1 == *str2 - 32)) {
            count++;
        }

        str1++;
        str2++;
    }

    return count;
}
int main() {
    int num = 8462;
    if (CheckNumber(num)) {
        printf("All digits of the number are even.\n");
    } else {
        printf("Not all digits of the number are even.\n");
    }

    int number = 12345;
    int sum = 15;
    if (Equal(number, sum)) {
        printf("The sum of the digits equals %d.\n", sum);
    } else {
        printf("The sum of the digits does not equal %d.\n", sum);
    }

    int num2 = 1234;
    int result = Creator(num2);
    printf("The result of Creator function is %d.\n", result);

    char str[] = "tH8j23$%2kmn6}3h";
    Reducing(str);
    printf("\n");

    int arr[] = {9, 3, 6, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    MinMaxArray(arr, size, &min, &max);
    printf("Minimum number: %d\n", min);
    printf("Maximum number: %d\n", max);

    char str1[] = "fBDRe";
    char str2[] = "FxdRle";
    int count = Compare(str1, str2);
    printf("Number of matching characters: %d\n", count);

    return 0;
}
