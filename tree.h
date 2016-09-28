#ifndef __tree_h__
#define __tree_h__

#include <stdbool.h>
#include "shelf.h"
#include "list.h"

/// Define struct tree in your .c file not here! (why?)
typedef struct _ware ware;
 typedef struct node{
   ware*item;
   struct node *left;
   struct node *right;
}_node;

typedef struct tree{
	struct node *head;
}tree_t; 

tree_t *tree_new();
bool isShelfexist(_node *root, shelf *shelfName);
int tree_size(_node*root);
tree_t *tree_head(tree_t*root);
char *return_Node_name(_node*name); 
char*get_name_node(tree_t *root);
_node*find_node(_node*root, char*Itemname);
int tree_depth(_node *leaf);
void insertNode(tree_t *root, char*Itemname);
void* print_order(tree_t * root);
bool find_shelf(tree_t *root, shelf*shelfName);
_node * min_Value(_node* root);
void remove_N(tree_t *root, char*Itemname);
void printTree(tree_t*root);
ware* return_ware(tree_t*root);
char*dump_tree(_node *leaf, char*arry[], int *p_t);
_node*return_node_head(tree_t *root);
void print(_node*d);
void print_p(_node*Node_name, char *ItemName);
ware *returnNodeware(_node*wareName); 

#endif
