/* Assignment: 5
Author: Emil Abdumalikov, ID: 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a single character using the Caesar cipher
char encryptCharacter(char ch, int key)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = (ch - 'A' + key) % 26 + 'A';
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        ch = (ch - 'a' + key) % 26 + 'a';
    }
    return ch;
}

// Function to encrypt a string using the Caesar cipher
void encryptString(char *str, int key)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = encryptCharacter(str[i], key);
    }
}

int main()
{
    FILE *inputFile, *keyFile, *outputFile;
    char inputFileName[] = "input.txt";
    char keyFileName[] = "key.txt";
    char outputFileName[] = "output.txt";
    char line[100];

    // Open input file
    inputFile = fopen("/Users/emilioaab/CLionProjects/Assignment5/input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error: Unable to open input file '%s'.\n", inputFileName);
        return 1;
    }

    // Open key file
    keyFile = fopen("/Users/emilioaab/CLionProjects/Assignment5/key.txt", "r");
    if (keyFile == NULL)
    {
        printf("Error: Unable to open key file '%s'.\n", keyFileName);
        fclose(inputFile);
        return 1;
    }

    // Open output file
    outputFile = fopen("/Users/emilioaab/CLionProjects/Assignment5/output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error: Unable to create output file '%s'.\n", outputFileName);
        fclose(inputFile);
        fclose(keyFile);
        return 1;
    }

    int key;
    fscanf(keyFile, "%d", &key);
    fclose(keyFile);

    // Read input file line by line and encrypt each line
    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        encryptString(line, key);
        fputs(line, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption complete. Encrypted text saved in '%s'.\n", outputFileName);

    return 0;
}
