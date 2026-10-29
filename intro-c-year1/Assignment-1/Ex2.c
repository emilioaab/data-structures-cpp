/* Assignment: 1.2
Author: Emil, ID: *********
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float num;

    printf("Please enter a float number: \n");

    scanf("%f", &num);
    
    
    printf("The value is: %.1f\n", num);

    printf("The integer value is: %d\n",(int)num);

    printf("The integer in hexadecimal base is: 0x%X\n", (int)num);

    printf("The char is: %c\n", (char)num);
    
    return 0;
    
}
