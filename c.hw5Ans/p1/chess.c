#include <stdio.h>
#include "chess.h"

int isValidboard(char chessboard[19][19], Player color)
{
  char *p = &chessboard[0][0];
  int i, j,b=0,w=0;
  for(i=0;i<19;i++)
  {
    for(j=0;j<19;j++)
    {       
      if(chessboard[i][j]==Black) b++;
      else if(chessboard[i][j]==White) w++;
    }
  }

  if (color == Black) 
    if (b == w)
      return 1;
  if (color == White) 
    if ((b-1) == w) 
      return 1;

  return 0;
}