#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "ware.h"
#include "list.h"


 struct node{
     ware*item;
	 list_t *shelf_list; 
	 struct node *left;
	 struct node *right;
};


struct tree{
	struct node *head;
}; 


tree_t *tree_new(){
	tree_t *root = (struct tree*)malloc(sizeof(struct tree));
	root -> head = NULL; 
	return root; 
}




bool isShelfexist(tree_t *root, shelf *shelfName, char*Itemname){
	if(root -> head ==NULL)
		return false;
	if(strcmp(get_name(root-> head -> item), Itemname) > 0){
		struct node *current = root-> head->left;

		while(current !=NULL){
			if(isexist(current ->shelf_list,shelfName)){
				return true;
			}
			current = current -> left; 
		}
		return false; 
	}
	if(strcmp(get_name(root-> head->item), Itemname) < 0){
		struct node *current = root -> head-> right;
		while(current!=NULL){
			if(isexist(current -> shelf_list, shelfName)){
				return true; 
			}
			current  = current -> right; 
		}
		return false; 
	}
	else {
		return false; 
	}
}





int tree_size(tree_t*root){
	if(root == NULL){
		return 0;}
	else{
		struct tree *temp = tree_new();
		struct tree *current = tree_new(); 
		temp -> head = root -> head-> left;
		current-> head = root-> head -> right; 
		return (tree_size(temp) + 1 + tree_size(current));
	}
}




char*get_name_node(tree_t *root){
	return get_name(root->head ->item);
	}



ware*return_item (tree_t*root){
	return root -> head -> item; 
}




tree_t*find_node(tree_t **root, char*Itemname){
	if ((*root)-> head== NULL)
		return NULL;
  
	else if((*root) ->head!= NULL){
		if(strcmp(get_name((*root)-> head->item), Itemname)== 0){
			return *root;
		}
		else if(strcmp(get_name((*root)->head -> item), Itemname) > 0){
			struct tree *temp = tree_new();
			temp -> head->left  = (*root) -> head; 
			return find_node(&temp, Itemname);
		}
		else{
			struct tree *temp = tree_new();
		    temp -> head-> right  = (*root) -> head; 
			return find_node(&temp, Itemname);
		}
	}
	else{
		return NULL; 
	}

}



int tree_depth(tree_t *node){
	if(node -> head == NULL){
		return 0;
	}
	else {
		struct tree *current = tree_new();
		struct tree *temp = tree_new();	
		temp -> head = node-> head ->left;
		current-> head = node -> head -> right; 
		int lDepth = tree_depth(temp);
		int rDepth = tree_depth(current);
		
		if(lDepth > rDepth){
			return (lDepth +1);} 
		else{
			return(rDepth +1);}
	}
};



void insertNode(tree_t **root, char*Itemname){ 
	if((*root) -> head ==NULL){
		(*root) = tree_new();
		(*root)->head -> item = create_ware(); 
		(*root)-> head -> shelf_list = list_new();
		shelf *Newshelf = new_shelf();
		list_append((*root) ->head -> shelf_list, Newshelf); 
		(*root) -> head-> left = NULL;
		(*root) -> head -> right = NULL; 
	}
	else if(strcmp(get_name((*root)-> head-> item), Itemname)== 0){
		
		printf("the item already existed");
		shelf * newShelf = new_shelf();
		while(!isShelfexist((*root), newShelf ,Itemname)){
			printf("The shelf is already taken please insert new shelf\n");
			newShelf = new_shelf(); 
		}; 
		list_append((*root)->head-> shelf_list, newShelf); 
	}
	
	else if(strcmp(get_name((*root) -> head-> item), Itemname) > 0){
		struct tree *temp = tree_new();
        temp -> head->left  = (*root) -> head; 
		insertNode(&temp, Itemname);}
	
	else if(strcmp(get_name((*root)->head ->item), Itemname) <0){
		struct tree *temp = tree_new();
		temp -> head->right  = (*root) -> head; 
		insertNode(&temp, Itemname);}

}




void print_order(tree_t * root){
	struct tree *temp = tree_new();
	struct tree *curr = tree_new();
	temp -> head-> left = root -> head;
	curr -> head -> right = root -> head;
	print_order(temp);
	printf("%s", get_name(root->head -> item));
	print_order(curr); 
}

bool find_shelf(tree_t *root, shelf*shelfName){
	return isexist(root ->head-> shelf_list, shelfName); 
	return false; 
}

// finding minimum value from the right side of tree
tree_t * min_Value( tree_t* root)
{
	struct tree *current = tree_new(); 
     current-> head= root -> head -> right; 
	
    while (current!=NULL){
        current -> head= current->head ->left;}
	return current;
}



struct node* remove_N(tree_t **root, char*Itemname){
	if((*root) -> head == NULL) 
		printf("the root is empty\n");
	else if(strcmp(get_name((*root) ->head -> item), Itemname) > 0){
		struct tree *temp = tree_new();
		temp -> head  = (*root) -> head ->left; 
		remove_N(&temp, Itemname);
	}
	else if(strcmp(get_name((*root) ->head -> item), Itemname) < 0){
		struct tree *temp = tree_new();
		temp -> head  = (*root) -> head ->right; 
		remove_N(&temp, Itemname);}

	else{
		// delete root and the root has no left or right child
		struct tree *prev = tree_new(); 
	    struct tree *curr = tree_new(); 
		prev -> head  = (*root) -> head ->left;
		curr -> head = (*root) -> head -> right; 
		tree_t *temp = find_node(root, Itemname);
		
		if(*root == temp && temp !=NULL && prev == NULL && curr == NULL){
			free(*root);
			root =NULL; 
		}
		// delete root when the root has only right child
		else if((*root) == temp && temp !=NULL && prev == NULL && curr !=NULL){
			tree_t*var = *root;
			*root = curr; 
			free(var);
	}
		// delte root when the root has  only left child
		else if((*root)== temp && temp !=NULL && prev != NULL && curr ==NULL){
			tree_t*var = *root;
			*root = prev; 
			free(var);
		}
		// delte root when the root has two child
		else{
			tree_t*min = min_Value(curr);
			*root = min;
			curr->head = remove_N(&curr, get_name_node(min));
		}
	
		}
	}



int main (int argc , char **argv){
	char *name = "Car"; 
	tree_t *t = tree_new();
	insertNode(&t, name); 
	return 0;
		}
