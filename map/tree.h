#ifndef __tree_h__
#define __tree_h__

#include <stdbool.h>
#include "shelf.h"
#include "list.h"

/// Define struct tree in your .c file not here! (why?)
typedef struct ware_t ware;
 typedef struct node{
   ware*item;
   struct node *left;
   struct node *right;
}node_t;

typedef struct tree{
	struct node *head;
}tree_t; 
void print (node_t*root); 
tree_t *tree_new();
bool isShelftaken(tree_t *root, shelf *shelfName);
int tree_size(node_t**root);
tree_t *tree_head(tree_t*root);
char *return_Node_name(node_t*name); 
char*get_name_node(tree_t *root);
node_t*find_node(tree_t*root, char*Itemname);
int tree_depth(node_t *leaf);
bool insertNode(tree_t *root, ware*ware_name);
void  print_order(tree_t * root);
bool find_shelf(tree_t *root, shelf*shelfName); 
node_t * min_Value(node_t* root);
bool remove_N(tree_t *root, ware*ware_name); 
ware* return_ware(tree_t*root);
node_t*return_node_head(tree_t *root);
ware *returnNodeware(node_t*wareName);
void print_tree_nodes(tree_t*root);
void printTree(tree_t*root); 


#endif
