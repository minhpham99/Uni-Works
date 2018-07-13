#include<stdlib.h>

/* *************************
 * 
 * This template is meant as a starting point to develop your program.
 * 
 * Rename this file and implement the provided functions (and any additional function you need)
 * 
 * 
 * NAME: 
 * 
 * STUDENT ID:
 * 
 * *************************
 */


#ifndef FUNCTIONS_TO_TEST_H__GUARD
#define FUNCTIONS_TO_TEST_H__GUARD

#define MaxGrid 10

char grid[MaxGrid][MaxGrid];

// initialise the grid
int init_grid(int grid_size) {
    int i,j;
    if (grid_size < 3 || grid_size > 10) {
        return 1;
    }
    else {
        for (i = 0; i < grid_size; i++) {
            for (j = 0; j < grid_size; j++) {
                grid[i][j] = '.';
            }
        }
        return 0;
    }
}
// check for character in each grid
char check_grid() {
    // loop through the grid
        // check for the character in the first grid
            // if the grid is not blank, check for the entire row/column
    return NULL;
}
// check for the player that has win
int player_won(char letter) {
    
    //implement this function!
    
    return 0;
}

// put character into grid square
int make_move(int x, int y, char letter) {
    
    //implement this function!!!
    
    return 0;
    
}


#endif
