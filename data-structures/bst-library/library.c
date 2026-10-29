#define _CRT_SECURE_NO_WARNINGS/*

 Asisignment : 5
Author : Kamal Hamdony
 Id: 

 */


#include <stdio.h>
#include <string.h>


int minus(int number) {
    if (number == 0) {
        return 0;
    }
    int last = number % 10;
    if (last % 2 == 0) {
        return last + minus(number / 10);
    } else {
        return -last + minus(number / 10);
    }
}


void binaryreturn(int number, char *binary, int i) {
    if (number == 0) {
        binary[i] = '\0';
        return;
    }
    binary[i] = number % 2 + '0';
    binaryreturn(number / 2, binary, i + 1);
}


int even(int array[], int sizee, int i) {

    if (i == sizee) { return 1; }
    if (array[i] % 2 == 1) { return 0; }
    return even(array, sizee, i + 1);
}


int odddigit(int number) {
    if (number < 10) { return number % 2 == 1; }

    return odddigit(number / 10) || (number % 10) % 2 == 1;

}


int grades(int gradearr[], int gradesize, int i, int count) {

    if (i == gradesize) { return count; }
    if (gradearr[i] >= 56) { count++; }
    return grades(gradearr, gradesize, i + 1, count);
}


int countletter(char *stringz, char letter3, int i, int count) {

    if (stringz[i] == '\0') {
        return count;
    } else if (stringz[i] == letter3) {
        count += 1;
        return countletter(stringz, letter3, i + 1, count);
    } else {
        return countletter(stringz, letter3, i + 1, count);
    }
}


int main() {

    int number;
    printf("enter anumber to substract odd numbers from even:\n");
    scanf("%d", &number);
    printf("the result is  :\n%d\n", minus(number));


    int num;
    printf(" enter a number to convert it to binary :\n");
    scanf("%d", &num);


    char binary[100];
    binaryreturn(num, binary, 0);
    unsigned long len = 0;
    len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
    printf("Binary representation of %d is %s\n", num, binary);


    int n;
    printf("enter the size of the array:\n");
    scanf("%d", &n);
    int arrx[n];
    printf(" enter a numbers to the array , to return : 1 if all of his numbers are even , else 0 :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrx[i]);
    }

    int result = even(arrx, n, 0);
    printf("%d\n", result);


    int number2;
    printf("enter a number to return 1 if all his digits are odd:\n");
    scanf("%d", &number2);
    printf("%d\n", odddigit(number2));


    int gradesize;

    printf("enter how many grades you have ");
    scanf("%d", &gradesize);
    int gradearray[gradesize];
    printf("enter the grades :\n");
    for (int i = 0; i < gradesize; i++) {
        scanf("%d", &gradearray[i]);
    }
    printf("the number of grades that are equal to 56 and above is :\n%d\n", grades(gradearray, gradesize, 0, 0));


    char stringz[50];
    char letter3;

    printf("enter a string :\n");
    // fgets(stringz, sizeof(stringz), stdin);
    scanf("%s", stringz);
    printf("enter the letter tou want to count :\n");

    scanf("%c", &letter3);

    printf("the letter have been written :%d in the string \n", countletter(stringz, letter3, 0, 0));


    return 0;
}
