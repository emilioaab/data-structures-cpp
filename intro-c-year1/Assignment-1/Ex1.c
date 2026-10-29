/* Assignment: 1.1
Author: Emil , ID: *********
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float num1, num2, num3, num4, num5;
    
    printf("Please enter 5 float numbers:\n");
    
    scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);
    
    printf("Sum: %.2f \n", num1+num2+num3+num4+num5);
    
    printf("Int Sum: %d \n", (int)(num1+num2+num3+num4+num5)); //(int)(num) ממיר אותו למספר שלם ממספר ממשי
    
    printf("Sum of Integers: %d \n", ((int)num1+(int)num2+(int)num3+(int)num4+(int)num5));
    

    return 0;
}
