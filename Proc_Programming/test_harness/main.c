#include<stdio.h>
#define MaxGrid 10

char grid[MaxGrid][MaxGrid];

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
            printf("%i %s\n", i, grid);
        }
        return 0;
    }
}

int player_won(char letter) {
    
    //implement this function!
    
    return 0;
}

int make_move(int x, int y, char letter) {
    
    //implement this function!!!
    
    return 0;
    
}

int main() {
    init_grid(10);
}