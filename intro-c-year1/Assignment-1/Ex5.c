/* Assignment: 1.5
Author: Emil, ID: *********
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int num;
    
    printf("Please enter an integer number to see if it's positive/negative & even/odd.\n");
    
    scanf("%d", &num);
    
    if(num>=0 && num%2==0)
        printf("The number %d is positive and even.\n", num);
    
    else if(num>=0 && (num%2)!=0)
        printf("The number %d is positive and odd.\n", num);
    
    else if(num<=0 && num%2==0)
        printf("The number %d is negative and even.\n", num);
    
    else if(num<=0 && (num%2)!=0)
        printf("The number %d is negative and odd.\n", num);
    
    return 0;
    

}
