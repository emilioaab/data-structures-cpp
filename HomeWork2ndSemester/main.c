/* Assignment: 1
Author: Emil Abdumalikov, ID: 
*/

/*

#include <stdio.h>


int main() {
    float num1, num2, num3, avgFloat = 0;
    int avgRoundedUp = 0;
    int avgInt = 0;

    printf("Please enter 3 real numbers to calculate the average: \n");
    scanf("%f%f%f", &num1, &num2, &num3);

    avgFloat = (num1+num2+num3)/3;
    avgRoundedUp = (int)((num1+num2+num3)/3+0.9);
    avgInt = (int)(num1+num2+num3)/3;

    printf("%f\n%d\n%d\n", avgFloat, avgRoundedUp, avgInt);


    return 0;
}

*/

/*
#include <stdio.h>

int main(){

    char character;


    printf("Please enter a character to view its ASCII number in Decimal and Hexadecimal number:\n");
    scanf("%c", &character);


    printf("%d\n%x", character, character);





    return 0;
}

 */
/*

#include <stdio.h>
#include <math.h>

int main() {

    float sum, A, R;
    int N;

    printf("Please");
    scanf("%f %f %d", &A, &R, &N);

    sum = A * ((1 - powf(R, N)) / (1 - R));

    printf("%f", sum);

    return 0;
}
*/

/*
#include <stdio.h>

int main() {
    int num, x, y, reverse;

    printf("Please enter an integer, positive, two digits number: \n");
    scanf("%d", &num);

    y = num % 10;
    x = num / 10;

    if (y > x) {
        reverse = y * 10 + x;
        printf("%d", reverse);
    } else
        printf("%d", num);


    return 0;
}
*/



#include <stdio.h>
#define PI 3.14


int main() {
    float length, width, diameter, sRec, sCir;
    printf("Please enter ");
    scanf("%f%f%f", &length, &width, &diameter);

    sRec = length*width;
    sCir = diameter * PI;

    if(sRec<sCir)
        printf("%.0f", sCir);
    else
        printf("%.0f", sRec);


    return 0;
}



/*
#include <stdio.h>

int main() {
    int year;
    printf("please enter a year:\n");
    scanf("%d", &year);

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        printf("Y");

    else
        printf("N");


    return 0;
}
*/