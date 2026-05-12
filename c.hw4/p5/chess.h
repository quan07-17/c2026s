#ifndef CHESS_H
#define CHESS_H

#include "define.h"

typedef struct
{
    int start;
    int end;
    int color;
    pattern_t type;
} chess_record_t;

void analyzeChess(char *p, chess_record_t *records, int *count);

#endif