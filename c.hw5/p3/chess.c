#include "chess.h"

bool checkHorizontal(char (*p)[6])
{
    int i, b = 0, w = 0;
    for (i = 1; i < 5; i++)
    {
        if ((*p)[i] == '1') {
            b++;
        }
        else if ((*p)[i] == '0'){
            w++;
        }
    }
    if ((b == 4 || w == 4) && (((*p)[0] == '.' && (*p)[5] != '.') || ((*p)[0] != '.' && (*p)[5] == '.'))) {
        return true;
    }
    return false;
}

bool checkVertical(char (*p)[19])
{
    int i, b = 0, w = 0;
    for (i = 1; i < 5; i++)
    {
        if (p[i][0] == '1') {
            b++;
        }
        else if (p[i][0] == '0'){
            w++;
        }
    }
    if ((b == 4 || w == 4) && ((p[0][0] != '.' && p[4][0] == '.') || (p[0][0] == '.' && p[4][0] != '.'))) {
        return true;
    }
    return false;
}

bool checkDiagonal(char (*p)[19])
{
    int i, b = 0, w = 0;
    for (i = 1; i < 5; i++)
    {
        if (p[i][i] == '1') {
            b++;
        }
        else if (p[i][i] == '0'){
            w++;
        }
    }
    if ((b == 4 || w == 4) && ((p[0][0] == '.' && p[5][5] != '.') || (p[0][0] != '.' && p[5][5] == '.'))) {
        return true;
    }
    return false;
}

bool checkBackDiagonal(char (*p)[18])
{
    int i, b = 0, w = 0;
    for (i = 1; i < 5; i++)
    {
        if (p[i][0] == '1') {
            b++;
        }
        else if (p[i][0] == '0'){
            w++;
        }
    }
    if ((b == 4 || w == 4) && ((p[0][0] == '.' && p[5][0] != '.') || (p[0][0] != '.' && p[5][0] == '.'))) {
        return true;
    }
    return false;
}

void isDeadFour(char chessboard[19][19])
{
    int i, j;
    bool DeadFour = false;
    bool noDeadFour = true;
    for (i = 0; i < 19; i++) {
        for (j = 0; j < 19; j++) {
            if (j <= 13) {
                DeadFour = checkHorizontal((char (*)[6])&chessboard[i][j]);
                if (DeadFour) {
                    printf("DeadFour found: (%c, %2d) (%c, %2d) (%c, %2d) (%c, %2d)\n", j + 'A' + 1, i + 1, j + 2 + 'A', i + 1, j + 3 + 'A', i + 1, j + 4 + 'A', i + 1);
                    noDeadFour = false;
                }
            }
            if (i <= 13) {
                DeadFour = checkVertical((char (*)[19])&chessboard[i - 1][j + 1]);
                if (DeadFour) {
                    printf("DeadFour found: (%c, %2d) (%c, %2d) (%c, %2d) (%c, %2d)\n", j + 'A' + 1, i + 1, j + 'A' + 1, i + 2, j + 'A' + 1, i + 3, j + 'A' + 1, i + 4);
                    noDeadFour = false;
                }
            }
            if ((i <= 13) && (j <= 13)) {
                DeadFour = checkDiagonal((char (*)[19])&chessboard[i][j]);
                if (DeadFour) {
                    printf("DeadFour found: (%c, %2d) (%c, %2d) (%c, %2d) (%c, %2d)\n", j + 'A' + 1, i + 2, j + 2 + 'A', i + 3, j + 3 + 'A', i + 4, j + 4 + 'A', i + 5);
                    noDeadFour = false;
                }
            }
            if ((i <= 13) && (j >= 5)) {
                DeadFour = checkBackDiagonal((char (*)[18])&chessboard[i][j]);
                if (DeadFour) {
                    printf("DeadFour found: (%c, %2d) (%c, %2d) (%c, %2d) (%c, %2d)\n", j + 'A' - 1, i + 2, j + 'A' - 2, i + 3, j + 'A' - 3, i + 4, j + 'A' - 4, i + 5);
                    noDeadFour = false;
                }
            }
        }
    }
    if (noDeadFour) {
        printf("Dead four does not exist.\n");
    }
    return;
}