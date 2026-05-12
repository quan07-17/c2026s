#include <string.h>

void trim(char *str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            break;
        }
        else
        {
            start++;
        }
    }

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            break;
        }
        else
        {
            end--;
        }
    }

    int j = 0;
    for (int i = start; i <= end; i++)
    {
        str[j++] = str[i];
    }

    str[j] = '\0';
}