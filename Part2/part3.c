/* Assignment: 4.2
Author: Emil Abdumalikov, ID: 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Minor(int ***pArr, int*pSize, int line, int col) {
    if (line < 0 || col < 0 || line >= *pSize || col >= *pSize) {
        return;
    }

    int newSize = *pSize - 1;
    int **newArr = malloc(newSize * sizeof(int*));

    for (int i = 0; i < newSize; i++) {
        newArr[i] = malloc(newSize * sizeof(int));
    }

    for (int i = 0, newI = 0; i < *pSize; i++, newI++) {
        if (i == line) {
            newI--;
            continue;
        }

        for (int j = 0, newJ = 0; j < *pSize; j++, newJ++) {
            if (j == col) {
                newJ--;
                continue;
            }

            newArr[newI][newJ] = (*pArr)[i][j];
        }
    }

    for (int i = 0; i < *pSize; i++) {
        free((*pArr)[i]);
    }
    free(*pArr);
    *pArr = newArr;
    *pSize = newSize;
}


char** Decompose(char* str, int* pCount) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    count++;

    char** arr = malloc(count * sizeof(char*));

    int start = 0;
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            int length = i - start + 1;
            if (str[i + 1] == '\0') {
                length--;
            }

            arr[index] = malloc((length + 1) * sizeof(char));
            strncpy(arr[index], str + start, length);
            arr[index][length] = '\0';
            start = i + 1;
            index++;
        }
    }

    *pCount = count;
    return arr;

}




void SortWords(char** text, int count) {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(text[j], text[minIndex]) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            char* temp = text[i];
            text[i] = text[minIndex];
            text[minIndex] = temp;
        }
    }
}


void PrintWords(char** text, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", text[i]);
    }
}

int main() {
    int size;
    printf("Enter size of matrix: ");
    scanf("%d", &size);

    int** arr = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(size * sizeof(int));
    }

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int line, col;
    printf("Enter line: ");
    scanf("%d", &line);
    printf("Enter col: ");
    scanf("%d", &col);
    Minor(&arr, &size, line, col);

    printf("Updated matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    char str[81];
    printf("Enter string: ");
    fgets(str, 81, stdin);
    str[strcspn(str, "\n")] = '\0';

    int count;
    char** words = Decompose(str, &count);

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}

