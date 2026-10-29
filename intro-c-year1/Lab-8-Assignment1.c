#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define N 80

int countLetters();

int main() {
    char str[N];
    gets(str); // for example : John lives in London
    printf("Count of letters in '%s': %d\n", str, countLetters(str));
    return 0;
}

int countLetters(char str[]) {
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        counter++;
    }
    return counter;


}