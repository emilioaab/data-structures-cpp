/* Assignment: 4.1
Author: Emil Abdumalikov, ID: 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to concatenate two strings with a new string where the second string is repeated after each character of the first string
char *CreateString(char *string1, char *string2) {
    // Get the length of the first string
    int string1Length = strlen(string1);
    // Get the length of the second string
    int string2Length = strlen(string2);
    // Calculate the length of the new string
    int newStringLength = string1Length + (string1Length * string2Length) + 1;

    // Allocate memory for the new string
    char *newString = (char *) malloc(newStringLength * sizeof(char));

    // Check if memory allocation was successful
    if (newString == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        // Loop through each character in the first string
        int j = 0;
        for (int i = 0; i < string1Length; i++) {
            // Add the current character of the first string to the new string
            newString[j++] = string1[i];
            // Loop through each character in the second string
            for (int k = 0; k < string2Length; k++) {
                // Add the current character of the second string to the new string
                newString[j++] = string2[k];
            }
        }
        // Add a null character to the end of the new string to terminate it
        newString[j] = '\0';
    }

    // Return the new string
    return newString;
}

// Function to check if a word is a palindrome (reads the same backwards as forwards)
int isPalindrome(char *word) {
    // Get the length of the word
    int len = strlen(word);
    // Calculate the middle index of the word
    int middle = len / 2;
    // Loop through the first half of the word
    for (int i = 0; i < middle; i++) {
        // If the current character does not match its corresponding character from the end of the word, it's not a palindrome
        if (word[i] != word[len - i - 1]) {
            return 0;
        }
    }
    // If the function has not yet returned, the word is a palindrome
    return 1;
}

// Function to find all palindromes in a given string
char *Palindromes(char *str) {
    // Check if the input string is empty or null
    if (str == NULL || strlen(str) == 0) {
        return NULL;
    }
    // Get the length of the input string
    int stringLength = strlen(str);
    // Allocate memory for a new string to store the palindromes
    char *newString = (char *) malloc(stringLength * sizeof(char));

    // Check if memory allocation was successful
    if (newString == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Count the number of words in the input string
    int wordCount = 0;
    char *p = str;
    while (*p != '\0') {
        if (*p == ' ') {
            wordCount++;
        }
        p++;
    }
    wordCount++;

    // Initialize a counter for the number of palindromes found
    int count = 0;
    // Pointer to the current word being checked
    char *word;


    // Initialize the new string to an empty string
    newString[0] = '\0';

    // Tokenize the input string into separate words and loop through each word
    word = strtok(str, " ");
    while
 (word != NULL) {
        // Check if the current word is a palindrome and add it to the new string if it is
        if (isPalindrome(word)) {
            count++;
            newString = (char *) realloc(newString, (strlen(newString) + strlen(word) + 2) * sizeof(char));
            strcat(newString, word);
            strcat(newString, " ");
        }
        word = strtok(NULL, " ");
    }

    // Check if any palindromes were found in the input string and return the new string
    if (count == 0) {
        free(newString);
        return NULL;
    }

    newString[strlen(newString) - 1] = '\0';
    return newString;
}

/* Main function that takes user input and calls other functions */
int main() {
    char *string1[80];
    char *string2[80];

    printf("Enter your String: \n");
    scanf("%s", string1);
    scanf("%s", string2);
    getchar();

    char *newString = CreateString(string1, string2);
    printf("CreateString result: %s\n", newString);
    free(newString);

    char *inputString[80];
    printf("\nEnter a string: \n");
    fgets(inputString, 80, stdin);


// Add a space after the input string
    int input_len = strlen(inputString);
    if (inputString[input_len - 1] != ' ') {
        inputString[input_len - 1] = ' ';
        inputString[input_len] = '\0';
    }


    char *palindromeString = Palindromes(inputString);
    if (palindromeString != NULL) {
        printf("Palindromes result: %s\n", palindromeString);
        free(palindromeString);
    } else {
        printf("No palindromes found.\n");
    }

    return 0;
}