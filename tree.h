#ifndef __tree_h__
#define __tree_h__

#include <stdbool.h>
#include "shelf.h"
#include "list.h"

/// Define struct tree in your .c file not here! (why?)
typedef struct tree tree_t;
typedef struct _ware ware;
typedef struct node _node;
tree_t *tree_new();
bool isShelfexist(tree_t *root, shelf *shelfName);
int tree_size(tree_t*root);
char*get_name_node(tree_t *root);
tree_t*find_node(tree_t **root, char*Itemname);
int tree_depth(tree_t *node);
void insertNode(tree_t **root, char*Itemname);
void* print_order(tree_t * root);
bool find_shelf(tree_t *root, shelf*shelfName);
tree_t * min_Value( tree_t* root);
void remove_N(tree_t **root, char*Itemname);
void printTree(tree_t*root);
tree_t *tree_head(tree_t*root);
ware* return_ware(tree_t*root); 

#endif
