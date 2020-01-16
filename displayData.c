//
// Created by Oana on 06.11.2019.
//
#include<stdio.h>
#include "type.h"

#define MAX_TYPE_NAME 70
#define MAX_ADD_INFO 60
#define MAX_DRINK_NAME 50
void displayDrinkOptions(int noOfDrinks,char * food, type *d)
{
    printf("Please choose a drink to go with your %s:\n", food);
    for(int i=0;i<noOfDrinks;i++)
    {
        putchar('a'+i);
        printf(") %s (%.2f)\n", d[i].name,d[i].price);
    }
    printf("%c) Go back\n",'a'+noOfDrinks);
}

void displayCutleryOptions(int noOfCutlery, char cutlery[][MAX_TYPE_NAME])
{
    printf("Do you want cutlery?\n");
    for(int i=0;i<noOfCutlery;i++)
    {
        putchar('a'+i);
        printf(") %s\n", cutlery[i]);
    }
    printf("%c) Go back\n",'a'+noOfCutlery);
}
