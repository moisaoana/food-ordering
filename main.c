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
void extractTypesAndPrices(char *dataLine, type *t);
void freeFoods(food* food, int noOfFoods);
void freeType(type * t);
int main() {
    int noOfFoods, noOfDrinks, noOfCutlery=2;
    int state =0, confirmOrder = 0;
    char drinksLine[MAX_LINE];
    char **line, ** copyLine;
    char cutlery[][MAX_TYPE_NAME]={"Yes!", "No, thanks!"};
    int foodChoice,typeChoice,drinkChoice, cutleryChoice;
    char addInfo[MAX_ADD_INFO];
    char firstLine[MAX_LINE];
    customer c=createCustomer();
    food *f;
    type *drink;
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
    f=(food *)malloc(noOfFoods*sizeof(food));
    copyLine=(char**)malloc(noOfFoods*sizeof(char*));
    for(int i=0;i<noOfFoods;i++)
    {
        line[i] = (char *) malloc(MAX_LINE * sizeof(char));
        copyLine[i] = (char *) malloc(MAX_LINE * sizeof(char));
        f[i]=createFood();
        fgets(line[i],MAX_LINE,filePointer);
        char *const  p = strchr(line[i], ':');
        if (p != NULL) {
            *p = '\0';
        }
        char * p2=strchr(line[i],' ');
        if(p2!=NULL)
        {
            *p2='\0';
            f[i].name=line[i];
            f[i].noOfTypes=atoi(p2+1);
        }
        strcpy(copyLine[i], p + 2);
        f[i].types=(type*)malloc(f[i].noOfTypes*sizeof(type));
       for(int j=0;j<f[i].noOfTypes;j++)
           f[i].types[j].name=(char*)malloc(MAX_TYPE_NAME*sizeof(char));
        extractTypesAndPrices(copyLine[i], f[i].types);
    }
    fgets(firstLine,MAX_LINE,filePointer);
    firstLine[strlen(firstLine)-1]='\0';
    noOfDrinks=atoi(firstLine);
    drink=(type*)malloc(noOfDrinks*sizeof(type));
    fgets(drinksLine,MAX_LINE,filePointer);
    for(int i=0;i<noOfDrinks;i++)
       drink[i].name=(char*)malloc(MAX_TYPE_NAME*sizeof(char));
    extractTypesAndPrices(drinksLine,drink);
    while(!confirmOrder){
        switch (state) {
            case 0:{
                readCustomerData(&c);
                state++;
                break;
            }
            case 1: {
                displayFoodOptions(noOfFoods, f);
                foodChoice= getChoiceIndex(noOfFoods, &state);
                break;
            }
            case 2: {
                displayTypeOptions(f[foodChoice].noOfTypes, f[foodChoice].name, f[foodChoice].types);
                typeChoice= getChoiceIndex(f[foodChoice].noOfTypes, &state);
                break;
            }
            case 3: {
                displayDrinkOptions(noOfDrinks, f[foodChoice].name, drink);
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
                displayOrderInfo(&c,&(f[foodChoice].types[typeChoice]),&(drink[drinkChoice]), addInfo, cutleryChoice);
                orderConfirmation(&c, &confirmOrder, &state);
                break;
            }
        }
    }
    for(int i=0;i<noOfFoods;i++) {
        free(line[i]);
        free(copyLine[i]);
    }
    free(line);
    free(copyLine);
    freeFoods(f, noOfFoods);
    freeType(drink);
    fclose(filePointer);
    return 0;
}
void extractTypesAndPrices(char *dataLine,type*t)
{
    char * pointer = strtok(dataLine, "(-");
    int j = 0, k=-1;
    while (pointer != NULL) {
        j++;
        if (j % 2 != 0) {
            k++;
            pointer[strlen(pointer)-1]='\0';
            t[k].name=pointer;
        } else {
            strcpy(pointer,pointer+1);
            pointer[strlen(pointer)-1]='\0';
            double price = atof(pointer);
            t[k].price =price;
        }
        pointer = strtok(NULL, "(-");
    }
}
void freeType(type * t) {
    free(t->name);
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
