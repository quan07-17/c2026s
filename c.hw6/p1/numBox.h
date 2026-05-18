#include "define.h"
#include <stdlib.h>
#include <stdio.h>

numBox* numBoxNew(int cap);
void numBoxAdd(numBox* nb, int data);
void numBoxList(numBox* nb);
void numBoxFree(numBox* nb);