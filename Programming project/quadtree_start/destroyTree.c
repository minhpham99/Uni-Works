#include <stdio.h>
#include <stdlib.h>
#include "destroyTree.h"

void destroyTree( Node *node ) {
    int i;
    // check for children
    if (node->child[0] == NULL) free(node);
    else {
        for ( i = 0; i < 4; i++) {
            destroyTree(node->child[i]);
        }
    free(node);
    }
    return;
}
