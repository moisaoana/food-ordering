//
// Created by Oana on 06.11.2019.
//
#include<stdio.h>
#include<string.h>

void displayOrderInfo(char username[], char types[], double priceFood, char drinks[], double priceDrink, char addInfo[], int cutleryChoice)
{
    printf("Food items:\n---%s: (%.2f)\n", types, priceFood);
    if(priceDrink!=0){
        printf("---%s: (%.2f)\n", drinks,priceDrink);
    }
    printf("Cutlery: ");
    if(cutleryChoice==0)
        printf("yes\n");
    else
        printf("no\n");
    if(strcmp(addInfo,"")!=0)
        printf("Additional info: %s\n", addInfo);
    printf("Payment amount: (%.2f)\n-------------------\n", priceFood+priceDrink);
}
void orderConfirmation(char username[], int *confirmOrder, int *state)
{
    char choice;
    printf("a) Confirm order\n");
    printf("b) Go back\n");
    choice = getchar();
    if(choice=='a') {
        *confirmOrder = 1;
        printf("Order confirmed! Thank you for buying from us, %s!",username);
    }
    else {
        (*state)-=2;
    }
    getchar();
}
