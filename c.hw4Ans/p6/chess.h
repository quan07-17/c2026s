#include "define.h"

typedef struct
{
    int start;
    int end;
    int color;  // 1: Black, 0: White
    pattern_t type;
} chess_record_t;

void analyzeChess(char* board, chess_record_t* records, int * count);