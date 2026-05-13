#include "chess.h"

bool checkHorizontal(char (*p)[5])
{
    int i, b = 0, w = 0;
    for (i = 1; i < 4; i++)
    {
        if ((*p)[i] == '1') {
            b++;
        }
        else if ((*p)[i] == '0'){
            w++;
        }
    }
    if ((b == 3 || w == 3) && ((*p)[0] == '.' && (*p)[4] == '.')) {
        return true;
    }
    return false;
}

bool checkVertical(char (*p)[19])
{
    int i, b = 0, w = 0;
    for (i = 1; i < 4; i++)
    {
        if (p[i][0] == '1') {
            b++;
        }
        else if (p[i][0] == '0'){
            w++;
        }
    }
    if ((b == 3 || w == 3) && (p[0][0] == '.' && p[4][0] == '.')) {
        return true;
    }
    return false;
}

bool checkDiagonal(char (*p)[19])
{
    int i, b = 0, w = 0;
    for (i = 1; i < 4; i++)
    {
        if ((*p)[i] == '1') {
            b++;
        }
        else if ((*p)[i] == '0'){
            w++;
        }
        p++;
    }
    if ((b == 3 || w == 3) && ((*p)[0] == '.' && (*p)[4] == '.')) {
        return true;
    }
    return false;
}

bool checkBackDiagonal(char (*p)[18])
{
    int i, b = 0, w = 0;
    for (i = 1; i < 4; i++)
    {
        if ((*p)[0] == '1') {
            b++;
        }
        else if ((*p)[0] == '0'){
            w++;
        }
        p++;
    }
    if ((b == 3 || w == 3) && ((*p)[0] == '.' && (*p)[4] == '.')) {
        return true;
    }
    return false;
}

void isLiveThree(char chessboard[19][19])
{
    int i, j;
    bool liveThree = false;
    bool noliveThree = true;
    for (i = 0; i < 19; i++) {
        for (j = 0; j < 19; j++) {
            if (j <= 14) {
                liveThree = checkHorizontal((char (*)[5])&chessboard[i][j]);
                if (liveThree) {
                    printf("LiveThree found: (%c, %2d)(%c, %2d)(%c, %2d)\n", j + 'A' + 1, i + 1, j + 2 + 'A', i + 1, j + 3 + 'A', i + 1);
                    noliveThree = false;
                }
            }
            if (i <= 14) {
                liveThree = checkVertical((char (*)[19])&chessboard[i - 1][j + 1]);
                if (liveThree) {
                    printf("LiveThree found: (%c, %2d)(%c, %2d)(%c, %2d)\n", j + 'A' + 1, i + 1, j + 'A' + 1, i + 2, j + 'A' + 1, i + 3);
                    noliveThree = false;
                }
            }
            if ((i <= 14) && (j <= 14)) {
                liveThree = checkDiagonal((char (*)[19])&chessboard[i][j]);
                if (liveThree) {
                    printf("LiveThree found: (%c, %2d)(%c, %2d)(%c, %2d)\n", j + 'A' + 1, i + 1, j + 2 + 'A', i + 2, j + 3 + 'A', i + 3);
                    noliveThree = false;
                }
            }
            if ((i <= 14) && (j >= 4)) {
                liveThree = checkBackDiagonal((char (*)[18])&chessboard[i][j]);
                if (liveThree) {
                    printf("LiveThree found: (%c, %2d)(%c, %2d)(%c, %2d)\n", j + 'A', i + 1, j + 'A' - 1, i + 2, j + 'A' - 2, i + 3);
                    noliveThree = false;
                }
            }
        }
    }
    if (noliveThree) {
        printf("Live three does not exist.\n");
    }
    return;
}