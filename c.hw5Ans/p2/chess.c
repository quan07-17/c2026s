#include <stdio.h>
#include <stdbool.h>
#include "chess.h"

void formatPrint(int i, int j) 
{
    printf(" (%c, %2d)", 'A' + j, i + 1);
}

void printPoints(int i, int j, int dx, int dy, int n) 
{
    printf("LiveThree found:");
    for (int k = 0; k < n; k++) 
        formatPrint(i + (k * dx), j + (k * dy));
    printf("\n");
}

bool isValidLiveThree(char *p, int dx, int dy) 
{
    int step = dx * 19 + dy;

    if (*(p - step) != '.' || *(p + 3 * step) != '.') 
        return false;

    char color = *p;
    if (*(p + step) == color && *(p + 2 * step) == color) 
        return true;

    return false;
}

void isLiveThree(char b[19][19]) 
{
    int i, j, found = 0;

    for (i = 0; i < 19; i++) 
    {
        for (j = 0; j < 19; j++) 
        {
            if (b[i][j] == '.') continue;

            char *curr = &b[i][j];

            // Horizontal
            if (j >= 1 && j <= 15) 
            {
                if (isValidLiveThree(curr, 0, 1)) 
                {
                    printPoints(i, j, 0, 1, 3);
                    found = 1;
                }
            }
            // Vertical
            if (i >= 1 && i <= 15) 
            {
                if (isValidLiveThree(curr, 1, 0)) 
                {
                    printPoints(i, j, 1, 0, 3);
                    found = 1;
                }
            }
            // Diagonal
            if (i >= 1 && i <= 15 && j >= 1 && j <= 15) 
            {
                if (isValidLiveThree(curr, 1, 1)) 
                {
                    printPoints(i, j, 1, 1, 3);
                    found = 1;
                }
            }
            // Anti-diagonal
            if (i >= 1 && i <= 15 && j >= 3 && j <= 17) 
            {
                if (isValidLiveThree(curr, 1, -1)) 
                {
                    printPoints(i, j, 1, -1, 3);
                    found = 1;
                }
            }
        }
    }

    // no live three
    if (!found) 
        printf("Live three does not exist.\n");
}