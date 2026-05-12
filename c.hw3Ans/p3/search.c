#include <string.h>

int search(const char *str, const char *substr)
{
    int str_len = strlen(str);
    int substr_len = strlen(substr);

    int found = 0;

    if (substr_len == 0 || substr_len > str_len)
    {
        return 0;
    }

    for (int i = 0; i < str_len - substr_len + 1; i++)
    {
        if (strncmp(&str[i], substr, substr_len) == 0)
        {
            found++;
            i += substr_len - 1;
        }
    }

    return found;
}