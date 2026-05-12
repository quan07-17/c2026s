#include <stdio.h>

#include "search.h"

int main()
{
    char str[1024];
    char substr[16];

    printf("Enter a context: ");
    scanf(" %1023[^\n]", str);
    printf("Enter a substring: ");
    scanf(" %15[^\n]", substr);

    int count = search(str, substr);
    printf("The substring [%s] ", substr);
    if (count == 0)
    {
        printf("does not appear ");
    }
    else if (count > 1)
    {
        printf("appears %d times ", count);
    }
    else
    {
        printf("appears %d time ", count);
    }
    printf("in the given context.\n");

    return 0;
}