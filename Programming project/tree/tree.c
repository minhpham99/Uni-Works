
#include <stdio.h>
#include <stdlib.h>

/* -------------------------------------------
        NODAL DATA STRUCTURE
 ------------------------------------------- */

typedef struct tree_data
{
  int integer_data;
  double real_data; 
} Data;

/* -------------------------------------------
        TREE NODE STRUCTURE
 ------------------------------------------- */

typedef struct tree_node
{
  struct tree_data *data_pointer;
  struct tree_node *left;
  struct tree_node *right;
} Node;

/* -------------------------------------------
          FUNCTION PROTOTYPES
 ------------------------------------------- */

Node *new_node(void);
Node *init_node(int, Node *, Node *);
Node *create_regular_tree(int *, int, int);
Node *create_data_tree(int *, int);
void postorder(Node *);
void preorder(Node *);
void inorder(Node *);

/* -------------------------------------------
  ALLOCATE MEMORY FOR THE NODE AND NODAL DATA
 ------------------------------------------- */

Node *new_node(void)
{
  Node *tree_node;
  Data *data_link;

/* TREE NODE */
  tree_node = (Node *)malloc(sizeof(Node));
  if( tree_node == NULL )
  {
    printf("WARNING: NULL returned from malloc(tree node)\n");
    exit(0);
  }

/* NODAL DATA */
  data_link = (Data *)malloc(sizeof(Data));
  if( data_link == NULL )
  {
    printf("WARNING: NULL returned from malloc(nodal data)\n");
    exit(0);
  }

/* LINK THE TREE NODE TO THE DATA */
  tree_node->data_pointer = data_link;

  return tree_node;
}

/* -------------------------------------------
     INITIALISE THE NODE WITH GIVEN DATA
 ------------------------------------------- */

Node *init_node(int nodal_data, Node *pointer_left, Node *pointer_right)
{
  Node *tree_node;

  tree_node = new_node();

  (tree_node->data_pointer)->integer_data = nodal_data;
  (tree_node->data_pointer)->real_data    = 0.0;
   tree_node->left  = pointer_left;
   tree_node->right = pointer_right;

  return tree_node;
}

/* -------------------------------------------
        CREATE A FULL TREE
 ------------------------------------------- */

Node *create_regular_tree(int tree_data[], int i, int size)
{
  if( i >= size )
  {
    return NULL;
  }
  else
    return init_node(tree_data[i],
                     create_regular_tree(tree_data,2*i+1,size),
                     create_regular_tree(tree_data,2*i+2,size));
}

/* -------------------------------------------
        CREATE A DATA DEPENDENT TREE
 ------------------------------------------- */

Node *create_data_tree(int tree_data[], int n)
{
  int i, done;
  Node *root;
  Node *location;

  root = init_node(tree_data[0], NULL, NULL);

  for( i=1; i<n; ++i )
  {
    location = root;
    done = 0;

    while( done == 0 )
    {
      if( tree_data[i] < (location->data_pointer)->integer_data )
      {
        if( location->left == NULL )
        {
          location->left = init_node(tree_data[i], NULL, NULL);
          done = 1;
        }
        else
          location = location->left;
      }
      else
      {
        if( location->right == NULL )
        {
          location->right = init_node(tree_data[i], NULL, NULL);
          done = 1;
        }
        else
          location = location->right;
      }
    }
  }
  return root;
}

/* -------------------------------------------
           POSTORDER TRAVERSAL
 ------------------------------------------- */

void postorder(Node *node)
{
  if( node != NULL )
  {
    postorder(node->left);
    postorder(node->right);
    printf(" %d\n",(node->data_pointer)->integer_data);
  }
}

/* -------------------------------------------
          PREORDER TRAVERSAL
 ------------------------------------------- */

void preorder(Node *node)
{
  if( node != NULL )
  {
    printf(" %d\n",(node->data_pointer)->integer_data);
    preorder(node->left);
    preorder(node->right);
  }
}

/* -------------------------------------------
          INORDER TRAVERAL
 ------------------------------------------- */

void inorder(Node *node)
{
  if( node != NULL )
  {
    inorder(node->left);
    printf(" %d\n",(node->data_pointer)->integer_data);
    inorder(node->right);
  }
}

/* -------------------------------------------
              MAIN
 ------------------------------------------- */

void main(void)
{
  int size = 16;
  int tree_data[16] = {9,5,17,18,7,2,14,6,4,11,1,16,3,10,12,8};
  Node *root;
/*
  root = create_regular_tree(tree_data, 0, size);
*/
  root = create_data_tree(tree_data, size);

  printf(" Postorder traversal\n");
  postorder(root);

  printf(" Preorder traversal\n");
  preorder(root);

  printf(" Inorder traversal\n");
  inorder(root);

  free(root);
}

