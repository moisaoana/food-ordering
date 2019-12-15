#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "displayData.h"
#include "order.h"
#include "dataInput.h"
#define MAX_FOOD_NAME 80
#define MAX_TYPE_NAME 70
#define MAX_ADD_INFO 60
#define MAX_LINE 100
#define LOAD_DATA "Please load the data"
void extractTypesAndPrices(char *dataLine, double *prices, char **type);

int main() {

    int noOfFoods, noOfDrinks, noOfCutlery=2;
    int * noOfFoodTypes;
    int state =0, confirmOrder = 0;
    char username[MAX_TYPE_NAME], password[MAX_TYPE_NAME], drinksLine[MAX_LINE];
    char ** foods, **line, ** copyLine, ***foodTypes, ** drink;
    double ** foodPrices, * drinksPrices;
    char cutlery[][MAX_TYPE_NAME]={"Yes!", "No, thanks!"};
    int foodChoice,typeChoice,drinkChoice, cutleryChoice;
    char addInfo[MAX_ADD_INFO];
    char firstLine[MAX_LINE];
    FILE *filePointer;
    filePointer=fopen("D:\\CP\\food-ordering\\data.txt", "r");
    if(filePointer==NULL)
    {
        printf("%s\n", LOAD_DATA);
        filePointer=stdin;
    }
    fgets(firstLine,MAX_LINE,filePointer);
    firstLine[strlen(firstLine)-1]='\0';
    noOfFoods=atoi(firstLine);
    line=(char**)malloc(noOfFoods*sizeof(char*));
    foods=(char**)malloc(noOfFoods*sizeof(char*));
    copyLine=(char**)malloc(noOfFoods*sizeof(char*));
    noOfFoodTypes=(int*)malloc(noOfFoods*sizeof(int));
    foodTypes=(char***)malloc(noOfFoods*sizeof(char**));
    foodPrices = (double**)malloc(noOfFoods* sizeof(double*));
    for(int i=0;i<noOfFoods;i++)
    {
        line[i] = (char *) malloc(MAX_LINE * sizeof(char));
        copyLine[i] = (char *) malloc(MAX_LINE * sizeof(char));
        foods[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        fgets(line[i],MAX_LINE,filePointer);
        char *const  p = strchr(line[i], ':');
        if (p != NULL) {
            *p = '\0';
        }
        char * p2=strchr(line[i],' ');
        if(p2!=NULL)
        {
            *p2='\0';
            foods[i]=line[i];
            noOfFoodTypes[i]=atoi(p2+1);
        }
        strcpy(copyLine[i], p + 2);
        foodTypes[i] = (char **) malloc(noOfFoodTypes[i] * sizeof(char *));
        foodPrices[i] = (double *) malloc(noOfFoodTypes[i] * sizeof(double));
        extractTypesAndPrices(copyLine[i], foodPrices[i], foodTypes[i]);
    }
    fgets(firstLine,MAX_LINE,filePointer);
    firstLine[strlen(firstLine)-1]='\0';
    noOfDrinks=atoi(firstLine);
    fgets(drinksLine,MAX_LINE,filePointer);
    drinksPrices = (double *) malloc(noOfDrinks * sizeof(double));
    drink = (char **) malloc(noOfDrinks * sizeof(char *));
    extractTypesAndPrices(drinksLine,drinksPrices, drink);
    while(!confirmOrder){
        switch (state) {
            case 0:{
                readCustomerData(username,password);
                state++;
                break;
            }
            case 1: {
                displayFoodOptions(noOfFoods, foods);
                foodChoice= getChoiceIndex(noOfFoods, &state);
                break;
            }
            case 2: {
                displayTypeOptions(noOfFoodTypes[foodChoice],foodTypes[foodChoice], foods[foodChoice],foodPrices[foodChoice]);
                typeChoice= getChoiceIndex(noOfFoodTypes[foodChoice], &state);
                break;
            }
            case 3: {
                displayDrinkOptions(noOfDrinks, foods[foodChoice], drink,drinksPrices);
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
                displayOrderInfo(username, foodTypes[foodChoice][typeChoice],foodPrices[foodChoice][typeChoice], drink[drinkChoice], drinksPrices[drinkChoice], addInfo, cutleryChoice);
                orderConfirmation(username, &confirmOrder, &state);
                break;
            }

        }
    }
    for(int i=0;i<noOfFoods;i++) {
        for(int j=0;j<noOfFoodTypes[i];j++) {
            free(foodTypes[i][j]);
        }
        free(foodTypes[i]);
        free(foodPrices[i]);
        free(foods[i]);
        free(line[i]);
        free(copyLine[i]);
    }
    free(foodTypes);
    free(foodPrices);
    free(foods);
    free(line);
    free(copyLine);
    free(noOfFoodTypes);
    for(int i=0; i<noOfDrinks;i++)
    {
        free(drink[i]);
    }
    free(drink);
    free(drinksPrices);
    fclose(filePointer);
    return 0;
}
void extractTypesAndPrices(char *dataLine, double *prices, char **type)
{
    char * pointer = strtok(dataLine, "(-");
    int j = 0, k=-1;
    while (pointer != NULL) {
        j++;
        if (j % 2 != 0) {
            k++;
            type[k] = (char *) malloc(MAX_TYPE_NAME * sizeof(char));
            pointer[strlen(pointer)-1]='\0';
            type[k]=pointer;
        } else {
            strcpy(pointer,pointer+1);
            pointer[strlen(pointer)-1]='\0';
            double price = atof(pointer);
            prices[k] =price;
        }
        pointer = strtok(NULL, "(-");
    }
}
