#include <stdio.h>
#include <stdlib.h>

#include "numBox.h"

int main()
{
    int cap = 0;
    printf("init capacity: ");
    scanf(" %d", &cap);

    numBox* nb = numBoxNew(cap);

    int data = 0;
    printf("input: ");
    while (scanf(" %d", &data) == 1)
    {
        numBoxAdd(nb, data);
    }

    printf("\n");
    numBoxList(nb);
    numBoxFree(nb);
    
    return 0;
}