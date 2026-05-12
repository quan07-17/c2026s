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
void isLiveThree(char chessboard[19][19])
{
    int i, j;
    bool liveThree = false;
    for (i = 0; i < 19; i++) {
        for (j = 0; j < 19; j++) {
            if (j <= 14) {
                liveThree = checkHorizontal((char (*)[5])&chessboard[i][j]);
                if (liveThree) {
                    printf("LiveThree found: (%c, %2d)(%c, %2d)(%c, %2d)\n", j + 'A' + 1, i + 1, j + 2 + 'A', i + 1, j + 3 + 'A', i + 1);
                    return;
                }
            }
        }
    }
    printf("Live three does not exist.\n");
    return;
}