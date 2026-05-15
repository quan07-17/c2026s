#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "replace.h"

int main()
{
    char* str = (char*)calloc(1024, sizeof(char));

    char target[128];
    memset(target, 0, sizeof(target));
    char replace[128];
    memset(replace, 0, sizeof(replace));

    scanf(" %1023[^\n]", str);
    scanf(" %127[^\n]", target);
    scanf(" %127[^\n]", replace);

    strReplace(str, target, replace);
    printf("%s\n", str);

    return 0;
}