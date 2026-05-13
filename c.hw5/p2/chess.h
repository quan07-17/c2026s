#include <stdio.h>
#define bool char
#define true 1
#define false 0

typedef enum {Black=49, White=48, None=0} Player;

bool checkHorizontal(char (*p)[5]);
bool checkVertical(char (*p)[19]);
bool checkDiagonal(char (*p)[19]);
void isLiveThree(char chessboard[19][19]);