#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "displayData.h"
#include "order.h"
#include "dataInput.h"
#define MAX_FOOD_NAME 80
#define MAX_TYPE_NAME 70
#define MAX_ADD_INFO 100
#define MAX_LINE 100
#define LOAD_DATA "Please load the data"
//
int main() {
    int noOfFoods;
    int noOfDrinks, noOfCutlery=2;
    int * noOfFoodTypes;
    int state =0;
    int j,k;
    int confirmOrder = 0;
    char username[MAX_TYPE_NAME], password[MAX_TYPE_NAME];
    char ** foods, **line;
    char * copyLine;
    char drinksLine[MAX_LINE];
    char ***foodTypes;
    double ** foodPrices;
    double * drinksPrices;
    char ** drink;
    int number=0;
    char cutlery[][MAX_TYPE_NAME]={"Yes!", "No, thanks!"};
    int foodChoice,typeChoice,drinkChoice, cutleryChoice;
    char addInfo[MAX_ADD_INFO];
    char * pointer;
    printf("%s\n", LOAD_DATA);
    scanf("%d", &noOfFoods);
    getchar();
    //printf("%d\n", noOfFoods);
    line=(char**)malloc(noOfFoods*sizeof(char*));
    foods=(char**)malloc(noOfFoods*sizeof(char*));
    copyLine=(char*)malloc(noOfFoods*sizeof(char));
    noOfFoodTypes=(int*)malloc(noOfFoods*sizeof(int));
    foodTypes=(char***)malloc(noOfFoods*sizeof(char**));
    foodPrices = (double**)malloc(noOfFoods* sizeof(double*));
    for(int i=0;i<noOfFoods;i++)
    {
        line[i] = (char *) malloc(MAX_LINE * sizeof(char));
        foods[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        gets(line[i]);
        //printf("%s\n",line[i]);

        char *const  p = strchr(line[i], ':');
        if (p != NULL) {
            *p = '\0';
            foods[i] = line[i];
            //printf("%s\n",foods[i]);
            // printf("%s\n", p+2);
        }
        strcpy(copyLine, p + 2);
        //printf("%s\n",copyLine);
        pointer = strtok(p + 2, "(-");
        number=0;
        while (pointer!= NULL) {
           // printf ("%s\n",pointer);
            number++;
            pointer = strtok(NULL, "(-");

        }
        number=number/2;
        //printf("%d\n", number);
        noOfFoodTypes[i]=number;
        // printf("%d\n", noOfFoodTypes[i]);
        foodTypes[i] = (char **) malloc(noOfFoodTypes[i] * sizeof(char *));
        foodPrices[i] = (double *) malloc(noOfFoodTypes[i] * sizeof(double));
        pointer = strtok(copyLine, "(-");
        j = 0;
        k=-1;
        while (pointer != NULL) {
           // printf ("%s\n",pointer);
            j++;
            if (j % 2 != 0) {
                k++;
                foodTypes[i][k] = (char *) malloc(MAX_TYPE_NAME * sizeof(char));
                foodTypes[i][k] = pointer;
                //printf("%s\n", foodTypes[i][k]);
            } else {
                strcpy(pointer,pointer+1);
                pointer[strlen(pointer)-1]='\0';
                double price = atof(pointer);
                foodPrices[i][k] = price;
                //printf("%.2lf\n", foodPrices[i][k]);

            }
            pointer = strtok(NULL, "(-");

        }

    }


    scanf("%d", &noOfDrinks);
    getchar();
    gets(drinksLine);
    drinksPrices = (double *) malloc(noOfDrinks * sizeof(double));
    drink = (char **) malloc(noOfDrinks * sizeof(char *));
    pointer = strtok(drinksLine, "(-");
    j = 0;
    k=-1;
    while (pointer != NULL) {
        // printf ("%s\n",pointer);
        j++;
        if (j % 2 != 0) {
            k++;
            drink[k] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
            drink[k] = pointer;
            //printf("%s\n", drink[k]);
        } else {
            strcpy(pointer,pointer+1);
            pointer[strlen(pointer)-1]='\0';
            double price = atof(pointer);
            drinksPrices[k] = price;
            //printf("%.2lf\n", drinksPrices[k]);

        }
        pointer = strtok(NULL, "(-");
    }

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

    return 0;
}


