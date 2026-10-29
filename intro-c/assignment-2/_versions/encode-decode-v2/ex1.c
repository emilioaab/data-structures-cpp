/*
Assignment: 2
Campus: Beer-Sheva
Author: Emil Abdumalikov, ID: 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void HorizontalLine();
void VerticalLine();
void DescendingDiagonalLine();
void AscendingDiagonalLine();

int main() {

    int choice;
    int backslash = 92;
    do {
        printf("enter angle position: 0 - quit, 1 --, 2 |, 3 %c, 4 /\n", backslash);
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                break;
            case 1:
                HorizontalLine();
                break;
            case 2:
                VerticalLine();
                break;
            case 3:
                DescendingDiagonalLine();
                break;
            case 4:
                AscendingDiagonalLine();
                break;
        }
    } while (choice != 0);

    return 0;
}

void HorizontalLine() {
    int length;
    printf("Enter length\n");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 2 * length + 1; j++) {
            printf("*");
        }

        printf("\n");
    }
    for (int i = 0; i < 2 * length + 1; i++)
        printf(" ");
    printf("\n");

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 2 * length + 1; j++) {
            printf("*");
        }

        printf("\n");
    }

}


void VerticalLine() {
    int length;
    printf("Enter length\n");
    scanf("%d", &length);

    for (int i = 0; i < 2 * length + 1; i++) {
        for (int j = 0; j < length; j++) {
            printf("*");
        }
        printf(" ");

        for (int j = 0; j < length; j++)
            printf("*");

        printf("\n");
    }
    printf("\n");


}


void DescendingDiagonalLine() {
    int length, i, j;
    printf("Enter length\n");
    scanf("%d", &length);

    for (i = 0; i < 2 * length + 1; i++) {
        for (j = 0; j < 2 * length + 1; j++) {
            if (j == i) {
                printf(" ");
            } else
                printf("*");
        }
        printf("\n");
    }


}


void AscendingDiagonalLine() {
    int length, i, j, decrease = 0;
    printf("Enter length\n");
    scanf("%d", &length);

    decrease = length*2+1;

    for (i = 1; i <= 2 * length + 1; i++) {
        for (j = 1; j <= 2 * length + 1; j++) {
            if(j==decrease) {
                printf(" ");
                decrease--;

            }
            else
                printf("*");

        }
        printf("\n");
    }
}