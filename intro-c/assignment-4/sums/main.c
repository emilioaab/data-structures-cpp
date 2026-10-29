/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void SumsFunc(float *arr, int size, int *SumIntReturn, float *SumFloatReturn) {
    int sumInt=0;
    float sumFloat = 0;
    int curInt;
    float curFloat;

    for (int i=0; i<size; i++) {
        //printf("%f", arr[i]);
        // arr[i] == *(arr+i)

        curInt = (int)(arr[i]);
        sumInt+=curInt;

        curFloat = arr[i]-curInt;
        sumFloat+=curFloat;

    }
    *SumIntReturn = sumInt;
    *SumFloatReturn = sumFloat;

}


int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    float array[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%f", &array[i]);
    }

    // Call the Sums function and store the result in two variables
    int int_part_sum = int_sum(array, size);
    float dec_part_sum = dec_sum(array, size);

    // Print the results
    printf("Sum of integer parts: %d\n", int_part_sum);
    printf("Sum of decimal parts: %f\n", dec_part_sum);



    // float test = 10.79;
    // int test_int = (int)(test);
    // float test2 = test-test_int;
    // float remainder = test % 1;
    // printf("%d, %.3f", test_int, test2);

    return 0;
}
 */



/* Assignment: 4.1
Author: Emil Abdumalikov, ID: 
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SumsFunc(float *arr, int size, int *SumIntReturn, float *SumFloatReturn) {
    int sumInt=0;
    float sumFloat = 0;
    int curInt;
    float curFloat;

    for (int i=0; i<size; i++) {
        //printf("%f", arr[i]);
        // arr[i] == *(arr+i)

        curInt = (int)(arr[i]);
        sumInt+=curInt;

        curFloat = arr[i]-(float)curInt;
        sumFloat+=curFloat;
    }
    *SumIntReturn = sumInt;
    *SumFloatReturn = sumFloat;
}

int main(){
    int size;
    float *array;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = malloc(size * sizeof(float));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%f", &array[i]);
    }

    // Call the Sums function and store the result in two variables
    int int_part_sum;
    float dec_part_sum;
    SumsFunc(array, size, &int_part_sum, &dec_part_sum);

    // Print the results
    printf("Sum of integer parts: %d\n", int_part_sum);
    printf("Sum of decimal parts: %f\n", dec_part_sum);

    return 0;
}


*/


/* Assignment: 4.2
Author: Emil Abdumalikov, ID: 
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* CreateString(char* string1, char* string2) {
    // Calculate the length of the resulting string
    int newStringLength = strlen(string1) + (strlen(string1) - 1) * strlen(string2);

    // Allocate memory for the resulting string
    char* newString = malloc(newStringLength + 1); // +1 for the null terminator

    // Keep track of the current position in the resulting string
    int currentPos = 0;

    // Loop through each character in string1
    for (int i = 0; string1[i] != '\0'; i++) {
        // Add the current character to the result
        newString[currentPos] = string1[i];
        currentPos++;

        // Add string2 after the current character
        for (int j = 0; string2[j] != '\0'; j++) {
            newString[currentPos] = string2[j];
            currentPos++;
        }
    }

    // Add the null terminator to the end of the string
    newString[currentPos] = '\0';

    return newString;
}

int main() {
    char originalString[100]; // Make sure the buffer is large enough to hold the input
    char stringToInsert[100]; // Make sure the buffer is large enough to hold the input

    printf("Enter original string: ");
    scanf("%s", originalString);

    printf("Enter string to insert: ");
    scanf("%s", stringToInsert);

    char* newString = CreateString(originalString, stringToInsert);
    printf("New string: %s\n", newString);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* CreateString(char* string1, char* string2) {
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    char* new_string = malloc((len1 + len2) * sizeof(char));
    int j = 0;
    for (int i = 0; i < len1; i++) {
        new_string[j] = string1[i];
        j++;
        for (int k = 0; k < len2; k++) {
            new_string[j] = string2[k];
            j++;
        }
    }
    return new_string;
}

int* Start(int* big, int big_size, int* small, int small_size, int* psize) {
    int* indexes = malloc(big_size * sizeof(int));
    *psize = 0;
    for (int i = 0; i < big_size; i++) {
        if (big[i] == small[0]) {
            int match = 1;
            for (int j = 1; j < small_size; j++) {
                if (big[i + j] != small[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                indexes[*psize] = i;
                (*psize)++;
            }
        }
    }
    if (*psize == 0) {
        free(indexes);
        return NULL;
    }
    if (indexes[*psize - 1] + small_size > big_size) {
        *psize = 0;
        free(indexes);
        return NULL;
    }
    return indexes;
}


int main() {
    // Test the CreateString function
    char string1[100];
    char string2[100];
    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);
    char* newString = CreateString(string1, string2);
    printf("Resulting string: %s\n", newString);

    // Test the Start function
    int big[100];
    int big_size;
    int small[100];
    int small_size;
    printf("Enter the size of the first array: ");
    scanf("%d", &big_size);
    printf("Enter the elements of the first array, separated by spaces: ");
    for (int i = 0; i < big_size; i++) {
        scanf("%d", &big[i]);
    }
    printf("Enter the size of the second array: ");
    scanf("%d", &small_size);
    printf("Enter the elements of the second array, separated by spaces: ");
    for (int i = 0; i < small_size; i++) {
        scanf("%d", &small[i]);
    }
    int psize;
    int* indexes = Start(big, big_size, small, small_size, &psize);
    printf("Resulting array: ");
    if (indexes == NULL) {
        printf("NULL");
    } else {
        for (int i = 0; i < psize; i++) {
            printf("%d ", indexes[i]);
        }
    }
    printf("\n");

    // Free the memory allocated by CreateString and Start
    free(newString);
    free(indexes);

    return 0;
}


 */


/*



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
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            count++;
        }
        i++;
    }
    count++; // for the last word

    char** arr = malloc(count * sizeof(char*));
    i = 0;
    int start = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\0') {
            arr[j] = malloc((i - start + 1) * sizeof(char));
            memcpy(arr[j], &str[start], (i - start));
            arr[j][i - start] = '\0';
            j++;
            start = i + 1;
        }
        i++;
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
    scanf("%[^\n]", str);
    getchar();

    int count;
    char** words = Decompose(str, &count);

    printf("Original array of pointers:\n");
    PrintWords(words, count);

    SortWords(words, count);

    printf("Sorted array of pointers:\n");
    PrintWords(words, count);

    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);

    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
*/



/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
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

*/

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

