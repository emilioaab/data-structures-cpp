#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define N 80

int countLetters();
void ReversePrint();

int main() {
    char str[N];
    gets(str); // for example : Peace and war
    int length = countLetters(str);
    ReversePrint(str, length);

    return 0;
}

void ReversePrint(char str[], int length) {
    for (int i = length; i >= 0; i--)
        printf("%c", str[i]);

}

int countLetters(char str[]) {
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        counter++;
    }
    return counter;
}