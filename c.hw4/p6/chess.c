#include "chess.h"

int countColor(char *p, int start, int end, char color)
{
    int i, cnt = 0;
    for (i = start; i <= end; i++)
    {
        if (p[i] == color)
            cnt++;
    }
    return cnt;
}

int countDot(char *p, int start, int end)
{
    int i, cnt = 0;
    for (i = start; i <= end; i++)
    {
        if (p[i] == '.')
            cnt++;
    }
    return cnt;
}

int isOnlyColorOrDot(char *p, int start, int end, char color)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (p[i] != color && p[i] != '.')
            return 0;
    }
    return 1;
}

void analyzeChess(char *p, chess_record_t *records, int *count)
{
    int i;
    *count = 0;

    for (i = 0; i < MAX_BOARD_SIZE;)
    {
        int found = 0;

        if (p[i] == '1' || p[i] == '0')
        {
            char color = p[i];

            /* HOLE_THREE: 長度4，裡面3顆同色+1個洞，左右都要是 . */
            if (i + 3 < MAX_BOARD_SIZE)
            {
                int start = i;
                int end = i + 3;

                if (isOnlyColorOrDot(p, start, end, color) &&
                    countColor(p, start, end, color) == 3 &&
                    countDot(p, start, end) == 1)
                {
                    if (start - 1 >= 0 && end + 1 < MAX_BOARD_SIZE &&
                        p[start - 1] == '.' && p[end + 1] == '.')
                    {
                        records[*count].start = start;
                        records[*count].end = end;
                        records[*count].color = color - '0';
                        records[*count].type = HOLE_THREE;
                        (*count)++;
                        i = end + 1;
                        found = 1;
                    }
                }
            }

            if (found)
                continue;

            /* HOLE_DEAD_FOUR: 長度5，裡面4顆同色+1個洞，至少一端是異色或邊界 */
            if (i + 4 < MAX_BOARD_SIZE)
            {
                int start = i;
                int end = i + 4;

                if (isOnlyColorOrDot(p, start, end, color) &&
                    countColor(p, start, end, color) == 4 &&
                    countDot(p, start, end) == 1)
                {
                    int left_blocked = (start - 1 < 0 || p[start - 1] != '.');
                    int right_blocked = (end + 1 >= MAX_BOARD_SIZE || p[end + 1] != '.');

                    if (left_blocked || right_blocked)
                    {
                        records[*count].start = start;
                        records[*count].end = end;
                        records[*count].color = color - '0';
                        records[*count].type = HOLE_DEAD_FOUR;
                        (*count)++;
                        i = end + 1;
                        found = 1;
                    }
                }
            }

            if (found)
                continue;
        }

        i++;
    }
}