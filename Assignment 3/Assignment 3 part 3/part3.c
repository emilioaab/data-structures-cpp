/* Assignment: 3.3 (part3.c)
Campus: Beer Sheva
Author: Emil Abdumalikov, ID: 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 80

void WordsChanger();
void SmallBigChar();
void LettersChanger();

int main() {
    int i;
    char string[SIZE];
    char temporary[SIZE];
    fgets(string, SIZE, stdin);

    for (i = 0; string[i] != '\0'; i++)
    {
        temporary[i] = string[i];
    }
    temporary[i] = '\0';
    LettersChanger(temporary);
    printf("%s", temporary);

    for (i = 0; string[i] != '\0'; i++)
    {
        temporary[i] = string[i];
    }
    temporary[i] = '\0';

    WordsChanger(temporary);
    printf("%s", temporary);

    for (i = 0; string[i] != '\0'; i++)
    {
        temporary[i] = string[i];
    }
    temporary[i] = '\0';

    SmallBigChar(temporary);
    printf("%s", temporary);
    return 0;
}



void WordsChanger(char s[]) {
    char temporary[SIZE];
    int i, j,k;
    for (i = 0; s[i] != '\n'; i++);
    i--;
    k=i;
    for (j = 0; j <= k; j++, i--) {
        temporary[j] = s[i];
    }
    temporary[j] = '\n';
    LettersChanger(temporary);
    for (i = 0; s[i] != '\n'; i++){
        s[i] = temporary[i];
    }

}


void SmallBigChar(char s[]) {
    for (int i = 0; s[i] != '\n'; i++) {
        if ( s[i] <= 'z' && s[i] >= 'a')
            s[i] -= 32;
        else
        if (s[i] <= 'Z' && s[i] >= 'A')
            s[i] += 32;
    }
}

void LettersChanger(char s[]) {
    char temporary[SIZE];
    int flag = 1, i = 0, j = 0, k;

    while (flag != 0){
        for (i = j+1; s[i] != ' '; i++){
            if (s[i] == '\n'){
                flag = 0;
                break;
            }
        }
        i--;
        for (k=j ; i >= k; i--, j++){
            temporary[j] = s[i];
        }
        temporary[j] = ' ';
        j++;
    }

    for (i = 0; s[i] != '\n'; i++){
        s[i] = temporary[i];
    }
}


