#include "chess.h"

int isValidboard(char colorStr[19][19], Player player)
{
    int blackCount = 0, whiteCount = 0;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (colorStr[i][j] == 49) {
                blackCount++;
            } else if (colorStr[i][j] == 48) {
                whiteCount++;
            }
        }
    }

    if (player == Black && blackCount == whiteCount) {
        return true;
    }
    if (player == White && blackCount == whiteCount + 1) {
        return true;
    }
    return false;
}