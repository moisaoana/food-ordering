//
// Created by Oana on 06.11.2019.
//
#include<stdio.h>
#define MAX_FOOD_NAME 10
#define MAX_TYPE_NAME 20
#define MAX_ADD_INFO 100
void displayFoodOptions(int noOfFoods, char food[][MAX_FOOD_NAME])
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfFoods;i++)
    {
        putchar('a'+i);
        printf(") %s\n", food[i]);
    }
    printf("%c) Go back\n",'a'+noOfFoods);
}
void displayTypeOptions(int noTypes, char types[][MAX_TYPE_NAME], char food[], double prices[])
{
    printf("Please choose the type of %s:\n",food);
    for(int i=0;i<noTypes;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",types[i], prices[i]);
    }
    printf("%c) Go back\n",'a'+noTypes);
}
void displayDrinkOptions(int noOfDrinks, char food[], char drinks[][MAX_TYPE_NAME], double drinkPrices[])
{
    printf("Please choose a drink to go with your %s:\n", food);
    for(int i=0;i<noOfDrinks;i++)
    {
        putchar('a'+i);
        if(i!=noOfDrinks-1)
            printf(") %s (%.2f)\n", drinks[i],drinkPrices[i]);
        else
            printf(") %s\n", drinks[i]);
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