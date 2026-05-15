#include <stdio.h>
#include <stdbool.h>
#include "chess.h"

void formatPrint(int i, int j) 
{
    printf(" (%c, %2d)", 'A' + j, i + 1);
}

void printPoints(int i, int j, int dx, int dy, int n) 
{
    printf("Dead Four found:");
    for (int k = 0; k < n; k++) {
        formatPrint(i + (k * dx), j + (k * dy));
    }
    printf("\n");
}

bool isValidDeadFour(char *p, int dx, int dy, int r, int c) 
{
    int s = dx * 19 + dy;
    char col = *p;

    if (*(p + s) != col || *(p + 2 * s) != col || *(p + 3 * s) != col) 
    {
        return false;
    }

    int lr = r - dx, lc = c - dy;
    int rr = r + 4 * dx, rc = c + 4 * dy;

    bool lIn = (lr >= 0 && lr < 19 && lc >= 0 && lc < 19);
    bool rIn = (rr >= 0 && rr < 19 && rc >= 0 && rc < 19);

    if (lIn && *(p - s) == col) return false;
    if (rIn && *(p + 4 * s) == col) return false;

    bool lD = lIn && (*(p - s) == '.');
    bool rD = rIn && (*(p + 4 * s) == '.');

    return lD ^ rD;
}

void isDeadFour(char b[19][19]) 
{
    int i, j, found = 0;

    for (i = 0; i < 19; i++) 
    {
        for (j = 0; j < 19; j++) 
        {
            if (b[i][j] == '.') continue;

            char *curr = &b[i][j];

            // Horizontal
            if (j <= 15) 
            {
                if (isValidDeadFour(curr, 0, 1, i, j)) 
                {
                    printPoints(i, j, 0, 1, 4);
                    found = 1;
                }
            }
            // Vertical
            if (i <= 15) 
            {
                if (isValidDeadFour(curr, 1, 0, i, j)) 
                {
                    printPoints(i, j, 1, 0, 4);
                    found = 1;
                }
            }
            // Diagonal
            if (i <= 15 && j <= 15) 
            {
                if (isValidDeadFour(curr, 1, 1, i, j)) 
                {
                    printPoints(i, j, 1, 1, 4);
                    found = 1;
                }
            }
            // Anti-diagonal
            if (i <= 15 && j >= 3) 
            {
                if (isValidDeadFour(curr, 1, -1, i, j)) 
                {
                    printPoints(i, j, 1, -1, 4);
                    found = 1;
                }
            }
        }
    }

    // no Dead four
    if (!found) 
    {
        printf("Dead Four does not exist.\n");
    }
}