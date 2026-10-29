/* Assignment: 1.3
Author: Emil, ID: *********
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float a1, d, an, Sn;
    int n;
    
    printf("Please insert an a1:\n\n");
    scanf("%f", &a1);
    
    printf("Please insert a d:\n\n");
    scanf("%f", &d);
    
    printf("Please insert n:\n\n");
    scanf("%d", &n);
    
    an=(a1+(n-1)*d);
    
    printf("The 3 number in the sequence is: %.1f \n\n" ,an);
    
    Sn=(n*(a1+an))/2;
    
    printf("The sum of all the numbers till the 3 number is: %.1f \n\n\n" , Sn);
    
    return 0;
}
