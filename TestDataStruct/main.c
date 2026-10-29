#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Data structure to store the dictionary words
typedef struct word_node {
    char word[20];
    struct word_node *next;
} WordNode;

// Linked list of words
typedef struct {
    WordNode *head;
} HashSet;

// Function to load the dictionary words from a file
HashSet loadDictionary(char* fileName) {
    FILE *fp;
    WordNode *curr, *prev;
    HashSet dict;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    dict.head = NULL;
    while (fscanf(fp, "%s", curr->word)!= EOF) {
        // Add the word to the linked list
        prev = curr;
        curr = (WordNode*) malloc(sizeof(WordNode));
        strcpy(curr->word, prev->word);
        prev->next = curr;
    }

    fclose(fp);
    return dict;
}

// Function to check if a word is in the dictionary
bool isWordInDictionary(HashSet dict, char* word) {
    WordNode *curr = dict.head;
    while (curr!= NULL) {
        if (strcmp(curr->word, word) == 0) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Function to generate all one-letter transformations of a word
void generateTransformations(char* word, HashSet dict, Stack* transformations) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        char c = word[i];
        char transformed[strlen(word)];
        int j;
        for (j = 0; j < strlen(word); j++) {
            if (j!= i) {
                transformed[j] = word[j];
            }
        }
        transformed[i] = toupper(c);
        if (isWordInDictionary(dict, transformed)) {
            push(transformations, transformed);
        }
    }
}

// Function to find the shortest transformation path from startWord to endWord
void wordLadder(char* startWord, char* endWord, char* dictFileName) {
    // Load the dictionary
    HashSet dict = loadDictionary(dictFileName);

    // Create a queue to store the paths
    Queue queue;
    initQueue(&queue);

    // Create a stack to store the current path
    Stack stack;
    initStack(&stack);

    // Push the start word onto the stack
    push(&stack, startWord);

    // Enqueue the initial path
    enqueue(&queue, &stack);

    while (!isEmptyQueue(&queue)) {
        // Dequeue the current path from the queue
        Stack* currentPath = dequeue(&queue);

        // Get the last word from the current path
        char* currentWord = top(currentPath);

        // Check if we have found the end word
        if (strcmp(currentWord, endWord) == 0) {
            // Print the path from bottom to top
            while (!isEmptyStack(currentPath)) {
                printf("%s ", pop(currentPath));
            }
            printf("\n");
            break;
        }

        // Generate all one-letter transformations of the current word
        Stack transformations;
        initStack(&transformations);
        generateTransformations(currentWord, dict, &transformations);

        // Enqueue all new paths that were generated
        while (!isEmptyStack(&transformations)) {
            char* transformedWord = pop(&transformations);
            Stack* newPath = copyStack(currentPath);
            push(newPath, transformedWord);
            enqueue(&queue, newPath);
        }
    }

    // Clean up
    destroyQueue(&queue);
    destroyStack(&stack);
    destroyStack(&transformations);
    return;
}

int main() {
    char startWord[] = "hit";
    char endWord[] = "cog";
    char dictFileName[] = "dict.txt";

    wordLadder(startWord, endWord, dictFileName);
    return 0;
}