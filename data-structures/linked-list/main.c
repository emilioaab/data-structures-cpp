#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Linkedlist.h"


int main()
{
    node* list1 = NULL, * list2 = NULL, * mergedList = NULL, * rotatedList = NULL;
    int num_min, mult_res, middle, sum_odd_ind;
    list1 = BuildList();


    /* task1 */
    printf("\n task1 - SumOddIndex\n");
    sum_odd_ind = SumOddIndex(list1);
    printf("\nSum of Odd index = %d\n", sum_odd_ind);


    /* task2 */
    printf("\n task3 - ReverseList\n");
    ReverseList(&list1);
    PrintList(list1);
    ReverseList(&list1);

    /* task3 */
    printf("\n task5 - MultHeadTail\n");
    mult_res = MultHeadTail(list1);
    printf("\n(head->data)*(tail->data) = %d\n", mult_res);

    /* task4 */
    printf("\n task6 - IfSorted\n\n");
    IfSorted(list1);

    /* task5 */
    printf("\n task8 - MergeSortedLists\n");
    mergedList = MergeSortedLists(list1, list2);
    PrintList(mergedList);


    /* task6 */
    printf("\n task9 - RotateList: k = -2\n");
    int k = -2; // Rotate by 4 places
    rotatedList = RotateList(mergedList, k);
    PrintList(rotatedList);

    printf("\n task9 - RotateList: k = 4\n");
    k = 4; // Rotate by 4 places
    rotatedList = RotateList(rotatedList, k);
    PrintList(rotatedList);

    /* FreeList */

    return 0;
}