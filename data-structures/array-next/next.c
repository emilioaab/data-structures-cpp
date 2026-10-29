#define _CRT_SECURE_NO_WARNINGS
#include "next.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack functions
StackNode *createStackNode(char *word)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

Stack* createStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (s == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	s->top = NULL;
	return s;
}

int isEmpty(Stack* s)
{
	return (s->top == NULL);
}

void push(Stack* s, char* data)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (newNode == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	strcpy(newNode->word, data);
	newNode->next = s->top;
	s->top = newNode;
}

char* pop(Stack* s)
{
	if (isEmpty(s))
	{
		printf("Stack is empty\n");
		exit(1);
	}
	StackNode* temp = s->top;
	s->top = s->top->next;
	char* popped = temp->word;
	free(temp);
	return popped;
}



// queue functions

Queue* createQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	q->front = NULL;
	q->rear = NULL;
	return q;
}

int isQueueEmpty(Queue* q)
{
	return (q->front == NULL);
}


void enqueue(Queue* q, Stack* s) {
	// Create a new node
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}
	newNode->Stack = s;
	newNode->next = NULL;

	// If the queue is empty, set the new node as both front and rear
	if (q->rear == NULL) {
		q->front = q->rear = newNode;
		return;
	}

	// Otherwise, add the new node to the end of the queue
	q->rear->next = newNode;
	q->rear = newNode;
}


Stack* dequeue(Queue* q) {
	// Check if the queue is empty using isQueueEmpty function
	if (isQueueEmpty(q)) {
		printf("Queue is empty. Cannot dequeue.\n");
		return NULL;
	}

	// Get the stack from the front node
	Stack* s = q->front->Stack;

	// Store the front node temporarily
	QueueNode* temp = q->front;

	// Move the front pointer to the next node
	q->front = q->front->next;

	// If the queue becomes empty, update the rear pointer
	if (q->front == NULL) {
		q->rear = NULL;
	}

	// Free the memory of the dequeued node
	free(temp);

	// Return the dequeued stack
	return s;
}



// other functions

bool isAdjacent(char* word1, char* word2)
{
	int count = 0;
	for (int i = 0; i < strlen(word1); i++)
	{
		if (word1[i] != word2[i])
		{
			count++;
		}
	}
	return (count == 1);
}

void printWordLadder(Stack* stack) {
	StackNode* current = stack->top;
	while (current != NULL) {
		printf("%s", current->word);
		if (current->next != NULL) {
			printf(" -> ");
		}
		current = current->next;
	}
	printf("\n");
}

void WordLadder(char* start_word, char* end_word, char dictionary[][MAX_WORD_LENGTH])
{
	// Create a queue and enqueue a stack containing the start word
	Queue* q = createQueue();
	Stack* s = createStack();
	push(s, start_word);
	enqueue(q, s);

	// Create a boolean array to keep track of visited words
	bool* visited = (bool*)malloc(num_words * sizeof(bool));
	if (visited == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	for (int i = 0; i < num_words; i++)
	{
		visited[i] = false;
	}

	// While the queue is not empty
	while (!isQueueEmpty(q))
	{
		// Dequeue a stack from the queue
		Stack* current = dequeue(q);

		// Get the top word from the stack
		char* top_word = current->top->word;

		// If the top word is the end word, print the word ladder and return
		if (strcmp(top_word, end_word) == 0)
		{
			printWordLadder(current);
			free(visited);
			return;
		}

		// Find all adjacent words to the top word
		for (int i = 0; i < num_words; i++)
		{
			if (!visited[i] && isAdjacent(top_word, dictionary[i]))
			{
				// Mark the adjacent word as visited
				visited[i] = true;

				// Duplicate the current stack
				Stack* newStack = createStack();
				StackNode* temp = current->top;
				while (temp != NULL)
				{
					push(newStack, temp->word);
					temp = temp->next;
				}

				// Push the adjacent word onto the new stack
				push(newStack, dictionary[i]);

				// Enqueue the new stack
				enqueue(q, newStack);
			}
		}
	}

	// If the end word is not reachable, print a message
	printf("No word ladder found.\n");
	free(visited);
}
