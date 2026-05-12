#include "define.h"

typedef struct {
    char name[20];
    int price;
} Item;

typedef struct {
    Item items [MAX_ORDER_ITEMS];
    int itemCount;
} order;

void deliShowMenu();
void deliAddItem(order *myOrder);
void deliRemoveItem(order *myOrder);
void deliListOrder(order *myOrder);
void deliCheckout(order *myOrder);