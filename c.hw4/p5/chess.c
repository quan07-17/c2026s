#include "chess.h"

void analyzeChess(char *p, chess_record_t *records, int *count)
{
    int i = 0;
    *count = 0;

    while (i < MAX_BOARD_SIZE)
    {
        if (p[i] == '.')
        {
            i++;
            continue;
        }

        if (p[i] == '1' || p[i] == '0')
        {
            char color = p[i];
            int start = i;

            while (i + 1 < MAX_BOARD_SIZE && p[i + 1] == color)
                i++;

            int end = i;
            int len = end - start + 1;

            if (len == 3)
            {
                if (start - 1 >= 0 && end + 1 < MAX_BOARD_SIZE &&
                    p[start - 1] == '.' && p[end + 1] == '.')
                {
                    records[*count].start = start;
                    records[*count].end = end;
                    records[*count].color = color - '0';
                    records[*count].type = LIVE_THREE;
                    (*count)++;
                }
            }
            else if (len == 4)
            {
                int left_open = (start - 1 >= 0 && p[start - 1] == '.');
                int right_open = (end + 1 < MAX_BOARD_SIZE && p[end + 1] == '.');

                int left_blocked = (start - 1 < 0 || p[start - 1] != '.');
                int right_blocked = (end + 1 >= MAX_BOARD_SIZE || p[end + 1] != '.');

                if ((left_open && right_blocked) || (right_open && left_blocked))
                {
                    records[*count].start = start;
                    records[*count].end = end;
                    records[*count].color = color - '0';
                    records[*count].type = DEAD_FOUR;
                    (*count)++;
                }
            }

            i = end + 1;
        }
        else
        {
            i++;
        }
    }
}