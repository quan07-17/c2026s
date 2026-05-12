#include <stdio.h>
#include "FiveInARow.h"

Player checkHorizontal(char (*p)[5])
{
  int i,b=0,w=0;
  for(i=0;i<5;i++)
  {
    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if(b==5) return Black;
  else if(w==5) return White;
  else return None;
}

Player checkVertical(char (*p)[19])
{
  int i,b=0,w=0;
  for(i=0;i<5;i++)
  {
    if(p[i][0]==Black) b++;
    else if(p[i][0]==White) w++;
  }
  if(b==5) return Black;
  else if(w==5) return White;
  else return None;
}

Player checkDiagonal(char (*p)[19])
{
  int i,b=0,w=0;
  for(i=0;i<5;i++)
  {
    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if(b==5) return Black;
  else if(w==5) return White;
  else return None;
}

Player checkBackDiagonal(char (*p)[18])
{
  int i,b=0,w=0;
  for(i=0;i<5;i++)
  {
    if((*p)[0]==Black) b++;
    else if((*p)[0]==White) w++;
    p++;
  }
  if(b==5) return Black;
  else if(w==5) return White;
  else return None;
}

Player check4Winner(char chessboard[19][19])
{
  int i,j;
  Player winner;
  
  for(i=0;i<19;i++)
  {
    for(j=0;j<19;j++)
    {    
      if(j<=14)
      {
        winner=checkHorizontal((char (*)[5])&chessboard[i][j]);
        if(winner!=None) return winner;      
      }
      if(i<=14)
      {
        winner=checkVertical((char (*)[19])&chessboard[i][j]);
        if(winner!=None) return winner;
      }
      if((i<=14)&&(j<=14))
      {
        winner=checkDiagonal((char (*)[19])&chessboard[i][j]);
        if(winner!=None) return winner;
      }
      if((i<=14)&&(j>=4))
      {
        winner=checkBackDiagonal((char (*)[18])&chessboard[i][j]);
        if(winner!=None) return winner;
      }
    }
  }
  return None;
}