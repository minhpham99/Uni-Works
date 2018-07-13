

/* *************************
 * 
 * In order to automatically test your program, you MUST implement the functions below.
 * The name of the function, the parameters it takes, and the return type has to be EXACTLY as specified below,
 * otherwise the test won't run.
 * 
 * For the purpose of testing rename your main() function into main_mine() and then compile the test as follows:
 * 
 * gcc --std=c99 -o test test.c unity.c YOURFILE.c
 * 
 * where you have substituted YOURFILE.c with the name of your file.
 * 
 * To run the tests, execute:  ./test
 * 
 * *************************
 */


#ifndef FUNCTIONS_TO_TEST_H__GUARD
#define FUNCTIONS_TO_TEST_H__GUARD

#define MaxGrid 10

int init_grid(int grid_size);

int player_won(char letter);

int make_move(int x, int y, char letter);


#endif

