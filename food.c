//
// Created by Oana on 21.12.2019.
//
#include<stdlib.h>
#include<stdio.h>
#include "food.h"
#define MAX_FOOD_NAME 80
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
void freeFoods(food* food, int noOfFoods) {
    for (int i = 0; i < noOfFoods; i++) {
        for (int j = 0; j < food[i].noOfTypes; j++) {
            freeType(&(food[i].types[j]));
        }
        free(food[i].types);
        free(food[i].name);
    }
    free(food);
}
