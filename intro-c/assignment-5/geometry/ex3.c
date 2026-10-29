/* Assignment: 3
Author: Emil Abdumalikov, ID: 
*/


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