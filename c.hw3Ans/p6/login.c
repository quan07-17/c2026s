#include <string.h>

int login(const char *acc, const char *pw)
{
    char acc_list[][20] =
    {
        "junwu",
        "someone",
        "linda",
        "markonbizz"
    };
    char pw_list[][20] =
    {
        "Professor Wu",
        "at Some Where",
        "Smart Girl",
        "Mark's Password"
    };

    int acc_exists = 0;
    int acc_i = -1;

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(acc, acc_list[i]) == 0)
        {
            acc_i = i;
            break;
        }
    }

    if (acc_i == -1)
    {
        return 1;
    }

    if (strcmp(pw, pw_list[acc_i]) != 0)
    {
        return 2;
    }

    return 0;
}