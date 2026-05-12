#include <stdio.h>

#include "isPalindrome.h"

int main()
{
    char str[33];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    if (isPalindrome(str))
    {
        printf("Is a palindrome.\n");
    }
    else
    {
        printf("Is not a palindrome.\n");
    }

    return 0;
}