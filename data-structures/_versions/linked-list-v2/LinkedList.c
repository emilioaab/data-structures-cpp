#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Linkedlist.h"

node* BuildNode(int num1)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = num1;
    new_node->next = NULL;
    return new_node;
}
/*====================================================*/
node* BuildList()
{
    node* head = NULL, * temp = head;
    int num;
    printf("Enter numbers for the list, enter -1 for the end: ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (head == NULL)
        {
            head = BuildNode(num);
            temp = head;
        }
        else
        {
            temp->next = BuildNode(num);
            temp = temp->next;
        }
        scanf("%d", &num);
    }
    return head;
}
/*====================================================*/
void PrintList(node* head)
{
    node* temp = head;
    printf("\nThe list is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//1.
int SumOddIndex(node* head)
{
    int sum = 0;
    node* temp = head;
    for (int i = 1; temp != NULL; i++) {
        if (i % 2 == 1)
            sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

//2.

void ReverseList(node** head) {
    node* prev = NULL;
    node* temp = *head;
    node* next = NULL;

    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
}

//3.
int MultHeadTail(node* head)
{
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return head->data * temp->data;
}

//4.
void IfSorted(node* head)
{
    node* temp = head;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data) {
            printf("The List is not sorted\n");
            return;
        }
        temp = temp->next;
    }
    printf("The List is sorted\n");
}

//5.
node* MergeSortedLists(node* list1, node* list2) {
    node* mergedList = NULL;
    node* tail = NULL;

    if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;

    if (list1->data <= list2->data) {
        mergedList = list1;
        list1 = list1->next;
    }
    else {
        mergedList = list2;
        list2 = list2->next;
    }

    tail = mergedList;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1 != NULL) {
        tail->next = list1;
    }
    else {
        tail->next = list2;
    }

    return mergedList;
}


//6.
node* RotateList(node* list, int k) {
    int counter = 1;
    if (list == NULL || k == 0) {
        return list;
    }

    node* tail = list;
    while (tail->next != NULL) {
        tail = tail->next;
        counter++;
    }
    k = k % counter;
    if (k < 0) {
        k = counter + k;
    }
    if (k == 0) {
        return list;
    }
    node* tail1 = list;
    for (int i = 1; i < counter - k; i++) {
        tail1 = tail1->next;
    }
    node* head1 = tail1->next;
    tail->next = list;
    tail1->next = NULL;

    return head1;
}

node *FreeList(node *head) {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
        temp = NULL; // Set the freed pointer to NULL for safety
    }
    return NULL;
}


