#include "define.h"

typedef struct
{
    char name[20];
    int price;
} item;

typedef struct
{
    item items[MAX_ORDER_ITEMS];
    int count;
} order;

void deliShowMenu();
void deliAddItem(order* order);
void deliRemoveItem(order* order);
void deliListOrder(order* order);
void deliCheckout(order* order);