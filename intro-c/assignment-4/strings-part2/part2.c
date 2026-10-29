/* Assignment: 4.2
Author: Emil Abdumalikov, ID: 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* CreateString(char* string1, char* string2) {
    int newStringLength = strlen(string1) + (strlen(string1) - 1) * strlen(string2);
    char* newString = malloc(newStringLength + 1); // +1 for the null terminator

    int currentPos = 0;

    for (int i = 0; string1[i] != '\0'; i++) {

        newString[currentPos] = string1[i];
        currentPos++;

        for (int j = 0; string2[j] != '\0'; j++) {
            newString[currentPos] = string2[j];
            currentPos++;
        }
    }

    newString[currentPos] = '\0';

    return newString;
}

int main() {
    char originalString[100];
    char stringToInsert[100];

    printf("Enter original string: ");
    scanf("%s", originalString);

    printf("Enter string to insert: ");
    scanf("%s", stringToInsert);

    char* newString = CreateString(originalString, stringToInsert);
    printf("New string: %s\n", newString);

    return 0;
}