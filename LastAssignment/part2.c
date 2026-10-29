/*
Asisignment : 5
Author : Emil Abdumalikov
id: 
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char name[30];
    int amount, price;
} Product;

typedef struct {
    int id;
    Product *pProd;
    int numprod;
} Cart;


void InputProduct(Product *pProduct) {

    printf("Please enter the name of the product:\n");
    scanf("%s", pProduct->name);

    printf("Please enter the quantity of the product/s:\n");
    scanf("%d", &pProduct->amount);

    printf("Please enter the price of the product:\n");
    scanf("%d", &pProduct->price);
}

void PrintProduct(Product prod) {

    printf("\nProducts name: %s\n", prod.name);

    printf("\nProducts quantity: %d\n", prod.amount);

    printf("\nProducts price:%d\n", prod.price);

}

void InputCart(Cart *pCart) {

    printf("Please enter your id: \n");
    scanf("%d", &pCart->id);

    printf("Please enter the number of the products: \n");
    scanf("%d", &pCart->numprod);

    pCart->pProd = (Product *) malloc(pCart->numprod * sizeof(Product));
    if (pCart->pProd == NULL) {
        printf("No memory was allocated");
        exit(1);
    }
    for (int i = 0; i < pCart->numprod; i++) {
        printf("Please enter info of your products %d:\n", i + 1);
        InputProduct(&pCart->pProd[i]);
    }
}

void PrintCart(Cart crt) {

    printf("\nClients id is :%d \n\n", crt.id);
    printf("\nQuantity of the product/s is/are :%d\n\n", crt.numprod);
    printf("\nInfo about the products: \n");

    for (int i = 1; i <= crt.numprod; i++) {
        PrintProduct(crt.pProd[i]);
    }
}

int InitCashReg(Cart **ppQueue) {
    int size;
    printf("Please enter the amount of baskets:\n");
    scanf("%d", &size);

    *ppQueue = (Cart *) malloc(sizeof(Cart) * size);
    if (*ppQueue == NULL) {
        printf("error no memory was allocated");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        printf("Please enter info to shopping basket number %d:\n", i + 1);
        InputCart(&(*ppQueue)[i]);
    }
    return size;

}

void FreeAll(Cart **ppQueue, int size) {

    for (int i = 1; i <= size; i++) {
        free((*ppQueue)[i].pProd);
    }
    free(*ppQueue);
}

void PrintAll(Cart *pQueue, int size) {

    for (int i = 1; i <= size; i++) {
        printf("\n\nHere is your info about shopping basket number %d:\n\n", i + 1);
        PrintCart(pQueue[i]);
    }

}

void Payment(Cart *pQueue, int size) {

    int sum = 0;
    for (int i = 0; i < size; i++) {
        printf("\n\nTotal price for client number %d is:", i + 1);
        for (int j = 0; j < pQueue[i].numprod; j++) {
            sum = sum + (pQueue[i].pProd[j].price) * (pQueue[i].pProd[j].amount);
        }
        printf("%d\n\n", sum);
        sum = 0;
    }

}


int main() {

    Cart *pQueue = NULL;
    int size;
    size = InitCashReg(&pQueue);
    PrintAll(pQueue, size);
    Payment(pQueue, size);
    FreeAll(&pQueue, size);
    return 0;
}