#include "growTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void growTree( Node *node, int maxLevel ) {
   int i;

   // check for children
   if (node->child[0] == NULL) {
     if (node->level < maxLevel) {
      makeChildren( node );
     }
   }
   else {
     for (i = 0; i < 4; i++) {
       growTree(node->child[i], maxLevel);
     }
   }
}
