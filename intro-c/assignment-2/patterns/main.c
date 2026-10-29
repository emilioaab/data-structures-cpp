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
    do {
        printf("enter angle position: 0 - quit, 1 --, 2 |, 3 , 4 /");
        scanf("%d", &choice);

        switch (choice) {
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
            default:
                printf("Error! operator is not correct!");
        }
    } while (choice!=0);


    
    
    
    return 0;
}