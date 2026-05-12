#include <stdio.h>
#include <string.h>

#include "deli.h"

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }
    return c;
}

void __strToLower(char* str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toLower(str[i]);
    }
}

const char* __foodToString(food f)
{
    switch (f)
    {
        case Sandwich:
            return "Sandwich";
        case Pizza:
            return "Pizza";
        case Burger:
            return "Burger";
        case Chipotle:
            return "Chipotle";
        case Steak:
            return "Steak";
        case Cola:
            return "Cola";
        case Tea:
            return "Tea";
        case Milk:
            return "Milk";
        case Water:
            return "Water";
        default:
            return "Unknown";
    }
}

food __strToFood(const char* str)
{
    char lowerStr[21] = {0};
    strncpy(lowerStr, str, 20);
    __strToLower(lowerStr);

    if (strcmp(lowerStr, "sandwich") == 0)
        return Sandwich;
    if (strcmp(lowerStr, "pizza") == 0)
        return Pizza;
    if (strcmp(lowerStr, "burger") == 0)
        return Burger;
    if (strcmp(lowerStr, "chipotle") == 0)
        return Chipotle;
    if (strcmp(lowerStr, "steak") == 0)
        return Steak;
    if (strcmp(lowerStr, "cola") == 0)
        return Cola;
    if (strcmp(lowerStr, "tea") == 0)
        return Tea;
    if (strcmp(lowerStr, "milk") == 0)
        return Milk;
    if (strcmp(lowerStr, "water") == 0)
        return Water;

    return Unknown;
}

void deliShowMenu()
{
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

void deliAddItem(order* order)
{
    if (order->count + 1 > MAX_ORDER_ITEMS)
    {
        printf("You cannot add more than %d items to your order!\n", MAX_ORDER_ITEMS);
        return;
    }

    printf("Enter the name of the food to add\n");
    char input[21] = {0};
    printf("-- Name: ");
    scanf(" %20s", input);

    food f = __strToFood(input);
    if (f == Unknown)
    {
        printf("%s is not on the menu!\n", input);
        return;
    }

    item i;
    strncpy(i.name, __foodToString(f), 20);
    i.price = f;
    order->items[order->count] = i;
    order->count++;

    printf("Okay, one %s coming right up!\n", i.name);
}

void deliRemoveItem(order* order)
{
    if (order->count < 1)
    {
        printf("You have no items to remove from your order!\n");
        return;
    }

    printf("Enter the item number to remove from your order\n");
    int index = -1;
    printf("-- Number: ");
    scanf(" %d", &index);
    if (index < 1 || index > order->count)
    {
        printf("That number is out of range! Please enter a number between 1 and %d.\n", order->count);
        return;
    }
    
    for (int i = index - 1; i < order->count - 1; i++)
    {
        order->items[i] = order->items[i + 1];
    }
    order->count--;
    printf("Okay, and ... done!\n");
}

void deliListOrder(order* order)
{
    if (order->count <= 0)
    {
        printf("Your order is empty, try order some!\n");
        return;
    }

    printf("Here are the items in your order:\n");
    int total = 0;
    for (int i = 0; i < order->count; i++)
    {
        printf("> #%d %s - $%d\n", i + 1, order->items[i].name, order->items[i].price);
        total += order->items[i].price;
    }
    printf("Total: $%d\n", total);
}

void deliCheckout(order* order)
{
    if (order->count < 1)
    {
        return;
    }

    int total = 0;
    for (int i = 0; i < order->count; i++)
    {
        total += order->items[i].price;
    }

    printf("That will be $%d in total.\n", total);
    int payment = 0;
    do
    {
        printf("-- Payment: ");
        scanf(" %d", &payment);

        if (payment < 0)
        {
            printf("\nYou cannot enter a negative payment!\n");
            continue;
        }        

        total -= payment;
        if (total > 0)
        {
            printf("\nThat is not enough!\n");
            printf("You still need to pay $%d.\n", total);
            continue;
        }
        else if (total < 0)
        {
            printf("\nHere is your order.\n");
            printf("And the change: $%d\n", -total);
            break;
        }
        else
        {
            printf("\nHere is your order.\n");
            break;
        }
        printf("\n");
    } while (total > 0);
}