#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 10
#define MAX_DICT_SIZE 1000

typedef struct StackNode {
	char word[MAX_WORD_LENGTH];
	struct StackNode* next;
} StackNode;

typedef struct Stack {
	StackNode* top;
} Stack;

typedef struct QueueNode {
	Stack* Stack;
	struct QueueNode* next;
} QueueNode;

typedef struct Queue {
	QueueNode* front;
	QueueNode* rear;
} Queue;

//functions for stack
Stack* createStack();
int isEmpty(Stack* s);
void push(Stack* s, char* word);
char* pop(Stack* s);

//functions for queue
Queue* createQueue();
void enqueue(Queue* q, Stack* s);
Stack* dequeue(Queue* q);
int isQueueEmpty(Queue* q);

//other functions
bool isAdjacent(char* word1, char* word2);
void printWordLadder(Stack* stack);
void WordLadder(char* start_word, char* end_word, char dictionary[][MAX_WORD_LENGTH], int num_words);


#endif