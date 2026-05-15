#include <stdio.h>
#include "chess.h"

int main()
{
    char chessboard[19][19];

    for(int i=0;i<19;i++)
        for(int j=0;j<19;j++)
        scanf(" %c",&chessboard[i][j]);

    isDeadFour(chessboard);
}