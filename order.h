//
// Created by Oana on 06.11.2019.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H
#include "dataInput.h"
#include "displayData.h"
void displayOrderInfo(customer *c, type *t, type* d, char addInfo[], int cutleryChoice);
void orderConfirmation(customer *c, int *confirmOrder, int *state);

#endif //FOOD_ORDERING_ORDER_H
