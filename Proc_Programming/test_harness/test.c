
/* Author: Matteo Leonetti m.leonetti@leeds.ac.uk
 *
 * Contanct the instructors if this code does not compile, or for any other related problem.
 *
 *
 */


#include "functions_to_test.h"

#include "unity.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

extern char grid[][MaxGrid];

char test_grid[MaxGrid][MaxGrid];

void reset_test_grid()
{
    for ( int i = 0 ; i < MaxGrid ; i ++ )
        for ( int j = 0 ; j < MaxGrid; j++ )
            test_grid[i][j] =  '.';
}

void randomise_grid ( char grid[][MaxGrid], int size )
{

    int changes = ( rand() % ( size * size ) /2 );

    for ( int i=0; i<changes; ++i ) {
        int x = rand() % size;
        int y = rand() % size;
        char letter = ( rand() %2 ) ? 'X' : 'O';

        grid[x][y] = letter;
    }
}

void setUp ( void )
{
    reset_test_grid();
}

void tearDown ( void )
{
    init_grid(MaxGrid);
}

void print_grid ( char grid[][MaxGrid] )
{
    for ( int i= 0; i < MaxGrid; ++i ) {
        for ( int j=0; j < MaxGrid; ++j )
            printf ( "%c ",grid[i][j] );
        printf ( "\n" );
    }
    printf ( "\n" );
}


void test_init_grid_limits ( void )
{
    for ( int test = 0; test<100 ; ++test ) {
        int size = rand() %30 - 10;

        if(size >=3 && size <= 10) {
            TEST_ASSERT_FALSE_MESSAGE ( init_grid (size ), "init_grid accepted input not in range" );
        }
        else {
            TEST_ASSERT_TRUE_MESSAGE ( init_grid ( size ), "init_grid accepted input not in range" );
        }
    }
}

void test_init_grid_clears()
{
    for ( int test=0; test< 100; ++test ) {
        grid[rand() %MaxGrid][rand() %MaxGrid] = 'X';
        init_grid ( MaxGrid );
        TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE ( test_grid, grid, MaxGrid*MaxGrid,"Grid not cleared after init_grid" );
    }
}

void test_player_won_noone_won()
{

    for ( int size = 3; size <= MaxGrid; ++size ) {
        init_grid ( size );
        TEST_ASSERT_FALSE_MESSAGE ( player_won ( 'X' ), "The player did not win, but player_won() returned true" );
    }

    for ( int test = 0; test<100 ; ++test ) {
        int size = rand() %8 + 3;

        init_grid(size);

        randomise_grid(grid, size);

        int x_found = 0;
        int y_found = 0;
        for(int i=0 ; i < size; ++i) {
            for(int j=0 ; j < size; ++j) {
                if(!x_found && grid[i][j] == 'X') {
                    x_found = 1;
                    grid[i][j] = '.';
                }

                if(!y_found && grid[i][j] == 'O') {
                    y_found = 1;
                    grid[i][j] = '.';
                }
            }
        }

        if(x_found && y_found) {
            TEST_ASSERT_FALSE_MESSAGE ( player_won ( 'X' ), "The player did not win, but player_won() returned true" );
        }
    }
}

void test_player_won_main_diagonal()
{

    for ( int size = 3; size <= MaxGrid; ++size ) {
        init_grid ( size );

        for ( int i = 0; i < size; ++i )
            grid[i][i] = 'X';

        TEST_ASSERT_TRUE_MESSAGE ( player_won ( 'X' ), "The player won, but player_won() returned false" );
    }
}

void test_player_won_secondary_diagonal()
{

    for ( int size = 3; size <= MaxGrid; ++size ) {
        init_grid ( size );

        for ( int i = 0; i < size; ++i )
            grid[i][size-i-1] = 'X';

        TEST_ASSERT_TRUE_MESSAGE ( player_won ( 'X' ), "The player won, but player_won() returned false" );
    }
}

void test_player_won_raws()
{

    for ( int size = 3; size <= MaxGrid; ++size ) {
        init_grid ( size );

        int line = rand() %size;
        for ( int i = 0; i < size; ++i )
            grid[line][i] = 'X';

        TEST_ASSERT_TRUE_MESSAGE ( player_won ( 'X' ), "The player won, but player_won() returned false" );
    }
}

void test_player_won_columns()
{
    for ( int size = 3; size <= MaxGrid; ++size ) {
        init_grid ( size );

        int column = rand() %size;
        for ( int i = 0; i < size; ++i )
            grid[i][column] = 'X';

        TEST_ASSERT_TRUE_MESSAGE ( player_won ( 'X' ), "The player won, but player_won() returned false" );
    }

}

void test_make_move_limits()
{
    //does not accept indices out of range:
    for ( int test = 0; test<100 ; ++test ) {
        int size = rand() %8 + 3;

        int x = rand() %30 - 10;
        int y = rand() %30 - 10;

        init_grid ( size );

        if ( x >= 0 && x <= size-1 && y >=0 && y <= size-1 ) {
            TEST_ASSERT_FALSE_MESSAGE ( make_move ( x,y,'X' ), "make_move() accepted a location that is not on the grid (including negative locations)" );
        } else {
            TEST_ASSERT_TRUE_MESSAGE ( make_move ( x,y,'X' ), "make_move() accepted a location that is not on the grid (including negative locations)" );
        }

    }

}

void test_make_move_changes_character()
{
    for ( int test = 0; test<100 ; ++test ) {
        int size = rand() %8 + 3;

        int x = rand() %size;
        int y = rand() %size;

        init_grid ( size );

        make_move ( x,y,'X' );

        TEST_ASSERT_EQUAL_UINT8_MESSAGE ( 'X', grid[x][y], "make_move() did not update the location" );
    }
}

void test_make_move_does_not_overwrite()
{
    for ( int test = 0; test<100 ; ++test ) {
        int size = rand() %8 + 3;

        int x = rand() %size;
        int y = rand() %size;

        init_grid ( size );

        randomise_grid ( grid,size );

        grid[x][y] = 'X';

        make_move ( x,y,'X' );

        TEST_ASSERT_TRUE_MESSAGE ( make_move ( x,y,'X' ), "make_move() overwrote a location that already contained a character" );
    }
}

void test_make_move_does_not_change_anything_else()
{
    for ( int test = 0; test<100 ; ++test ) {
        int size = rand() %8 + 3;

        int x = rand() %size;
        int y = rand() %size;

        init_grid ( size );

        randomise_grid ( grid,size );

        if ( grid[x][y] != '.' )
            continue; //there is something there already, skip this test

        memcpy ( test_grid,grid,MaxGrid*MaxGrid );
        test_grid[x][y] = 'X';

        make_move ( x,y,'X' );

        TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE ( test_grid, grid, MaxGrid*MaxGrid, "make_move() changed another character besides the one it was supposed to change" );
    }
}



int main ( void )
{
    UNITY_BEGIN();

    srand ( 1 ); //we all do the same tests.

    RUN_TEST ( test_init_grid_limits );
    RUN_TEST ( test_init_grid_clears );

    RUN_TEST ( test_player_won_noone_won );
    RUN_TEST ( test_player_won_main_diagonal );
    RUN_TEST ( test_player_won_secondary_diagonal );
    RUN_TEST ( test_player_won_raws );
    RUN_TEST ( test_player_won_columns );

    RUN_TEST ( test_make_move_limits );
    RUN_TEST ( test_make_move_changes_character );
    RUN_TEST ( test_make_move_does_not_change_anything_else );
    RUN_TEST ( test_make_move_does_not_overwrite );
    return UNITY_END();
}
