/* Assignment: 5
Author: Emil Abdumalikov, ID: 
*/


#include <stdio.h>

#define PI 3.14


int main() {
    float length, width, diameter, sRec, sCir;
    printf("Please enter ");
    scanf("%f%f%f", &length, &width, &diameter);

    sRec = length * width;
    sCir = diameter * PI;

    if (sRec < sCir)
        printf("%.0f", sCir);
    else
        printf("%.0f", sRec);


    return 0;
}