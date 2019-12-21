//
// Created by Oana on 21.12.2019.
//
#include<stdio.h>
#include<stdlib.h>
#include "customerData.h"
#define MAX_USERNAME 30
#define MAX_PASSWORD 20
customer createCustomer()
{
    customer c;
    c.username=(char *)malloc(MAX_USERNAME*sizeof(char));
    c.password=(char *)malloc(MAX_PASSWORD*sizeof(char));
    return c;
}
void readCustomerData(customer *c)
{
    printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");
    printf("---Username\n");
    gets(c->username);
    printf("---Password\n");
    gets(c->password);
}

