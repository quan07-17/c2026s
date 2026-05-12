#include "deli.h"
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

void deliShowMenu(){
    printf("Here is our menu:\n");
    printf("> Sandwich - $8\n");
    printf("> Pizza - $12\n");
    printf("> Burger - $10\n");
    printf("> Chipotle - $11\n");
    printf("> Steak - $18\n");
    printf("> Cola - $3\n");
    printf("> Tea - $2\n");
    printf("> Milk - $4\n");
    printf("> Water - $1\n");
}
void deliAddItem(order *myOrder){
    if (myOrder->itemCount >= MAX_ORDER_ITEMS) {
        printf("You cannot add more than %d items to your order!\n", MAX_ORDER_ITEMS);
    } else {
        int index = myOrder->itemCount;
        printf("Enter the name of the food to add\n");
        scanf("%s", myOrder->items[index].name);
        if (strcasecmp((myOrder->items[index].name), ("Sandwich")) == 0) {
            strcpy(myOrder->items[index].name, "Sandwich");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 8;
            myOrder->itemCount++;
        }
        else if(strcasecmp((myOrder->items[index].name), ("Pizza")) == 0){
            strcpy(myOrder->items[index].name, "Pizza");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 12;
            myOrder->itemCount++;
        }
        else if(strcasecmp((myOrder->items[index].name), ("Burger")) == 0){
            strcpy(myOrder->items[index].name, "Burger");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 10;
            myOrder->itemCount++;
        }
        else if(strcasecmp((myOrder->items[index].name), ("Chipotle")) == 0){
            strcpy(myOrder->items[index].name, "Chipotle");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 11;
            myOrder->itemCount++;
        }
        else if(strcasecmp((myOrder->items[index].name), ("Steak")) == 0){
            strcpy(myOrder->items[index].name, "Steak");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 18;
            myOrder->itemCount++;
        }
        else if(strcasecmp((myOrder->items[index].name), ("Cola")) == 0){
            strcpy(myOrder->items[index].name, "Cola");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 3;
            myOrder->itemCount++;
        }
        else if(strcasecmp((myOrder->items[index].name), ("Tea")) == 0){
            strcpy(myOrder->items[index].name, "Tea");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 2;
            myOrder->itemCount++;
        }
        else if(strcasecmp((myOrder->items[index].name), ("Milk")) == 0){
            strcpy(myOrder->items[index].name, "Milk");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 4;
            myOrder->itemCount++;
        }
        else if(strcasecmp((myOrder->items[index].name), ("Water")) == 0){
            strcpy(myOrder->items[index].name, "Water");
            printf("Okay, one %s coming right up!\n", myOrder->items[index].name);
            myOrder->items[index].price = 1;
            myOrder->itemCount++;
        } else {
            printf("%s is not on the menu!\n", myOrder->items[index].name);
        }
    }
}
void deliRemoveItem(order *myOrder){
    if (myOrder->itemCount == 0) {
        printf("You have no items to remove from your order!\n");
    } else {
        int remove = 0;
        printf("Enter the item number to remove from your order:\n");
        printf("-- Number: ");
        scanf("%d", &remove);
        if (remove < 1 || remove > myOrder->itemCount) {
            printf("That number is out of range! Please enter a number between 1 and %d.\n", myOrder->itemCount);
        } else {
            for (int i = remove - 1; i < myOrder->itemCount - 1; i++) {
                myOrder->items[i] = myOrder->items[i + 1];
            }
            myOrder->itemCount--;
            printf("Okay, and … done!\n");
        }
    }
}
void deliListOrder(order *myOrder){
    if (myOrder->itemCount == 0) {
        printf("Your order is empty, try order some!\n");
    } else {
        int total = 0;
        printf("Here are the items in your order:\n");
        for (int i = 0; i < myOrder->itemCount; i++) {
            total += myOrder->items[i].price; 
            printf("> #%d %s - $%d\n", i + 1, myOrder->items[i].name, myOrder->items[i].price);
        }
        printf("Total: $%d\n", total);
    }
}
void deliCheckout(order *myOrder){
    if (myOrder->itemCount != 0) {
        int total = 0;
        int payment = 0;
        for (int i = 0; i < myOrder->itemCount; i++) {
            total += myOrder->items[i].price;
        }
        printf("That will be $%d in total.\n", total);
        while (total > 0) {
            printf("-- Payment: ");
            scanf("%d", &payment);
            printf("\n");
        
            if (payment < 0) { 
                printf("You cannot enter a negative payment!\n");
            } else if (payment < total) {
                total -= payment;
                printf("That is not enough!\n");
                printf("You still need to pay $%d.\n", total);
            } else if (payment > total) {
                printf("Here is your order.\n");
                printf("And the change: $%d\n", payment - total);
                break;
            } else {
                printf("Here is your order.\n");
                break;
            }
        }
    }
}