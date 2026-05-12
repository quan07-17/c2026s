#include <string.h>

int search(char *str, char *substr) 
{
    int i, j;
    int len = strlen(str);
    int sublen = strlen(substr);
    int count = 0;

   for (i = 0; i < len; i++) {
    if (str[i] == substr[0]) {
        for (j = 0; j < sublen; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
            if (j == sublen - 1) {
                count++;
                i += sublen - 1;
            }
        }
    }
   }

    return count;
}