#include "replace.h"
void strReplace(char *str, char *target, char *replace) 
{
    for (char *p = str; *p != '\0'; p++) 
    {
        if (strncmp(p, target, strlen(target)) == 0) 
        {
            char temp[1024];
            strcpy(temp, p + strlen(target));
            strcpy(p, replace);
            strcat(p, temp);
            p += strlen(replace) - 1;
        }
    }
}