//
// Created by Oana on 06.11.2019.
//
#include<stdio.h>
#include<string.h>
#include "order.h"
#include "dataInput.h"
#include "displayData.h"

void displayOrderInfo(customer *c, type *t, type* d, char addInfo[], int cutleryChoice)
{
    printf("This is your order:\n-------------------\n");
    printf("Name: %s \n", c->username);
    printf("Food items:\n---%s: (%.2f)\n", t->name, t->price);
    if(d->price!=0){
        printf("---%s: (%.2f)\n", d->name,d->price);
    }
    printf("Cutlery: ");
    if(cutleryChoice==0)
        printf("yes\n");
    else
        printf("no\n");
    if(strcmp(addInfo,"")!=0)
        printf("Additional info: %s\n", addInfo);
    printf("Payment amount: (%.2f)\n-------------------\n", t->price+d->price);
}

void orderConfirmation(customer *c, int *confirmOrder, int *state)
{
    char choice;
    printf("a) Confirm order\n");
    printf("b) Go back\n");
    choice = getchar();
    if(choice=='a') {
        *confirmOrder = 1;
        printf("Order confirmed! Thank you for buying from us, %s!",c->username);
    }
    else {
        (*state)-=2;
    }
    getchar();
}
