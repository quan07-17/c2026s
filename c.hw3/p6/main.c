#include <stdio.h>

#include "login.h"

int main()
{
    char acc[20];
    char pw[20];

    printf("Account? ");
    scanf(" %[^\n]", acc);
    printf("Password? ");
    scanf(" %[^\n]", pw);

    int stat = login(acc, pw);

    switch (stat)
    {
        case 1:
            printf("Account does not exist!\n");
            break;
        case 2:
            printf("Wrong password!\n");
            break;
        default:
            printf("Login successful\n");
    }

    return stat;
}