#include <string.h>

int isVisa(const char *number)
{
    return number[0] == '4';
}

int isMasterCard(const char *number)
{
    int converted = (number[0] - '0') * 10 + (number[1] - '0');
    return (converted >= 51) && (converted <= 55);
}

int isJCB(const char *number)
{

    int converted = (number[0] - '0') * 1000 +
          (number[1] - '0') * 100 +
          (number[2] - '0') * 10 +
          (number[3] - '0');
    return (converted >= 3528) && (converted <= 3589);
}

int luhn(const char *number)
{
    int sum = 0;
    int len = strlen(number);
    
    for (int i = len - 1; i >= 0; i--)
    {
        int digit = number[i] - '0';
        
        if (i % 2 == 0)
        {
            digit *= 2;
        }
        
        if (digit > 9)
        {
            digit -= 9;
        }

        sum += digit;
    }

    return sum % 10 == 0;
}

int isValidCard(const char *number)
{
    if (strlen(number) < 16 || strlen(number) > 16)
    {
        return 0;
    }

    for (int i = 0; number[i] != '\0'; i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            return 0;
        }
    }

    return luhn(number);
}

int cardValid(const char *number, int *valid)
{
    *valid = isValidCard(number);
    if (isVisa(number))
    {
        return 1;
    }
    else if (isMasterCard(number))
    {
        return 2;
    }
    else if (isJCB(number))
    {
        return 3;
    }
    else
    {
        return 0;
    }
}