#include "Sudoku.h"
#define true 1
#define false 0

void initCounter(int * ptr_counter){
    for(int i=0; i<10; i++){
        ptr_counter[i] = 0; // initialize the counter to 0, ptr_counter[0] is not used.
        // ptr_counter[1] to ptr_counter[9] are used to count the number of 1s to 9s.
    }
}

int checkCounter(int * ptr_counter){
    for(int i=1; i<10; i++){
        if((ptr_counter[i]) != 1) // if the number in each row/column/block is not 1,
        // return false then.
            return false;
    }
    return true;
}

int isValidSudoku(int board[9][9]) { 
    int number_count[10];

    for (int i=0; i<9; i++) {
        initCounter(&number_count[0]);
        for (int j=0; j<9; j++) {
            number_count[board[i][j]] += 1;
        }
        if (checkCounter(&number_count[0]) == false)
            return false;
    }

    for (int i=0; i<9; i++) {
        initCounter(&number_count[0]);
        for (int j=0; j<9; j++) {
            number_count[board[j][i]] += 1;
        }
        if (checkCounter(&number_count[0]) == false)
            return false;
    }

    for (int row=0; row<9; row += 3) {
        for (int col=0; col<9; col += 3) {
            initCounter(&number_count[0]);
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    number_count[board[row + i][col + j]] += 1;
                }
            }
            if (checkCounter(&number_count[0]) == false)
                return false;
        }
    }
    return true;
}
