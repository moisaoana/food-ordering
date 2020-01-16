//
// Created by Oana on 21.12.2019.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "type.h"
void displayTypeOptions(int noTypes,char *food ,type *t )
{
    printf("Please choose the type of %s:\n",food);
    for(int i=0;i<noTypes;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",t[i].name, t[i].price);
    }
    printf("%c) Go back\n",'a'+noTypes);
}
void freeType(type * t) {
    free(t->name);
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