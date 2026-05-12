#include <string.h>

int numFormat(char *in, char *out, int out_size)
{
    int len = (int)strlen(in);

    if (len > 10)
    {
        return 1;
    }
    else if (len < 10)
    {
        return 2;
    }

    for (int i = 0; i < len; i++)
    {
        if (in[i] < '0' || in[i] > '9')
        {
            return 3;
        }
    }

    if (in[0] != '0' || in[1] != '9')
    {
        return 4;
    }

    int i = 0;
    int j = 0;
    while (i < len && j < out_size - 1)
    {
        if (i == 4 && j == 4)
        {
            out[j++] = '-';
        }
        else
        {
            out[j++] = in[i++];
        }
    }
    out[j] = '\0';

    return 0;
}