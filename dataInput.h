//
// Created by Oana on 06.11.2019.
//

#ifndef FOOD_ORDERING_DATAINPUT_H
#define FOOD_ORDERING_DATAINPUT_H
typedef struct _customer {
    char * username;
    char * password;

} customer;
void readCustomerData(customer *c);
int getChoiceIndex(int noOfChoices, int *state);
void addAdditionalInformation(char addInfo[]);
customer createCustomer();
#endif //FOOD_ORDERING_DATAINPUT_H
