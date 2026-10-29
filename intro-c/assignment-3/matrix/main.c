/* Assignment: 3
Campus: Beer Sheva
Author: Emil Abdumalikov, ID: 
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROW 4
#define COLUMN 5


void InputMatrix(int mat[ROW][COLUMN]) {

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COLUMN; j++)
            scanf("%d", &(mat[i][j]));

}

void PrintSpiral(int mat[ROW][COLUMN]) {


    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COLUMN; j++) {
            if (mat[i] <= mat[0])
                printf("%d ", mat[i][j]); //printing the first line in order

            if (mat[j] == mat[4] && mat[i][j] != mat[0][4])
                printf("%d ", mat[i][j]); // printing the last row in descending order

        }

    for (int i = ROW; i >= 0; i--)  //another for, for the reversed line
        for (int j = COLUMN; j >= 0; j--) {
            if (mat[i] == mat[3] && mat[i] >= mat[j] && mat[i][j] != mat[3][4]) {
                printf("%d ", mat[i][j]); //printing the last row in reversed order
            }
        }
    printf("%d ", mat[2][0]);
    printf("%d ", mat[1][0]);

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COLUMN; j++) {
            if (mat[i] == mat[1] && (mat[i][j] > mat[1][0] && mat[i][j] < mat[1][4]))
                printf("%d ", mat[i][j]);
        }

    for (int i = ROW; i >= 0; i--)
        for (int j = COLUMN; j >= 0; j--) {
            if (mat[i] == mat[2] && (mat[i][j] > mat[2][0] && mat[i][j] < mat[2][4])) {
                printf("%d ", mat[i][j]);
            }

        }
}


int main() {
    int arr[ROW][COLUMN];

    InputMatrix(arr);
    PrintSpiral(arr);


    return 0;
}