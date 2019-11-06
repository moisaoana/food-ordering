//
// Created by Oana on 06.11.2019.
//

#ifndef FOOD_ORDERING_DISPLAYDATA_H
#define FOOD_ORDERING_DISPLAYDATA_H
#define MAX_FOOD_NAME 10
#define MAX_TYPE_NAME 20
#define MAX_ADD_INFO 100

void displayFoodOptions(int noOfFoods, char food[][MAX_FOOD_NAME]);
void displayTypeOptions(int noTypes, char types[][MAX_TYPE_NAME], char food[], double prices[]);
void displayDrinkOptions(int noOfDrinks, char food[], char drinks[][MAX_TYPE_NAME], double drinkPrices[]);
void displayCutleryOptions(int noOfCutlery, char cutlery[][MAX_TYPE_NAME]);

#endif //FOOD_ORDERING_DISPLAYDATA_H
