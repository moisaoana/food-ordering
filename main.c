#include <stdio.h>
#include <string.h>

int main() {
    int noOffoods=3;
    int noOfdrinks=5;
    int noOfcutlery=2;
    int state =0;
    int confirmOrder = 0;
    char username[20];
    int notypes[]={3,2,4};
    char password[20];
    char food[][10]={"Pizza", "Pasta", "Salad"};
    char choice;
    char types[3][4][20]={{"Pizza Carbonara","Pizza Diavola", "Pizza Margherita"},{"Chicken Alfredo", "Mac&cheese"},{"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}};
    double prices[3][4]={{21,23,19}, {23,21}, {23,22,19,21}};
    double drinkprices[5]={5,5,5,4,0};
    char drinks[][20]={"Coca-cola", "Fanta", "Lipton","Water","No, thanks!"};
    char cutlery[][20]={"Yes!", "No, thanks!"};
    int foodchoice,typechoice,drinkchoice, cutlerychoice;
    char addInfo[100];

    while(!confirmOrder){
        switch (state) {
            case 0:{
                printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");
                printf("---Username\n");
                gets(username);
                printf("---Password\n");
                gets(password);
                state++;
                break;
            }
            case 1: {
                printf("Please choose the food you feel like eating today:\n");
                for(int i=0;i<noOffoods;i++)
                {
                    putchar('a'+i);
                    printf(") %s\n", food[i]);
                }
                printf("%c) Go back\n",'a'+noOffoods);
                choice=getchar();
                getchar();
                if(choice == 'a'+noOffoods) {
                    state--;
                    break;
                }
                foodchoice=choice-'a';
                state++;
                break;
            }
            case 2: {
                printf("Please choose the type of %s:\n",food[foodchoice]);
                for(int i=0;i<notypes[foodchoice];i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n",types[foodchoice][i], prices[foodchoice][i]);
                }
                printf("%c) Go back\n",'a'+notypes[foodchoice]);

                choice=getchar();
                getchar();
                if(choice == 'a'+notypes[foodchoice]) {
                    state--;
                    break;
                }
                typechoice=choice-'a';
                state++;
                break;
            }
            case 3: {
                printf("Please choose a drink to go with your %s:\n", food[foodchoice]);
                for(int i=0;i<noOfdrinks;i++)
                {
                    putchar('a'+i);
                    printf(") %s\n", drinks[i]);
                }
                printf("%c) Go back\n",'a'+noOfdrinks);

                choice=getchar();
                getchar();
                if(choice == 'a'+noOfdrinks) {
                    state--;
                    break;
                }
                drinkchoice=choice-'a';
                state++;
                break;


            }
            case 4:{
                printf("Do you want cutlery?\n");
                for(int i=0;i<noOfcutlery;i++)
                {
                    putchar('a'+i);
                    printf(") %s\n", cutlery[i]);
                }
                printf("%c) Go back\n",'a'+noOfcutlery);

                choice=getchar();
                getchar();
                if(choice == 'a'+noOfcutlery) {
                    state--;
                    break;
                }
                cutlerychoice=choice-'a';
                state++;
                break;
            }
            case 5:
            {
                printf("Any additional info?\n");
                gets(addInfo);
                state++;
                break;
            }
            case 6:
            {
                printf("This is your order:\n");
                printf("-------------------\n");
                printf("Name: %s \n", username);
                printf("Food items:\n");
                printf("---%s: (%.2f)\n", types[foodchoice][typechoice], prices[foodchoice][typechoice]);
                if(drinkchoice!=4)
                {
                    printf("---%s: (%.2f)\n", drinks[drinkchoice],drinkprices[drinkchoice] );
                }
                printf("Cutlery: ");
                if(cutlerychoice==0)
                    printf("yes\n");
                else
                    printf("no\n");
                if(strcmp(addInfo,"")!=0)
                    printf("Additional info: %s\n", addInfo);

                printf("Payment amount: (%.2f)\n", prices[foodchoice][typechoice]+drinkprices[drinkchoice]);
                printf("-------------------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    confirmOrder = 1;
                    printf("Order confirmed! Thank you for buying from us, %s!",username);
                } else {
                    state=state-2;
                }
                getchar();
                break;

            }
        }
    }
    return 0;
}
