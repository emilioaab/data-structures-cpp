/* Assignment: 1.4
Author: Emil, ID: *********
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float num1, num2;
    
    printf("Please insert 2 float numbers:\n");
    
    scanf("%f %f", &num1, &num2);
    
    
    if(num1<0||num2<0)
        printf("Error!!! Try numbers that are bigger than 0.\n");
    
    else
        if(num1-(int)num1==num2-(int)num2)
            printf("%.3f\n", num1);
    
    else
        if(num1-(int)num1>num2-(int)num2)
            printf("%.3f\n", num1);
    
    else
        
            printf("%.3f\n", num2);
    
    return 0;
    
    
}
