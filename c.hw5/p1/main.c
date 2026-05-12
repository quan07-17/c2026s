#include <stdio.h>
#include <string.h>
#include "chess.h"


int main()
{
    char chessboard[19][19];
    char color_str[10];
    Player player;
    scanf("%s", color_str);
    for(int i=0;i<19;i++)
        for(int j=0;j<19;j++)
            scanf(" %c",&chessboard[i][j]);

    player = (strcmp(color_str,"Black")==0)?Black:White;
    
    (isValidboard(chessboard, player) == true) ? 
        printf("Valid!\n") :
        printf("Invalid!\n");
}