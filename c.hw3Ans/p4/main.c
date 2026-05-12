#include <stdio.h>

#include "numFormat.h"

int main()
{
    char out[17];
    char in[65];

    printf("Enter a 10-digit number: ");
    scanf(" %64s", in);
    in[64] = '\0';

    int stat = numFormat(in, out, sizeof(out));
    switch (stat)
    {
        case 1:
            printf("The number is too long!\n");
            break;
        case 2:
            printf("The number is too short!\n");
            break;
        case 3:
            printf("The number has invalid characters!\n");
            break;
        case 4:
            printf("The number must start with 09!\n");
            break;
        case 0:
            printf("Result: %s\n", out);
    }

    return stat;
}