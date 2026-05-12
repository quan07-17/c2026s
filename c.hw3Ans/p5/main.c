#include <stdio.h>

#include "trim.h"

int main()
{
    char str[33];

    printf("Enter a string:");
    fgets(str, sizeof(str), stdin);
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }

    printf("Before: [%s]\n", str);
    trim(str);
    printf("After: [%s]\n", str);

    return 0;
}