#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "treeStructure.h"

// function definitions
Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );

// task 1
void destroyTree( Node *node );
// task 2
void growTree( Node *node, int maxLevel );
// task 4
void dependentTree( Node *node, int count);

// main
int main( int argc, char **argv ) {
    Node *node;
    int i, treeLevel = 0, task = 0, count = 0, max = 0;

    // make the head node
    node = makeNode( 0.0, 0.0, 0 );

    printf("Test with tree up to 2 or 3 level?");
    scanf("%i", &treeLevel);

    if(treeLevel == 2) {
        // full tree up to level 2
        makeChildren( node );
        makeChildren( node->child[0] );
        makeChildren( node->child[1] );
        makeChildren( node->child[2] );
        makeChildren( node->child[3] );

        // test cases
        printf("Which task to test?");
        scanf("%i", &task);
        switch(task) {

          // test for task 1
          case 1:
            // need to check with valgrind
            destroyTree( node );
            printf("Tree is destroyed\n");
            break;

          // test for task 2
          case 2:
            // this will only grow the tree to one more level
            max = treeLevel + 1;
            for ( i = 0; i < max; i++)
              growTree( node, max );

            writeTree( node );
            printf("Tree is grow to one more level\n");
            // free all memories
            destroyTree( node );
            break;

          // test for task 3
          case 3:
            // set max here
            printf("Enter the max level:");
            scanf("%i", &max);
            for ( i = 0; i < max; i++)
            {
              growTree( node, max );
            }
            writeTree( node );
            // free all memories, check with valgrind
            destroyTree( node );
            break;

          // test for task 4
          case 4:
            dependentTree( node, count );
            writeTree( node );
            // free all memories
            destroyTree( node );
            break;
          default:
            printf("Invalid task number\n");
            break;
        }
      }
    else if ( treeLevel == 3) {
        // non uniform tree up to level 3
        makeChildren( node );
        makeChildren( node->child[0] );
        makeChildren( node->child[1] );
        makeChildren( node->child[3] );
        makeChildren( node->child[1]->child[0] );
        makeChildren( node->child[3]->child[0] );

         // test cases
        printf("Which task to test?");
        scanf("%i", &task);
        switch(task) {

          // test for task 1
          case 1:
            // need to check with valgrind
            destroyTree( node );
            printf("Tree is destroyed\n");
            break;

          // test for task 2
          case 2:
            // this will only grow the tree to one more level
            max = treeLevel + 1;
            for ( i = 0; i < max; i++)
              growTree( node, max );

            writeTree( node );
            printf("Tree is grow to one more level\n");
            // free all memories
            destroyTree( node );
            break;

          // test for task 3
          case 3:
            // set max here
            printf("Enter the max level:");
            scanf("%i", &max);
            for ( i = 0; i < max; i++)
            {
              growTree( node, max );
            }
            writeTree( node );
            // free all memories, check with valgrind
            destroyTree( node );
            break;

          // test for task 4
          case 4:
            dependentTree( node, count );
            writeTree( node );
            // free all memories
            destroyTree( node );
            break;
          default:
            printf("Invalid task number\n");
            break;
        }
      }
    else printf("Invalid tree level\n");
  return 0;
}
