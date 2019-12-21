//
// Created by Oana on 06.11.2019.
//
#include<stdio.h>
#include<stdlib.h>
#include "displayData.h"
#define MAX_FOOD_NAME 80
#define MAX_TYPE_NAME 70
#define MAX_ADD_INFO 60
#define MAX_DRINK_NAME 50
food createFood() {
    food f;
    f.name = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
    f.types = NULL;
    return f;
}

void displayFoodOptions(int noOfFoods, food * food)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfFoods;i++)
    {
        putchar('a'+i);
        printf(") %s\n", food[i].name);
    }
    printf("%c) Go back\n",'a'+noOfFoods);
}

void displayTypeOptions(int noTypes,char *food ,type *t )
{
    printf("Please choose the type of %s:\n",food);
    for(int i=0;i<noTypes;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",t[i].name, t[i].price);
    }
    printf("%c) Go back\n",'a'+noTypes);
}

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
