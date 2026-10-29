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

    char name [30];
    int amount;
    int price;
}product;

typedef struct {
    int id;//number of client
    product *pprod;//arrray of the products
    int numprod; // the size ot the array / amount of diffrence products
}cart;


void inputproduct(product *pproduct){
    printf("enter the product name :\n");
    scanf("%s",pproduct->name);
    printf("enter the amount of the product :\n");
    scanf("%d",&pproduct->amount);
    printf("enter the price of this product :\n");
    scanf("%d",&pproduct->price);
}

void printproduct(product prod){

    printf("\nthe product name is : %s\n",prod.name);

    printf("\nthe amount of this product :%d",prod.amount);

    printf("\nthe price of this product is :%d\n",prod.price);

}



void inputcart(cart* pcart){

    printf(" enter the client id : \n");
    scanf("%d",&pcart->id);

    printf("enter the number of the products:\n");
    scanf("%d",&pcart->numprod);

    pcart->pprod = (product *)malloc(pcart->numprod*sizeof(product));
    if(pcart->pprod==NULL){printf("ni memory was allocated");
        exit(1);
    }
    for (int i =0; i<pcart->numprod; i++) {
        printf("enter information to product number %d:\n",i+1 );
        inputproduct(&pcart->pprod[i]);
    }

}

void printcart(cart crt){

    printf("\nthe client id is :%d \n\n",crt.id);
    printf("\nthe number of the products is :%d\n\n",crt.numprod);
    printf("\ninformation about the produccts:\n");

    for (int i=0; i<crt.numprod; i++) {
        printproduct(crt.pprod[i]);
    }


}

int Initcashreg(cart** ppqueue){
    int size ;

    printf("enter the amount of the shopping baskets in the line :\n");
    scanf("%d",&size);

    *ppqueue=(cart*)malloc(sizeof(cart)*size);
    if (*ppqueue==NULL){printf("error no memory was allocated");
        exit(1);
    }
    for (int i=0; i<size; i++) {
        printf("enter informations to shopping basket number %d:\n",i+1);
        inputcart(&(*ppqueue)[i]);
    }

    return size;

}



void printall(cart* pqueue, int size){

    for (int i=0; i<size; i++) {
        printf("\n\n>>>information about shopping basket number %d:<<<\n\n",i+1);
        printf("------------------------------");
        printcart(pqueue[i]);
    }

}


void freeall(cart** ppqueue, int size){

    for (int i =0; i<size; i++) {
        free((*ppqueue)[i].pprod);
    }
    free(*ppqueue);
}




void payment(cart *pqueue, int size){

    int sum=0;
    for (int i=0; i<size; i++) {
        printf("..................................\n");
        printf("\n\nthe total payment to client number %d is:",i+1);
        for (int j=0; j<pqueue[i].numprod; j++) {
            sum=sum+(pqueue[i].pprod[j].price)*(pqueue[i].pprod[j].amount);
        }
        printf("%d\n\n",sum);
        sum=0;
    }

}



int main() {

    cart *pqueue= NULL;

    int size;
    size=Initcashreg(&pqueue);

    printall(pqueue, size);

    payment(pqueue, size);

    freeall(&pqueue, size);


    return 0;
}