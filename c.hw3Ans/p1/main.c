#include <stdio.h>

#include "reverse.h"

int main()
{
    char str[65];

    printf("Enter a string: ");
    scanf(" %64[^\n]", str);
    str[64] = '\0';

    reverse(str);
    printf("Reversed string: %s\n", str);

    return 0;
}