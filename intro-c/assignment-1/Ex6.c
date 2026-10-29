/* Assignment: 1.6
Author: Emil, ID: *********
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int dayA, monthA, yearA, dayB, monthB, yearB;
    
    printf("Enter birth date of A:\n");
    scanf("%d%d%d", &dayA, &monthA, &yearA);
    
    printf("Enter birth date of B:");
    scanf("%d%d%d", &dayB, &monthB, &yearB);
    
    if(dayA == dayB && monthA == monthB && yearA == yearB)
        printf("Please try a a different date.\n");
    
        else if(yearA>yearB || (yearA == yearB && monthA > monthB) || (yearA == yearB && monthA == monthB && dayA > dayB))
            printf("A is younger!\n");
        
    else
        printf("B is younger!\n");

    
    return 0;
}
