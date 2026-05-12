#include <stdio.h>
#include <ctype.h>

#include "deli.h"

void deliShowChoices()
{
    printf("> (m) Show menu\n");
    printf("> (a) Add item to order\n");
    printf("> (r) Remove item from order\n");
    printf("> (l) List items in order\n");
    printf("> (q) Checkout and quit\n");
}

int main() {
    order myOrder = {0};
    char choice = 0;

    printf("Welcome to Dell's Deli!\n");
    printf("How can we help you today?\n");

    do
    {
        printf("\n");
        deliShowChoices();
        printf("-- Choice: ");
        
        scanf(" %c", &choice);
        switch (tolower(choice))
        {
            case 'm':
                printf("\n");
                deliShowMenu();
                break;
            case 'a':
                printf("\n");
                deliAddItem(&myOrder);
                break;
            case 'r':
                printf("\n");
                deliRemoveItem(&myOrder);
                break;
            case 'l':
                printf("\n");
                deliListOrder(&myOrder);
                break;
            case 'q':
                printf("\n");
                deliCheckout(&myOrder);
                printf("Thank you for visiting Dell's Deli!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 'q' && choice != 'Q');

    return 0;
}