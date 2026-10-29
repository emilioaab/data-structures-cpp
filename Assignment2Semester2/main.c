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
        printf("Please enter 'E' to Encode or 'D' to Decode ---> C/R/D ---> key integer number ---> and the message | 2 times Q to exit:\n");
        scanf("%c ", &choice);

        switch (choice) {
            case 'E':
                Encode();
                break;
            case 'D':
                Decode();
                break;
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
        scanf("%c ", &choice); //Choice of C(Caesar)/R(Reversed)/D(Doubled)

        if (choice == 'C') { //Encode - Caesar
            scanf("%d ", &key);

            while (1) {
                scanf("%c", &MSG);
                if (MSG == '\n' || MSG == ' ') {
                    break;
                }
                if ((MSG + key) <= 'Z' && (MSG + key) >= 'A')
                    printf("%c", (MSG + key));
                else
                    printf("%c", (((MSG - 'A') + key) % 26) + 'A');
            }

            printf("\n");
            break;

        } else if (choice == 'R') { //Encode - Reversed Caesar
            scanf("%d ", &key);

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

            while (1) {
                scanf("%c", &MSG);
                if (MSG == '\n' || MSG == ' ') {
                    break;
                }
                if ((MSG + key) <= 'Z' && (MSG + key) >= 'A')
                    printf("%c", (MSG + (2 * key)));
                else
                    printf("%c", (((MSG - 'A') + (2 * key)) % 26) + 'A');
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
        scanf("%c ", &choice); //Choice of C(Caesar)/R(Reversed)/D(Doubled)

        if (choice == 'C') { //Decode - Caesar
            scanf("%d ", &key);

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

        } else if (choice == 'R') { //Decode - Reversed Caesar
            scanf("%d ", &key);

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

        } else if (choice == 'D') { //Decode - Doubled Caesar
            scanf("%d ", &key);

            while (1) {
                scanf("%c", &MSG);
                if (MSG == '\n' || MSG == ' ') {
                    break;
                }
                if ((MSG + key) <= 'Z' && (MSG + key) >= 'A')
                    printf("%c", (MSG - (2 * key)));
                else
                    printf("%c", (((MSG - 'A') - (2 * key)) % 26) + 'A');
            }

            printf("\n");
            break;
        }

    } while (choice != 'Q');
    return 0;
}