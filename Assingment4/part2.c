/* Assignment: 4.2
Author: Emil Abdumalikov, ID: 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dupCheck();

void BuildGroup(int **group, int *count) {
    int size;
    printf("Please enter the size of the group:\n");
    scanf("%d", &size);

    *count = size;

    *group = (int *) malloc(size * sizeof(int)); //Memory allocation

    if (group == NULL) { //memory alloc check
        printf("Memory not allocated.\n");
        exit(0);
    }

    int temp; //temp is used to contain the numbers so it won't override them

    printf("Enter the group values:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &temp);

        do {
            if (dupCheck(*group, temp, size)) { //The number is duplicated
                printf("The number that you've entered is repeating itself, enter a new number\n ");

                scanf("%d", &temp);
            }
        } while (dupCheck(*group, temp, size));

        (*group)[i] = temp; //initialization of the numbers in the new malloc

    }
}

int dupCheck(int *group, int temp, size) {
    for (int i = 0; i < size; i++) {
        if (group[i] == temp) { //the number repeated itself do another one
            return 1;
        }
    }
    return 0;
}

int *Union(int *group1, int size1, int *group2, int size2, int *sizeUnion) {
    int i, j, sizeOfNewGroup;

    int size = size1 + size2;

    int *UnionGroup = (int *) malloc(size * sizeof(int));
    if (UnionGroup == NULL) { //memory alloc check
        printf("Memory not allocated.\n");
        exit(0);
    }

    for (i = 0; i < size1; i++) { //group1 initialization into Union group
        UnionGroup[i] = group1[i];
    }
    sizeOfNewGroup = size1;

    for (j = 0; j < size2; j++) { //group2 initialization into Union group
        int duplicate = 0;
        for (int k = 0; k < sizeOfNewGroup; k++) {
            if (group2[j] == UnionGroup[k]) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate == 0) {
            UnionGroup[sizeOfNewGroup++] = group2[j];
        }
    }
    *sizeUnion = sizeOfNewGroup;

    UnionGroup = (int *) realloc(UnionGroup, sizeOfNewGroup * sizeof(int));
    if (UnionGroup == NULL) { //memory alloc check
        printf("Memory not allocated.\n");
        exit(0);
    }
    return UnionGroup;
}

int *Intersection(int *group1, int size1, int *group2, int size2, int *sizeInter) {

    int i, j, sizeOfNewGroup = 0;
    int size = size1 + size2;

    int *IntersectionGroup = (int *) malloc(size * sizeof(int));
    if (IntersectionGroup == NULL) { //memory alloc check
        printf("Memory not allocated.\n");
        exit(0);
    }
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (group1[i] == group2[j]) {
                IntersectionGroup[sizeOfNewGroup++] = group1[i];
            }
        }
    }
    *sizeInter = sizeOfNewGroup;

    IntersectionGroup = (int *) realloc(IntersectionGroup, sizeOfNewGroup * sizeof(int));
    if (IntersectionGroup == NULL) { //memory alloc check
        printf("Memory not allocated.\n");
        exit(0);
    }
    return IntersectionGroup;
}

int *Minus(int *group1, int size1, int *group2, int size2, int *sizeMinus) {
    int i, j, sizeOfNewGroup = 0;
    int size = size1;

    int *MinusGroup = (int *) malloc(size * sizeof(int));
    if (MinusGroup == NULL) { //memory alloc check
        printf("Memory not allocated.\n");
        exit(0);
    }
    for (i = 0; i < size1; i++) {
        int present = 0;
        for (j = 0; j < size2; j++) {
            if (group1[i] == group2[j]) {
                present = 1;
                break;
            }
        }
        if (!present) {
            MinusGroup[sizeOfNewGroup++] = group1[i];
        }
    }
    *sizeMinus = sizeOfNewGroup;

    MinusGroup = (int *) realloc(MinusGroup, sizeOfNewGroup * sizeof(int));
    if (MinusGroup == NULL) { //memory alloc check
        printf("Memory not allocated.\n");
        exit(0);
    }

    return MinusGroup;
}

void PrintGroup(int *group, int size) {

    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", group[i]);
        if (group[i] != group[size - 1]) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    int *group1, *group2, size1, size2, sizeUnion, sizeIntersection, sizeMinus;

    BuildGroup(&group1, &size1);
    BuildGroup(&group2, &size2);
    int *UnionGroup2 = Union(group1, size1, group2, size2, &sizeUnion);
    int *IntersectionGroup2 = Intersection(group1, size1, group2, size2, &sizeIntersection);
    int *MinusGroup2 = Minus(group1, size1, group2, size2, &sizeMinus);
    printf("The first group: ");
    PrintGroup(group1, size1);
    printf("\nThe second group: ");
    PrintGroup(group2, size2);
    printf("\nThe Union group: ");
    PrintGroup(UnionGroup2, sizeUnion);
    printf("\nThe Intersection group: ");
    PrintGroup(IntersectionGroup2, sizeIntersection);
    printf("\nThe Minus group: ");
    PrintGroup(MinusGroup2, sizeMinus);

    free(group1);
    free(group2);
    free(UnionGroup2);
    free(IntersectionGroup2);
    free(MinusGroup2);

    return 0;
}