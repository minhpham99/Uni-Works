#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treeStructure.h"


// function definitions

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );
// main

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0,0);

  // make a tree
  //make level 0
  makeChildren( head );
  //make level 1
  makeChildren( head->child[0]);
  makeChildren( head->child[1] );
  makeChildren( head->child[3]);
  //make level 3
  makeChildren( head->child[3]->child[0]);
  makeChildren( head->child[3]->child[0]);

  // print the tree for Gnuplot
	writeTree( head );

  return 0;
}
