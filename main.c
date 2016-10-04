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
	puts("[A] add  item"); 
	puts("[R] remove item");
	puts("[E]edit  item");
	puts("[U]ndo lates change");
	puts("[L]ist the whole database");
	puts("[D]isplay content of a item");
	puts("[Q]ite"); 

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
		insertNode(root,  foo);
		lastupdate = 1;
		trace_action.merch = foo;
		break;
	case 2:
		edit_insert(foo);
		insertNode(root, foo); 
		break;
	case 3:
			memset(foo, 0, sizeof(ware));
			break;
	default:
		break;
	}
}


void remove_goods(tree_t * root){
	char itemName[100]; 
	printf("Please insert the item you would like to delete\n");
	scanf("%s", itemName); 
	_node*node_search = find_node(return_node_head(root), itemName);
	ware*ware_name = returnNodeware(node_search);
	if(node_search != NULL){
		trace_action.type = 2;
		trace_action.copy = *ware_name; 
		remove_N(root, ware_name);
		return; 
	}
	else{
		printf("The item you are looking is not find"); 
		return; 
	}
}

void edit_alternative(){
	printf("Please insert edit\n"); 
	printf("%d.Name\n", 1); 
	printf("%d.Price\n", 2);
	printf("%d.Description\n", 3);
	printf("%d.Shelf\n", 4);
	printf("%d.Quantity\n",5); 

}
void edit_goods(tree_t* root){
	int j;
	char size[50];
	printf("Please insert the item you are looking?: ");
	scanf("%s", size); 
	_node*node_search = find_node(return_node_head(root), size);
    ware*item = returnNodeware(node_search); 
	if(node_search != NULL) {
		item = returnNodeware(node_search);
		trace_action.copy = *item; 
		edit_alternative(); 
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
			int index_shelf; 
			printf("Which index shelf you would like to edit\n");
			scanf("%d", &index_shelf);
			shelf *at_index_shelf = listGetshelf(return_list(item), index_shelf);
			printf("%s, the oldshelf: ", get_shelf(at_index_shelf));
			strcpy(get_shelf(at_index_shelf), ask_question_shelf(size)); 
			break;

		case 5:
			print_link_list(return_list(item));
			int index_quantity; 
			printf("Which index shelf you would like to edit\n");
			scanf("%d", &index_quantity);
			shelf *at_index_qun = listGetshelf(return_list(item), index_quantity);
			printf("%d, the old quanity", get_quantity(at_index_qun));
			set_quantity((at_index_qun)); 
			 
		default:
			break; }
	}
	else 
{
	printf("The item you are looking is not on the data base\n"); 
}
		trace_action.merch = item;
	  	trace_action.type = 3;
}


void list_good(tree_t *root){
	printTree(root); 	
}




void display_goods(tree_t *root){
	char itemName[50]; 
	printf("Which item would you like to see?:  ");
	scanf("%s", itemName); 
	_node*node_search = find_node(return_node_head(root), itemName);
	if(node_search !=NULL){
		printf("Name: %s:\n", get_name(returnNodeware(node_search)));
		printf("Description: %s\n", get_des(returnNodeware(node_search)));
		printf("Price: %d\n", get_price(returnNodeware(node_search)));
		printf("Shelf: %s\n", get_shelf(return_shelf(return_list((returnNodeware(node_search))))));
		printf("Quantity: %d\n", get_quantity(return_shelf(return_list((returnNodeware(node_search)))))); 
	}
}


void undo_action(tree_t*root, ware*ware_name){
	puts("insert undo action alternative number here, \n");
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
		remove_N(root, trace_action.merch);
		lastupdate = 0; 
		printf("There is no more thing to undo\n");
		break;
    case 2:
		*strcpy(ware_name-> name, trace_action.copy.name);
		strcpy(ware_name->description, trace_action.copy.description);
		ware_name -> price = trace_action.copy.price;
		ware_name -> shelf_list = trace_action.copy.shelf_list;
		insertNode(root, ware_name); 
		lastupdate = 0;
		printf("There is no more thing to undo\n");
		break;
	case 3:
		*ware_name = trace_action.copy;
		add_goods(root, ware_name); 
		lastupdate = 0;
		printf("There is no more thing to undo\n");
		break;
	default:
		printf("There is no action to be done\n");	
	}
}


bool quit_action()
{
  do
    {
      puts("Do you want to quit? [Y/N]");
      char input = getchar(); 

      if (input == 'Y') return true;
      if (input == 'N') return false;

      puts("Only Y or N are valid answers!");
    }while(true); 

  return false;
}




int main (int argc , char **argv){
	
	
	printf("Välkommen till lagerhantering 1.0\n"); 
	printf("=================================\n"); 

	ware * ware_name = createWare(); 
	tree_t *root = tree_new();
	char c; 
	bool end_action = false;
	while(!end_action){
		puts("What are you going to do?\n");
		print_menu(); 
    	scanf("%c",&c);
		if(c =='A'){
			ware *wareName = insertInfo_at_ware(); 
			add_goods(root, wareName);
		}
	    if(c =='R'){
			remove_goods(root);
		}
		if(c =='D'){
			display_goods(root);
		}
	    if(c =='E'){
			edit_goods(root);
		}
	    if(c== 'U'){
			undo_action(root, ware_name);
		}
		if(c=='L'){
		list_good(root);
		}
		if(c=='Q'){
			end_action = quit_action();}
			}
	
	
	/*

	ware*name = insertInfo_at_ware();
	trace_action.copy = *name;
	*trace_action.merch = 	trace_action.copy; 
	printf("%s\n", get_name(trace_action.merch)); 
	tree_t *root = tree_new();
	add_goods(root, name); 
	print_p(return_node_head(root), "Key"); 
	remove_goods(root, trace_action.merch);
    printf("%s\n", get_name(trace_action.merch)); 
	*/
	/*
	print_p(return_node_head(root), "Key");
	undo_action(root, name);
	print_p(return_node_head(root), "Key"); */
	return 0; 
	//printTree(root);
	//printf("%s", get_name(return_ware(root))); 
	//
	

}
