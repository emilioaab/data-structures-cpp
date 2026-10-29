/* Assignment: 3.2 (part2.c)
Campus: Beer Sheva
Author: Emil Abdumalikov, ID: 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PlayerName 25
#define SIZE8 8

void ArrayPrint();
int RowCheck();
int ColumnCheck();


int main() {
    char FirstName[PlayerName], SecondName[PlayerName];
    int i, j, FirstScore = 0, SecondScore = 0, arr[SIZE8][SIZE8];


    printf("Please enter 8*8 numbers: \n");
    for( i = 0; i < SIZE8; i++)
    {
        for ( j = 0; j < SIZE8; j++)
        {
            scanf("%d", &arr[i][j]);
            while (arr[i][j] <= 0)
            {
                printf("Please enter only positive numbers! \n");
                scanf("%d", &arr[i][j]);
            }
        }
    }

    printf("Please enter 1st players name: \n");
    scanf("%s", &FirstName);
    printf("Please enter 2nd players name: \n");
    scanf("%s", &SecondName);
    ArrayPrint(arr);
    printf("%s = %d, %s = %d \n", FirstName, FirstScore, SecondName, SecondScore);
    printf("Please enter first cordinator - a row and a column %s: \n", FirstName);
    scanf("%d%d", &i, &j);
    i--;
    j--;

    while(!(i < SIZE8 && i >= 0 && j >= 0 && j < SIZE8))
    {
        printf("Please try again and put a better cordinator: \n");
        scanf("%d%d", &i, &j);
    }

    FirstScore += arr[i][j];
    arr[i][j] = 0;
    ArrayPrint(arr);
    arr[i][j] = -1;

    printf("%s = %d, %s = %d", FirstName, FirstScore, SecondName, SecondScore);

    while (1)
    {
        if (ColumnCheck(arr, j) == 0)
            break;

        printf("%s, Enter a row: \n", SecondName);
        scanf("%d", &i);
        i--;

        while (!(i < SIZE8 && i >= 0 && j >= 0 && j < SIZE8 && arr[i][j] > 0))
        {
            printf("Bad row choice try again!: \n");
            scanf("%d", &i);
            i--;
        }

        SecondScore += arr[i][j];
        arr[i][j] = 0;
        ArrayPrint(arr);
        arr[i][j] = -1;

        printf("%s = %d , %s = %d\n", FirstName, FirstScore, SecondName, SecondScore);
        if (RowCheck(arr, i) == 0)
            break;

        printf("%s, Enter a column: \n", FirstName);
        scanf("%d", &j);
        j--; //[0-size]

        while (!(i < SIZE8 && i >= 0 && j >= 0 && j < SIZE8 && arr[i][j] > 0))
        {
            printf("Bad column choice try again!: \n");
            scanf("%d", &j);
            j--;
        }

        FirstScore += arr[i][j];
        arr[i][j] = 0;
        ArrayPrint(arr);
        arr[i][j] = -1;

        printf("%s = %d , %s = %d\n", FirstName, FirstScore, SecondName, SecondScore); // names and scores
    }

    if(FirstScore > SecondScore)
        printf("Congratulations %s is the Winner! \n", FirstName);
        else
            if(FirstScore < SecondScore)
                 printf("Congratulations %s is the Winner! \n", SecondName);
                    else
                        printf("No one is a winner try again");

    return 0;

}


void ArrayPrint(int arr[SIZE8][SIZE8]){    //a function that prints the board
    for(int i = 0; i < SIZE8; i++){
        for (int j = 0; j < SIZE8; ++j) {
            if(arr[i][j] == 0)
                printf("    *");
            else
                if(arr[i][j] == -1)
                    printf("    -");
                    else
                        printf("%5d", arr[i][j]);
        }
        printf("\n");
    }

}

int RowCheck(int arr[SIZE8][SIZE8], int row)  //Row check function
{
    for (int i = 0; i < SIZE8; ++i) {
        if(arr[row][i]>0)
            return 1;
    }
    return 0;
}

int ColumnCheck(int arr[SIZE8][SIZE8], int col) //Column check function
{
    for (int j = 0; j < SIZE8; ++j) {
        if (arr[col][j] > 0)
            return 1;
    }
    return 0;
}
