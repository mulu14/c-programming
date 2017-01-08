#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"
#include "ware.h"
#include "list.h"
#include "shelf.h"




node_t *create_node(){
	node_t *nodeTree = (struct node*)malloc(sizeof(struct node));
	nodeTree -> item = NULL;
	nodeTree -> left = NULL;
	nodeTree -> right = NULL; 
	return nodeTree; 
}

tree_t *tree_new(){
	tree_t *root = (struct tree*)malloc(sizeof(struct tree));
	root->head = NULL;
	return root; 
}


char *return_Node_name(node_t*name){
	return get_name(name -> item); 
}

node_t*return_node_head(tree_t *root){
	return root -> head; 
}

ware *return_ware(tree_t *root){
	return root -> head ->item; 
}

ware *returnNodeware(node_t*wareName){
	return wareName -> item; 
}




bool isShelftakenaux(node_t *root, shelf *shelfName){
	if(root ==NULL)
		return false;
	else {
		if(isexist(return_list(returnNodeware(root)) ,shelfName) == true){
				return true;
	
		}}
	return isShelftakenaux(root -> left, shelfName) || isShelftakenaux(root -> right, shelfName); 
}


bool isShelftaken(tree_t *root, shelf *shelfName){
	if(root ==NULL)
		return false;
	return isShelftakenaux(root -> head, shelfName); 
}



 
int tree_size(node_t** node){
	if((*node) == NULL){
		return 0;}
	else{
		return (tree_size(&((*node)-> left)) + tree_size(&((*node)->right)) +1);
	}
}




char*get_name_node(tree_t *root){
	if(root -> head == NULL){
		return NULL;}
	else {
		return get_name(root->head ->item);
	}
	return NULL; 
}

char *getNodename(node_t * leaf){
  if(leaf == NULL){
    return NULL; 
  }
  else {return get_name(leaf -> item); 
}
  return NULL; 
}



node_t*findaux(node_t *root, char*Itemname){
	if (root== NULL)
		return NULL;
  
	else {
		
		if(strcmp(get_name(root->item), Itemname)== 0){
			return root;
		}
		else if(strcmp(get_name(root-> item), Itemname) > 0){
			
			
			return findaux(root -> left, Itemname);
		}
		else {
			return findaux(root -> right, Itemname);
		}
	}
   
}


node_t*find_node(tree_t*root, char*name){
	if(root-> head == NULL){
		return NULL; }
	return findaux(root -> head, name); 
}


bool findnode(node_t *root, char*Itemname){
	if (root== NULL)
		return false;
  
	else {
		
		if(strcmp(get_name(root->item), Itemname)== 0){
			return true;
		}
		else if(strcmp(get_name(root-> item), Itemname) > 0){
			
			
			return findnode(root -> left, Itemname);
		}
		else {
			return findnode(root -> right, Itemname);
		}
	}
   
}

bool find_Node(tree_t*root, char*name){
	if(root-> head == NULL){
		return false; }
	return findnode(root -> head, name); 
}


int tree_depth(node_t *leaf){
	if(leaf == NULL){
		return 0;
	}
	else {
		int lDepth = tree_depth(leaf -> left);
		int rDepth = tree_depth(leaf -> right);
		
		if(lDepth > rDepth){
			return (lDepth +1);} 
		else{
			return(rDepth +1);}
	}
	return 0; 
};



bool insertaux(node_t **root, ware*ware_name){
	char *Itemname = get_name(ware_name); 
	if(*root ==NULL){
		(*root) = create_node(); 
		(*root)-> item = ware_name; 
		(*root)-> left = NULL;
		(*root) ->right = NULL;
		return true; 
	}
	
	else if(strcmp(get_name((*root)-> item), Itemname)== 0){
  
		return false; 
	}
	
	else if(strcmp(get_name((*root) -> item), Itemname) > 0){
		
		insertaux(&((*root)->left), ware_name);
		return true; 
	}
	
	else if(strcmp(get_name((*root) ->item), Itemname) <0){
 
		insertaux(&((*root)-> right), ware_name);
		return true; 
	}
	
	return true; 
}

bool insertNode(tree_t *root, ware*ware){
	if(root -> head == NULL){
		root -> head = create_node();
		root ->head -> item = ware;
		root -> head -> left = NULL;
		root -> head -> right = NULL;
		return true; 
	}
	insertaux(&(root->head), ware);
	return true; 
}



node_t * min_Value(node_t* root){
	if(root == NULL){
		return NULL; 
	}
	else {
		node_t *current =root ; 
	
		while (current -> left!=NULL){
		   current= current ->left;}
		return current;
	}
}



bool removeaux(node_t **root, ware*ware_name){
	char *Itemname = get_name(ware_name);
	bool exist = findnode(*root, Itemname); 
	if(exist == false) {
		return true;
	}
	else if(strcmp(get_name((*root) ->item), Itemname) > 0){
		return removeaux(&((*root)-> left), ware_name);
	}
	else if(strcmp(get_name((*root) ->item), Itemname) < 0){
		return removeaux(&(*root)-> right, ware_name);}

	else{
		/* delete root and the root has no left or right child*/
		
		if( (*root)-> left == NULL && (*root) -> right == NULL){
			free(root);
			root = NULL;
			return true; 
		}
		/* delete root when the root has only right child*/
		else if( (*root) -> left == NULL && (*root) -> right != NULL){
			node_t*var  = (*root)->right;
			*root = var;   
			return true;
	}
		/* delete root when the root has  only left child*/
		else if((*root) -> left != NULL && (*root) ->right == NULL){
			node_t *var = (*root)-> left;
			*root = var; 
			return true; 
		}
		/* delte root when the root has two child*/
		else{
			node_t *min = min_Value(*root);
			*root = min; 
			return removeaux(root, returnNodeware(min));
		}
	
		}
	return true; 
	}

bool remove_N(tree_t*root, ware*ware_name){
	if(root -> head == NULL)
		return true;
	removeaux(&(root -> head), ware_name);
	return true; 
}


void print (node_t*root){
	if(root == NULL)
		return; 
	{
		print(root -> left); 
		printf("%s\n", get_name(returnNodeware(root)));
		print(root -> right);
	}
}



void dumpTree(node_t *node, node_t *arry[], int* p_t){
  if(node){
      dumpTree(node-> left, arry, p_t);
      arry[*p_t] = node;
      *p_t += 1; 
      dumpTree(node -> right, arry, p_t);
    }
  else{
  }
}


void printTree(tree_t*tree){
	int i = 0 , j = 1; 
	int size = tree_size(&(tree-> head)); 
    node_t* nodeArray[size];
	dumpTree(tree -> head, nodeArray, &i);	   
	for(i = 0; i < size; i++, ++j){
			printf("%d. %s\n", j, get_name(returnNodeware(nodeArray[i])));
		}
}




		




