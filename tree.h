#ifndef __tree_h__
#define __tree_h__

#include <stdbool.h>

/// Define struct tree in your .c file not here! (why?)
typedef struct tree tree_t;
typedef struct _ware ware; 

/// \file tree.h
///
/// \author Tobias Wrigstad
/// \version 1.0
/// \date 2015-08-28
/// \bug This file is partial. (On purpose.)


/// Creates a new tree
///
/// \returns: empty tree
tree_t *tree_new();

/// Get the size of the tree 
///
/// \returns: the number of nodes in the tree
int tree_size(tree_t *tree);

/// Get the depth of the tree 
///
/// \returns: the depth of the deepest subtree
int tree_depth(tree_t *tree);

tree_t *tree_insert(tree_t *tree, ware*items);

/// This does not need implementation until Assignment 2
tree_t *tree_remove(tree_t *tree, ware* items);
void insertNode(tree_t **root, char*Itemname); 

#endif
