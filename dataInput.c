//
// Created by Oana on 06.11.2019.
//
#include<stdio.h>
void readCustomerData(char username[], char password[])
{
    printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    gets(password);
}


int getChoiceIndex(int noOfChoices, int *state) {
    int choiceIndex;
    char choice = getchar();
    getchar();
    choiceIndex= choice-'a';
    if (choice == 'a' + noOfChoices)
        (*state)--;
    else {
        choiceIndex= choice-'a';
        (*state)++;
    }
    return choiceIndex;

}
void addAdditionalInformation(char addInfo[])
{
    printf("Any additional info?\n");
    gets(addInfo);
}
