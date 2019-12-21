//
// Created by Oana on 21.12.2019.
//

#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H
#include "type.h"
typedef struct _food {
    char * name;
    int noOfTypes;
    type * types;
} food;
void displayFoodOptions(int noOfFoods, food * f);
food createFood();
void freeFoods(food* food, int noOfFoods);
#endif //FOOD_ORDERING_FOOD_H
