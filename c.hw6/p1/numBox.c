#include "numBox.h"

numBox* numBoxNew(int cap) {
    numBox *nb = (numBox*)malloc(sizeof(numBox));
    if (cap < 1) {
        nb->capacity = INIT_SIZE;
    } else {
        nb->capacity = cap;
    }

    nb -> size = 0;
    nb -> data = (int*)malloc(sizeof(int) * nb->capacity);
    return nb;
}

void numBoxAdd(numBox* nb, int data)
{   
    if (nb->size == nb->capacity) {
        nb->capacity *= GROWTH_RATE;
        nb->data = (int*)realloc(nb->data, sizeof(int) * nb->capacity);
    }
    nb->data[nb->size] = data;
    nb->size++;
}
void numBoxList(numBox* nb)
{
    printf("size: %d\n", nb->size);
    printf("capacity: %d\n", nb->capacity);
     if (nb->size == 0) {
        printf("content: (empty)\n");
        return;
    }
    printf("content: [");
   
    for (unsigned int i = 0; i < nb->size; i++) {
        printf("%d", nb->data[i]);
        if (i != nb->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
void numBoxFree(numBox* nb) {
    free(nb->data);
    free(nb);
}