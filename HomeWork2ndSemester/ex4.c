/* Assignment: 4
Author: Emil Abdumalikov, ID: 
*/

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
