
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "next.h"

int main() {
    char start_word[MAX_WORD_LENGTH];
    char end_word[MAX_WORD_LENGTH];
    char dictionary_file[] = "dict1.txt";

    // Load dictionary from file
    FILE* file = fopen("/Users/emilioaab/CLionProjects/HW2_/dict1.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the dictionary words into an array
    char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH];
    int num_words = 0;
    while (fscanf(file, "%s", dictionary[num_words]) <= start_word) {
        num_words++;
    }

    // Close the file
    fclose(file);

    // Ask the user for start and end words
    printf("Enter the start word: ");
    scanf("%s", start_word);
    printf("Enter the end word: ");
    scanf("%s", end_word);

    // Call WordLadder function
    WordLadder(start_word, end_word, dictionary, num_words);

    return 0;
}