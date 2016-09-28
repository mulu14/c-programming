#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "ware.h"
#include "list.h"
#include "utilise.h"
int lastupdate; 
typedef struct _action {
	int type;
	ware *merch;
	ware copy;
	}action; 
action trace_action;


void print_menu(){
	puts("[L]ägga till en vara"); 
	puts("[T]a bort en vara");
	puts("[R]edigera en vara");
	puts("Ån[g]ra senaste ändringen");
	puts("Lista [h]ela varukatalogen");
	puts("[A]vsluta");

}

void edit_insert(ware *item){
	int f;
	printf("%d,[N]ame \n", 1);
	printf("%d,[D]escription \n",2);
	printf("%d,[S]helf_adress \n", 3);
	printf("%d,[P]rice \n", 4);
	printf("%d, [Q]antity\n",5);
	printf("Which row you wann edit?\n");
	scanf("%d", &f);
	switch(f){
	case 1:
	   printf("Please insert new name?\n");
	   set_name(item); 
	   printf("The new name is %s\n", get_name(item));
		break;
	case 2:
		printf("Please insert new description?\n");
		set_des(item); 
		printf("The new description %s:\n" , get_des(item));
		break;
	case 3:
		printf("Please insert new shelf_adress?\n");
		set_shelf(return_shelf(return_list(item)));
		printf("The new shelf is %s:\n", get_shelf((return_shelf(return_list(item)))));
		break;
	case 4:
		printf("-------------------------------------\n");
		printf("Please insert new price:\n");
		set_price(item); 
		printf("The new  price %d\n", get_price(item));
		break;
	case 5:
		
		printf("-------------------------------------\n");
		printf("Please insert new quantity:\n");
		set_quantity(return_shelf(return_list(item)));
		printf("The old quantity %d\n", get_quantity(return_shelf(return_list(item))));
		break;	
	default:
		printf("May be you insert wrong item");	
	}
}



void alternativ (){
	printf("%d.Add to database\n", 1);
	printf("%d.Edit information\n", 2);
	printf("%d.Cancel action\n", 3);
}

void add_goods(tree_t *root , ware *foo){
	int see;
	printf("What you wann do?\n");
	alternativ ();
	scanf("%d", &see);
	switch(see){
	case 1:
		insertNode(root,  get_name(foo));
		lastupdate = 1;
		trace_action.merch = foo;
		break;
	case 2:
		edit_insert(foo);
		insertNode(root, get_name(foo)); 
		break;
	case 3:
			memset(foo, 0, sizeof(ware));
			break;
	default:
		break;
	}
}


void remove_goods(tree_t * root, ware *item){
	char * searchItem =  ask_que("Please insert the item you want to remove\t \n");
	_node*node_search = find_node(return_node_head(root), searchItem);
	if(node_search != NULL){
		trace_action.type = 2;
		trace_action.copy = *item; 
		remove_N(root, get_name(item));
		return; 
	}
	else{
		printf("The item you are looking is not find"); 
		return; 
	}
}


void edit_goods(tree_t* root, ware *item){
	int j;
	char size[50]; 
	_node*node_search = find_node(return_node_head(root), get_name(item));
	if(node_search != NULL) {
		print_p(node_search, get_name(returnNodeware(node_search))); 
		item = returnNodeware(node_search);
		scanf("%d", &j);
		switch(j){
		case 1:
			printf("%s, the old name: ", get_name(returnNodeware(node_search)));
			set_name(item); 
			break;
		case 2:
			printf("%d, the old price: ", get_price(returnNodeware(node_search)));
			set_price(item); 
			break; 
		case 3:
			printf("%s, the old description: ", get_des(returnNodeware(node_search)));
			set_des(item); 
			break;
		case 4:
			print_link_list(return_list(item));
			int number  = ask_quantity(size); 
			shelf *sh =listGetshelf(return_list(item), number); 
			printf("%s, the oldshelf: ", get_shelf(sh));
			printf("%d, the old quanity", get_quantity(sh)); 
			set_shelf(return_shelf(return_list(item)));
			set_quantity(return_shelf(return_list(item)));
			break;
			 
		default:
			break; }
	}
	else 
{
	printf("The item you are looking is not on the data base"); 
}
	trace_action.merch = item; 
	trace_action.type = 3;
}


void list_good(tree_t *root){
	printTree(root); 	
}




void display_goods(tree_t *root, ware *item){
	print_p(return_node_head(root), get_name(item)); 
}


void undo_action(tree_t*root, ware *item){
  
	puts("insert undo number alternative here, \n");
	printf("%d.Undo nothing to database\n", 0);
	printf("%d.Undo add information\n", 1);
	printf("%d.Undo delete action\n", 2);
	printf("%d.Undo edit \n", 3);
	scanf("%d", &(trace_action.type));
	switch(trace_action.type){
	case 0:
		printf("There is nothing to do\n");
		break;
	case 1:
		// delete action 
		printf("There is no more thing to undo\n");
		break;
    case 2:
		*trace_action.merch = trace_action.copy;
		add_goods(root, item); 
		lastupdate = 0;
		printf("There is no more thing to undo\n");
		break;
	case 3:
		*trace_action.merch = trace_action.copy;
		// add action 
		lastupdate = 0;
		printf("There is no more thing to undo\n");
		break;
	default:
		printf("There is no action to be done\n");	
	}
}


void exit_program(){
}


int main (int argc , char **argv){

	//ask_question_string("Please insert your name"); 
	tree_t T ;
	ware *ware_name = create_ware();
	
	//printf("%s\n", get_name(ware_name)); 
	tree_t *root = &T; 
	add_goods(root, ware_name); 
	//remove_goods(root, item);
	
	
	//edit_insert(item);
	//edit_goods(root, item); 
	return 0;

}
