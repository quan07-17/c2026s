#include <stdio.h>

#include "cardValid.h"

int main()
{
    char number[33];
    int valid = 0;
    int res = 0;

    printf("Enter credit card number: ");
    scanf(" %16s", number);

    res = cardValid(number, &valid);

    if (valid == 0)
    {
        printf("Invalid card number!\n");
        return 1;
    }

    switch (res)
    {
        case 1:
            printf("It's Visa!\n");
            break;
        case 2:
            printf("It's MasterCard\n");
            break;
        case 3:
            printf("It's JCB\n");
            break;
        default:
            printf("Unknown bank id!\n");
    }

    return 0;
}