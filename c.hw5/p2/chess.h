#include <stdio.h>
#define bool char
#define true 1
#define false 0

typedef enum {Black=49, White=48, None=0} Player;

bool checkHorizontal(char (*p)[5]);
void isLiveThree(char chessboard[19][19]);