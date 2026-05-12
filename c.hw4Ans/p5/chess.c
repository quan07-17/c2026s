#include "chess.h"
#include <stdio.h>

int isLiveThree(char* board, int n, int start, int len)
{
    int dot_on_left = (start > 0 && board[start - 1] == '.');
    int dot_on_right = ((start + len) < n && board[start + len] == '.');

    return dot_on_left && dot_on_right;
}

int isDeadFour(char* board, int n, int start, int len, int color)
{
    char enemy = (color == 1) ? '0' : '1';
    int left_idx = start - 1;
    int right_idx = start + len;

    int left_is_dot = (left_idx >= 0 && board[left_idx] == '.');
    int right_is_dot = (right_idx < n && board[right_idx] == '.');
    
    int left_blocked = (left_idx < 0 || board[left_idx] == enemy);
    int right_blocked = (right_idx >= n || board[right_idx] == enemy);

    return (left_is_dot && right_blocked) || (right_is_dot && left_blocked);
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
    for (int i = 0; i < n; i++)
    {
        char symbol = board[i];

        if (symbol == '1' || symbol == '0')
        {
            int color = (symbol == '1') ? 1 : 0;
            int len = 1;

            while ((i + len) < n && board[i + len] == symbol)
            {
                len++;
            }

            int end_idx = i + len;

            if (len == 3)
            {
                if (isLiveThree(board, n, i, len))
                {
                    records[*count] = chessNewRecord(i, end_idx - 1, color, LIVE_THREE);
                    (*count)++;
                }
            }
            else if (len == 4)
            {
                if (isDeadFour(board, n, i, len, color))
                {
                    records[*count] = chessNewRecord(i, end_idx - 1, color, DEAD_FOUR);
                    (*count)++;
                }
            }
            i += (len - 1);
        }
    }
}