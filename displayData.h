//
// Created by Oana on 06.11.2019.
//

#ifndef FOOD_ORDERING_DISPLAYDATA_H
#define FOOD_ORDERING_DISPLAYDATA_H
#define MAX_FOOD_NAME 80
#define MAX_TYPE_NAME 70
#define MAX_ADD_INFO 60

void displayFoodOptions(int noOfFoods, char **foods);
void displayTypeOptions(int noTypes, char **types, char *food, double *prices);
void displayDrinkOptions(int noOfDrinks, char *food, char **drinks, double *drinkPrices);
void displayCutleryOptions(int noOfCutlery, char cutlery[][MAX_TYPE_NAME]);

#endif //FOOD_ORDERING_DISPLAYDATA_H
