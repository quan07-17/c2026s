#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAP 2

#include "contact.h"

contactBook contactBookInit()
{
    contactBook list;
    list.size = 0;
    list.capacity = INIT_CAP;
    list.contacts = calloc(list.capacity, sizeof(contact));
    return list;
}

int main()
{
    contactBook book = contactBookInit();
    char command[5];

    while (1)
    {
        printf("command (add, del, ls, exit): ");
        scanf(" %[^\n]s", command);

        if (strcmp(command, "add") == 0)
        {
            printf("\n");
            contactBookAdd(&book);
            printf("\n");
        }
        else if (strcmp(command, "del") == 0)
        {
            printf("\n");
            contactBookRemove(&book);
            printf("\n");
        }
        else if (strcmp(command, "ls") == 0)
        {
            printf("\n");
            contactBookList(&book);
            printf("\n");
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("\n");
            printf("  Invalid command!\n");
            printf("\n");
        }
    }

    free(book.contacts);
    return 0;
}