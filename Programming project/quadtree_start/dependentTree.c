#include "dependentTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define choice 1
#define tolerance 0.2

void dependentTree( Node *node, int falseCount ) {
  int i;
  falseCount = 0;

  for (i = 0; i < 4; i++) {
    // check for children
    if ( node->child[i] == NULL ) {
      if ( !indicator( node, tolerance, choice ) ) {
        // add children and record number of false
        makeChildren( node );
        falseCount++;
        dependentTree(node, falseCount);
      }
    }
    else {
      dependentTree(node->child[i], falseCount);
    }
  }
}
