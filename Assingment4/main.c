#include <stdio.h>
#include <stdlib.h>

int** BuildMatrix(int row, int column) {
    int** Mtrx = (int**) malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        Mtrx[i] = (int*) malloc(column * sizeof(int));
        printf("Enter elements for row %d:\n", i + 1);
        for (int j = 0; j < column; j++) {
            scanf("%d", &Mtrx[i][j]);
        }
    }
    return Mtrx;
}

void FreeMatrix(int*** matrix, int row) {
    for (int i = 0; i < row; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}

void PrintMatrix(int** matrix, int row, int column) {
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** MultiplyMatrixes(int** a, int** b, int size1, int size2, int size3) {
    int** finalMatrix = (int**) malloc(size1 * sizeof(int*));
    for (int i = 0; i < size1; i++) {
        finalMatrix[i] = (int*) malloc(size3 * sizeof(int));
        for (int j = 0; j < size3; j++) {
            finalMatrix[i][j] = 0;
            for (int k = 0; k < size2; k++) {
                finalMatrix[i][j] = finalMatrix[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }
    return finalMatrix;
}

int main() {
    int size1, size2, size3;
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &size1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &size2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &size3);

    int** matrix1 = BuildMatrix(size1, size2);
    int** matrix2 = BuildMatrix(size2, size3);

    int** finalMatrix = MultiplyMatrixes(matrix1, matrix2, size1, size2, size3);

    PrintMatrix(finalMatrix, size1, size3);

    FreeMatrix(&matrix1, size1);
    FreeMatrix(&matrix2, size2);
    FreeMatrix(&finalMatrix, size1);

    return 0;
}
