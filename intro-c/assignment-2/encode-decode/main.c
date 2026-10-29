/*
Assignment: 2
Campus: Beer-Sheva
Author: Emil Abdumalikov, ID: 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char Encode();
char Decode();

int main() {
    char choice;  //E or D

    do {
        printf("Please enter 'E' to Encode or 'D' to Decode, after that C/R/D, key integer number, and the message:\n");
        scanf("%c ", &choice);


        switch (choice) {
            case 'E':
                Encode();
                break;
            case 'D':
                Decode();
                break;
            case 'Q':

            default:
                break;

        }

    } while (choice != 'Q');


    return 0;
}


char Encode() { //Encode
    int key;
    char choice, MSG;
    do {
        scanf("%c ", &choice);
        if (choice == 'C') { //Caesar
            scanf("%d ", &key);
            // for (int i = 0; i < 5; i++) {
            while (1) {
                scanf("%c", &MSG);
                if (MSG == '\n' || MSG == ' ') { //if 'space' or 'Enter' = stop
                    break;
                }

                if ((MSG + key) <= 'Z' && (MSG + key) >= 'A')
                    printf("%c", (MSG + key));
                else
                    printf("%c", (((MSG - 'A') + key) % 26) + 'A');
            }
            printf("\n");
            break;

        } else if (choice == 'R') { //Reversed Caesar
            scanf("%d ", &key);
            //for (int i = 0; i < 5; i++) {
            while (1) {
                scanf("%c", &MSG);
                if (MSG == '\n' || MSG == ' ') {
                    break;
                }
                if ((MSG + key) <= 'Z' && (MSG + key) >= 'A')
                    printf("%c", (MSG - key));
                else
                    printf("%c", (((MSG - 'A') - key) % 26) + 'A');
            }
            printf("\n");
            break;

        } else if (choice == 'D') { //Doubled Caesar
            scanf("%d ", &key);
            // for (int i = 0; i < 5; i++) {
            while (1) {
                scanf("%c", &MSG);
                if (MSG == '\n' || MSG == ' ') {
                    break;
                }
                if ((MSG + key) <= 'Z' && (MSG + key) >= 'A')
                    printf("%c", (MSG + (2 * key)));
                else
                    printf("%c", (((MSG - 'A') + (2 * key)) % 26) + 'A');
                // printf("%c", MSG + (2 * key));
            }


            printf("\n");
            break;

        }

    } while (choice != 'Q');


    return 0;
}

char Decode() { //Decode
    int key;
    char choice, MSG;
    do {
        scanf("%c ", &choice);
        if (choice == 'C') { //Caesar
            scanf("%d ", &key);
            for (int i = 0; i < 5; i++) {
                scanf(" %c", &MSG);

                printf("%c", MSG - key);
            }
            printf("\n");
            break;

        } else if (choice == 'R') { //Reversed Caesar
            scanf("%d", &key);
            for (int i = 0; i < 5; i++) {
                scanf(" %c", &MSG);
                printf("%c", MSG + key);
            }
            printf("\n");
            break;

        } else if (choice == 'D') { //Doubled Caesar
            scanf("%d", &key);
            for (int i = 0; i < 5; i++) {
                scanf(" %c", &MSG);
                printf("%c", MSG - (key * 2));
            }
            printf("\n");
            break;
        }

    } while (choice != 'Q');


    return 0;

}

