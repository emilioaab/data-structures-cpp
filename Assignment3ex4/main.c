/* Assignment: 3
Campus: Beer Sheva
Author: Emil Abdumalikov, ID: 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 100

void spaceRemover(char s[]) {
    int j = 0, i = 0;

    while (s[i]) {
        if (s[i] == ' ') {
            while (s[i + 1] == ' ') {
                i++;
            }
        }

        s[j] = s[i];
        i++;
        j++;

    }

    s[j] = '\0';
    printf("%s", s);

}


int main() {
    char s[SIZE];
    printf("Enter your sentence:\n");
    gets(&s);

    spaceRemover(s);


    return 0;
}
