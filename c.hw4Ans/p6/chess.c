#include "chess.h"
#include <stdio.h>

int isHoleThree(char* board, int n, int start, int color) 
{
    char target = (color == 1) ? '1' : '0';

    if (board[start] != target || board[start + 3] != target) return 0;

    int targets = 0, holes = 0;
    for (int i = 0; i < 4; i++) 
    {
        if (board[start + i] == target) targets++;
        else if (board[start + i] == '.') holes++;
    }

    if (targets == 3 && holes == 1) 
    {
        int left_ok = (start == 0 || board[start - 1] == '.');
        int right_ok = (start + 4 == n || board[start + 4] == '.');
        return left_ok && right_ok;
    }
}

int isHoleDeadFour(char* board, int n, int start, int color) 
{
    char target = (color == 1) ? '1' : '0';
    char enemy = (color == 1) ? '0' : '1';

    if (board[start] != target || board[start + 4] != target) return 0;

    int targets = 0, holes = 0;
    for (int i = 0; i < 5; i++) 
    {
        if (board[start + i] == target) targets++;
        else if (board[start + i] == '.') holes++;
    }

    if (targets == 4 && holes == 1) 
    {
        int left_idx = start - 1;
        int right_idx = start + 5;
        
        int left_is_dot = (left_idx >= 0 && board[left_idx] == '.');
        int right_is_dot = (right_idx < n && board[right_idx] == '.');
        int left_blocked = (left_idx < 0 || board[left_idx] == enemy);
        int right_blocked = (right_idx >= n || board[right_idx] == enemy);

        return (left_is_dot && right_blocked) || (right_is_dot && left_blocked);
    }
    return 0;
}

chess_record_t chessNewRecord(int start, int end, int color, pattern_t type) 
{
    chess_record_t record;
    record.start = start;
    record.end = end;
    record.color = color;
    record.type = type;
    return record;
}
void analyzeChess(char* board, chess_record_t* records, int* count) 
{
    int n = MAX_BOARD_SIZE;
    *count = 0;
    int i = 0;

    while (i < n) 
    {
        int found = 0;
        if (board[i] == '1' || board[i] == '0') 
        {
            int color = (board[i] == '1') ? 1 : 0;

            if (isHoleDeadFour(board, n, i, color)) 
            {
                if (*count < MAX_RECORDS) 
                {
                    records[*count] = chessNewRecord(i, i + 4, color, HOLE_DEAD_FOUR);
                    (*count)++;
                    i += 5; 
                    found = 1;
                }
            } 
            else if (isHoleThree(board, n, i, color)) 
            {
                if (*count < MAX_RECORDS) 
                {
                    records[*count] = chessNewRecord(i, i + 3, color, HOLE_THREE);
                    (*count)++;
                    i += 4;
                    found = 1;
                }
            }
        }
        
        if (!found) i++;
    }
}