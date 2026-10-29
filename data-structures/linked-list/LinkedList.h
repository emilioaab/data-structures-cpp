#define _CRT_SECURE_NO_WARNINGS
#ifndef _LINKEDLIST
#define _LINKEDLIST

typedef struct Node node;
struct Node {
    int data;
    node* next;
};

node* BuildList();
void PrintList(node*);
node* BuildNode(int);
int SumOddIndex(node*);
void ReverseList(node**);
int MultHeadTail(node*);
void IfSorted(node*);
node* MergeSortedLists(node*, node*);
node* RotateList(node*, int);
node* FreeList(node* head);
#endif

#pragma once
