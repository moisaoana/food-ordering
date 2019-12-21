//
// Created by Oana on 21.12.2019.
//

#ifndef FOOD_ORDERING_CUSTOMERDATA_H
#define FOOD_ORDERING_CUSTOMERDATA_H
#include "customerData.h"
typedef struct _customer {
    char * username;
    char * password;

} customer;
void readCustomerData(customer *c);
customer createCustomer();
#endif //FOOD_ORDERING_CUSTOMERDATA_H
