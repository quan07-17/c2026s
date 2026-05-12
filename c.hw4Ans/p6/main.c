#include <stdio.h>
#include "chess.h"

void chessPrint(chess_record_t* records, int count) {
    if (count == 0) {
        printf("No HOLE_THREE or HOLE_DEAD_FOUR detected.\n");
        return;
    }

    int holeThreeCount = 0;
    int holeDeadFourCount = 0;

    for (int i = 0; i < count; i++) {
        if (records[i].type == HOLE_THREE) holeThreeCount++;
        else if (records[i].type == HOLE_DEAD_FOUR) holeDeadFourCount++;
    }

    printf("HOLE_THREE: %d, HOLE_DEAD_FOUR: %d\n", holeThreeCount, holeDeadFourCount);

    for (int i = 0; i < count; i++) {
        printf("%d ~ %d: %s %s\n", 
            records[i].start + 1, 
            records[i].end + 1, 
            (records[i].color == 1) ? "Black" : "White",
            (records[i].type == HOLE_THREE) ? "HOLE_THREE" : "HOLE_DEAD_FOUR"
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