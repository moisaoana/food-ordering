//
// Created by Oana on 21.12.2019.
//

#ifndef FOOD_ORDERING_TYPE_H
#define FOOD_ORDERING_TYPE_H
typedef struct _type {
    char * name;
    double price;
} type;
void displayTypeOptions(int noTypes, char *food, type * t);
void freeType(type * t);
void extractTypesAndPrices(char *dataLine,type*t);
#endif //FOOD_ORDERING_TYPE_H
