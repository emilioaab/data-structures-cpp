/* Assignment: 2
Author: Emil Abdumalikov, ID: 
*/

#include <stdio.h>

int main() {

    char character;


    printf("Please enter a character to view its ASCII number in Decimal and Hexadecimal number:\n");
    scanf("%c", &character);


    printf("%d\n%x", character, character);


    return 0;
}
