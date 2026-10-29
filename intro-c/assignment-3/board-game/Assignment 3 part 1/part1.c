/* Assignment: 3.1 (part1.c)
Campus: Beer Sheva
Author: Emil Abdumalikov, ID: 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE8 8
#define SIZE10 10

int arrayCheck();


int main() {
    int arr1[SIZE8], arr2[SIZE8], array1[SIZE10], array2[SIZE10];
    printf("\n\nPlease enter 8 numbers: \n");
    for(int i=0; i<SIZE8; i++) //array 1 of size 8
    {
        scanf("%d", &arr1[i]);
    }

    printf("Please enter another 8 numbers: \n");
    for(int i=0; i<SIZE8; i++) //array 2 of size 8
    {
        scanf("%d", &arr2[i]);
    }
    if(arrayCheck(arr1, arr2, SIZE8) == 1) //function checks if they have sets of numbers.
        printf("The arrays contain the same set of numbers \n\n");
    else
        printf("The arrays contain different sets of numbers \n\n");

    printf("Please enter 10 numbers: \n");
    for(int i=0; i<SIZE10; i++) //array 3 of size 10
    {
        scanf("%d", &array1[i]);
    }
    printf("Please enter another 10 numbers: \n");
    for (int i = 0; i < SIZE10; ++i) //array 4 of size 10
    {
        scanf("%d", &array2[i]);
    }
    if(arrayCheck(array1, array2, SIZE10) == 1)
        printf("The arrays contain the same set of numbers \n\n");
    else
        printf("The arrays contain different sets of numbers \n\n");


    return 0;
}


int arrayCheck(int arr1[], int arr2[], int size){
    int flag=0;

    for (int i = 0; i < size; i++) // array 1
    {
        flag = 0;
        for (int j = 0; j < size; j++) //array 2
        {
            if (arr1[i] == arr2[j]) //array Check of equality
                flag = 1;
        }
        if(flag == 0)
            return 0;
    }

    flag = 0;
    for(int i=0; i<size; i++) //array 2
    {
        flag = 0;
        for(int j=0; j<size; j++) //array 1
        {
            if(arr2[i] == arr1[j]) //array Check of equality
                flag = 1;
        }
        if(flag == 0)
            return 0;
    }
    return 1;
}





