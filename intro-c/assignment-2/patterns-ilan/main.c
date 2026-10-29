/*Assignment:2
Campus: Beer-Sheva
Author: Ilan Travin , ID:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PatternPrint();
void MagicLetters();
int Palindrom(int number);
int Prime(int number);
void PrimePalindromeScavengerHunt();
void TheGuessingGame();

void MagicLetters() {
    int dif;
    char UserInput1, UserInput2, temp;
    do {
        getchar();
        printf("enter 2 letters\n");
        scanf("%c %c", &UserInput1, &UserInput2); // save use input
        getchar(); // remove the enter
    } while ((!(UserInput1 >= 'A' && UserInput1 <= 'Z') && !(UserInput1 >= 'a' && UserInput1 <= 'z')) || (!(UserInput2 >= 'A' && UserInput2 <= 'Z') && !(UserInput2 >= 'a' && UserInput2 <= 'z')));
    if (UserInput1 >= 'A' && UserInput1 <= 'Z')
    {
        UserInput1 += 32;
    }
    if (UserInput2 >= 'A' && UserInput2 <= 'Z')
    {
        UserInput2 += 32;
    }
    if (UserInput2 > UserInput1)
    {
        temp = UserInput1;
        UserInput1 = UserInput2;
        UserInput2 = temp;
    }
    dif = (int)(UserInput1 - UserInput2);
    for (int i = 0; i <= dif; i++)
    {
        for (char i = UserInput2; i <= UserInput1; i++)
        {
            printf("%c%c ", UserInput2, i);
        }
        printf("\n");
        UserInput2++;
    }





}

void PatternPrint()
{
    int number;

    do {
        printf("enter your number 1-60:");
        scanf("%d", &number);
    } while (!(number > 0 && number <= 60));
    printf("+");
    for (int i = 0; i <= number; i++)
    {
        printf("-");
    }
    printf("+\n");

    for (int row = 0; row <= number; row++)
    {
        printf("|");
        for (int x = 0; x < number - row; x++)
        {
            printf("X");
        }
        printf(" ");
        for (int o = 0; o < row; o++)
        {
            printf("O");
        }
        printf("|\n");
    }

    printf("+");
    for (int i = 0; i <= number; i++)
    {
        printf("-");
    }
    printf("+\n");
}

int Palindrom(int number) {
    int temp = 0, temp1 = number;
    while (temp1 > 0)
    {
        temp = temp * 10;
        temp = temp + (temp1 % 10);
        temp1 = temp1 / 10;
    }
    if (temp == number)
        return 1;
    return 0;
}

int Prime(int number) {
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void PrimePalindromeScavengerHunt() {
    int start, finish, temp;
    do {
        printf("please enter 2 positive numbers:\n");
        scanf("%d %d", &start, &finish);
    } while (start < 0 || finish < 0);
    if (start > finish)
    {
        temp = start;
        start = finish;
        finish = temp;
    }
    for (int i = start; i <= finish; i++)
    {
        if (Prime(i) && Palindrom(i))
            printf("%d ", i);
    }
    printf("\n");
}

void TheGuessingGame() {
    int start, finish,temp,guesses, guess;
    printf("enter a number:\n");
    scanf("%d", &start);
    printf("enter a number:\n");
    scanf("%d", &finish);
    if (start > finish)
    {
        temp = start;
        start = finish;
        finish = temp;
    }
    printf("Enter the number of guesses you would like to make [2-10]:\n");
    scanf("%d", &guesses);
    int value = (rand() % (finish - start + 1)) + start;
    printf("Enter your guess (you have %d guesses left) :\n", guesses);
    scanf("%d", &guess);
    while (guesses > 1)
    {

        guesses--;
        if (guess > finish || guess < start)
        {
            printf("Invalid guess - not in the required range [%d - %d]\n", start, finish);
            scanf("%d", &guess);
        }
        else if (guess > value)
        {
            printf("Enter a lower number (you have %d guesses left) : \n", guesses);
            scanf("%d", &guess);
        }
        else if (guess < value)
        {
            printf("Enter a higher number (you have %d guesses left) : \n", guesses);
            scanf("%d", &guess);
        }
        if (guess == value)
        {
            printf("Congratulations - you have won !\n");
            return;
        }
    }
    printf("Game is over , unsuccessful attempts !\n");
}


int main() {
    int choice;

    do
    {
        printf(" please choose an option:\n 1 - Magic letters\n 2 - The guessing game\n 3 - Pattern print\n 4 - Prime Palindrome scavenger hunt\n 5 - Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                MagicLetters();
                break;
            case 2:
                TheGuessingGame();
                break;
            case 3:
                PatternPrint();
                break;
            case 4:
                PrimePalindromeScavengerHunt();
                break;
            case 5:
                printf("Have a great day & see you soon!\n");
                break;

        }
    } while (choice!=5);


    return 0;
}
