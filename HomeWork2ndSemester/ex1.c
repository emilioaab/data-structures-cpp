/* Assignment: 1
Author: Emil Abdumalikov, ID: 
*/
#include <stdio.h>


int main() {
    float num1, num2, num3, avgFloat = 0;
    int avgRoundedUp = 0;
    int avgInt = 0;

    printf("Please enter 3 real numbers to calculate the average: \n");
    scanf("%f%f%f", &num1, &num2, &num3);

    avgFloat = (num1 + num2 + num3) / 3;
    avgRoundedUp = (int) ((num1 + num2 + num3) / 3 + 0.9);
    avgInt = (int) (num1 + num2 + num3) / 3;

    printf("%f\n%d\n%d\n", avgFloat, avgRoundedUp, avgInt);


    return 0;
}