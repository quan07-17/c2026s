#include <stdio.h>
#include "chess.h"

void chessPrint(chess_record_t* records, int count) {
    if (count == 0) {
        printf("No LIVE_THREE or DEAD_FOUR detected.\n");
        return;
    }

    int liveThreeCount = 0;
    int deadFourCount = 0;

    for (int i = 0; i < count; i++) {
        if (records[i].type == LIVE_THREE) liveThreeCount++;
        else if (records[i].type == DEAD_FOUR) deadFourCount++;
    }

    printf("LIVE_THREE: %d, DEAD_FOUR: %d\n", liveThreeCount, deadFourCount);

    for (int i = 0; i < count; i++) {
        printf("%d ~ %d: %s %s\n", 
            records[i].start + 1, 
            records[i].end + 1, 
            (records[i].color == 1) ? "Black" : "White",
            (records[i].type == LIVE_THREE) ? "LIVE_THREE" : "DEAD_FOUR"
        );
    }
}

int main()
{
    char chessboard[MAX_BOARD_SIZE];
    for (int i = 0; i < MAX_BOARD_SIZE; i++)
    {
        scanf(" %c", &chessboard[i]);
    }

    char* p = &chessboard[0];
    int count = 0;
    chess_record_t records[MAX_RECORDS];

    analyzeChess(p, records, &count);
    chessPrint(records, count);
}