#include <stdio.h>

#define N 3
#define n 4
#define NN  5

//ex 1
void PrintMergeArray(int arr1[], int size1, int arr2[], int size2) {
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (arr1[i] == arr2[j]) {
                printf("%d \t", arr1[i]);
                break;
            }
        }
    }

}


//ex 2
void InputArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

}

int MostCommon(int arr[], int size) {
    int counter = 0, max = 0, common;
    for (int i = 0; i < size; i++) {
        counter = 0;
        for (int j = 0; j < size; ++j) {


            if (arr[i] == arr[j]) {
                counter++;
            }
            if (counter > max) {
                max = counter;
                common = arr[i];
            }
        }
    }
    return common;

}


//ex3
void InserMat(int arr1[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &arr1[i][j]);
        }
    }
}

void PrintMat(int arr1[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }

}

int MagicCube(int arr1[][N]) {
    int sumMainDiagonal = 0, sumSecondDiagonal = 0, sumCol = 0, sumRow = 0;

    for (int i = 0; i < N; ++i) {

        sumMainDiagonal += arr1[i][i];
        sumSecondDiagonal += arr1[i][N - 1 - i];

    }
    if (sumSecondDiagonal != sumMainDiagonal) return 0;

    for (int i = 0; i < N; ++i) {
        sumCol = 0;
        sumRow = 0;
        for (int j = 0; j < N; ++j) {
            sumRow += arr1[i][j]; //sum of rows
            sumCol += arr1[j][i]; //sum of column
        }
        if (sumRow != sumMainDiagonal || sumRow != sumMainDiagonal) return 0;
    }
    return 1;
}


//ex4
int IsOrthogonally(int a1[], int a2[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += a1[i] * a2[2];


    }
    return sum == 0;
}

int Orthogonally(int arr1[][n]) {
    for (int i = 0; i < n; ++i) {

        for (int j = i + 1; j < n; ++j) {

            if (!IsOrthogonally(arr1[i], arr1[j], n))
                return 0;

        }

    }
    return 1;
}


//ex5
int IsPali(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] != arr[size - 1 - i])
            return 0;
    }
    return 1;
}

int main() {
    //ex1
    /*
     int a1[4] = {1, 2, 3, 4}, a2[5] = {7, 6, 5, 4, 3};
     PrintMergeArray(a1, 4, a2, 5);
    */

    //ex2
    /*
    int arr[10];
    InputArray(arr, 10); // for example : {1,1,2,2,4,3,2,2,4,2}
    printf("The most common number is: %d\n", MostCommon(arr, 10));
     */

    //ex3
    /*
    int mat[N][N];
    InserMat(mat);
    PrintMat(mat);
    printf("IsMagic: %d", MagicCube(mat));
    */

    //ex4
    /*
    int mat[n][n];
    InserMat(mat);
    printf("Orthogonally: %d\n", Orthogonally(mat));
    */

    //ex5
    /*
    int a[NN] ={7,17,27,17,7};
    printf("IsPali:%d", IsPali(a,NN));
    */

    return 0;
}

