#include <stdio.h>
#include <string.h>
#include "displayData.h"
#include "order.h"
#include "dataInput.h"
#define MAX_FOOD_NAME 10
#define MAX_TYPE_NAME 20
#define MAX_ADD_INFO 100

int main() {
    int noOfFoods=3, noOfDrinks=5, noOfCutlery=2, noTypes[]={3,2,4};
    int state =0;
    int confirmOrder = 0;
    char username[MAX_TYPE_NAME], password[MAX_TYPE_NAME];
    char food[][MAX_FOOD_NAME]={"Pizza", "Pasta", "Salad"};
    char types[3][4][MAX_TYPE_NAME]={
            {"Pizza Carbonara","Pizza Diavola", "Pizza Margherita"},
            {"Chicken Alfredo", "Mac&cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}};
    double prices[3][4]={{21,23,19}, {23,21}, {23,22,19,21}};
    double drinkPrices[5]={5,5,5,4,0};
    char drinks[][MAX_TYPE_NAME]={"Coca-cola", "Fanta", "Lipton","Water","No, thanks!"};
    char cutlery[][MAX_TYPE_NAME]={"Yes!", "No, thanks!"};
    int foodChoice,typeChoice,drinkChoice, cutleryChoice;
    char addInfo[MAX_ADD_INFO];

    while(!confirmOrder){
        switch (state) {
            case 0:{
                readCustomerData(username,password);
                state++;
                break;
            }
            case 1: {
                displayFoodOptions(noOfFoods, food);
                foodChoice= getChoiceIndex(noOfFoods, &state);
                break;
            }
            case 2: {
                displayTypeOptions(noTypes[foodChoice],types[foodChoice], food[foodChoice], prices[foodChoice]);
                typeChoice= getChoiceIndex(noTypes[foodChoice], &state);
                break;
            }
            case 3: {
                displayDrinkOptions(noOfDrinks, food[foodChoice], drinks,drinkPrices);
                drinkChoice= getChoiceIndex(noOfDrinks, &state);
                break;
            }
            case 4:{
                displayCutleryOptions(noOfCutlery, cutlery);
                cutleryChoice= getChoiceIndex(noOfCutlery, &state);
                break;
            }
            case 5:
            {
                addAdditionalInformation(addInfo);
                state++;
                break;
            }
            case 6:
            {
                displayOrderInfo(username, types[foodChoice][typeChoice],prices[foodChoice][typeChoice], drinks[drinkChoice], drinkPrices[drinkChoice], addInfo, cutleryChoice);
                orderConfirmation(username, &confirmOrder, &state);
                break;
            }
        }
    }
    return 0;
}
