/*
Asisignment : 5
Author : Emil Abdumalikov
id: 
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *readfile = NULL;
    FILE *writefile = NULL;
    int size = 0, grade, sum;
    char NAME[25];
    double Average;

    readfile = fopen("/Users/emilioaab/Documents/grades.txt", "r"); //files location might change when you will open the program, please make sure to change file destination before use
    if (readfile == NULL) {
        printf("Error while trying to open file grades.txt");
        exit(1);
    }

    writefile = fopen("/Users/emilioaab/Documents/averages.txt", "a+"); //files location might change when you will open the program, please make sure to change file destination before use
    if (writefile == NULL) {
        printf("Error while trying to open file averages.txt");
        fclose(readfile);
        exit(1);
    }

    while (fscanf(readfile, "%s %d", NAME, &size) != EOF) {
        sum = 0;
        for (int i = 0; i < size; i++) {
            fscanf(readfile, "%d", &grade);
            sum += grade;
        }
        Average = (double) sum / size;
        printf("%s %lf\n", NAME, Average);
        fprintf(writefile, "%s %lf\n", NAME, Average);

    }

    fclose(writefile);
    fclose(readfile);

    return 0;

}
