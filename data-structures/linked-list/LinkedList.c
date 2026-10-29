#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"Linkedlist.h"

node *BuildNode(int num1) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = num1;
    new_node->next = NULL;
    return new_node;
}

/*====================================================*/
node *BuildList() {
    node *head = NULL, *temp = head;
    int num;
    printf("Enter numbers for the list, enter -1 for the end: ");
    scanf("%d", &num);
    while (num != -1) {
        if (head == NULL) {
            head = BuildNode(num);
            temp = head;
        } else {
            temp->next = BuildNode(num);
            temp = temp->next;
        }
        scanf("%d", &num);
    }
    return head;
}

/*====================================================*/
void PrintList(node *head) {
    node *temp = head;
    printf("\nThe list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//1.
int SumOddIndex(node *head) {
    int sum = 0;
    node *temp = head;
    for (int i = 1; temp != NULL; i++) {//for loop until temp points to null
        if (i % 2 == 1)//if index is odd add the value to sum
            sum += temp->data;
        temp = temp->next;//temp points to the next node
    }
    return sum;
}

//2.

void ReverseList(node **head) {
    node *prev = NULL;
    node *temp = *head;
    node *next = NULL;

    while (temp != NULL) {
        // Store next node
        next = temp->next;
        // Reverse current node's pointer
        temp->next = prev;
        // Move pointers one position ahead
        prev = temp;
        temp = next;
    }
    // Update head to point to the new first node (previous last node)
    *head = prev;
}

//3.
int MultHeadTail(node *head) {
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return head->data * temp->data;
}

//4.
void IfSorted(node *head) {
    node *temp = head;
    //int prevData = temp->data;
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
    node dummy;
    node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = (list1 != NULL) ? list1 : list2;

    return dummy.next;
}
node* MergeSortedLists(node* list1, node* list2) {
    // ????? ?? ????? ??? ?? ??? ??????? ?????
    if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;

    node* mergedList = NULL; // ????? ?????? ????
    node* tail = NULL; // ????? ???? ?????? ???????

    // ????? ???? ?? ?????? ??????? ??? ???? ???????? ?????? ??? ???????
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
        tail = tail->next; // ????? ?????? ???? ?????? ???????
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


node *RotateList(node *list, int k) {
    if (list == NULL || k == 0) {
        // If the list is empty or k is 0, no rotation is needed
        return list;
    }

    int length = 1; // Length of the list
    node *tail = list;

    // Find the length of the list and locate the tail node
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Adjust k to be within the range of [0, length)
    k = k % length;

    if (k < 0) {
        // If k is negative, rotate counter-clockwise
        k = length + k; // Convert negative rotation to positive
    }

    if (k == 0) {
        // If k is 0 after adjustment, no rotation is needed
        return list;
    }

    // Find the (length - k)-th node (new tail) and the (length - k + 1)-th node (new head)
    int steps_to_new_tail = length - k;
    node *new_tail = list;
    for (int i = 1; i < steps_to_new_tail; i++) {
        new_tail = new_tail->next;
    }

    // Update pointers
    tail->next = list; // Make the list circular
    list = new_tail->next; // New head
    new_tail->next = NULL; // New tail

    return list;
}

node *FreeList(node *head) {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

