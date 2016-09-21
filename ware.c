#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ware.h"
#include "list.h"
#include "shelf.h"
#include<stdint.h> 
 struct _ware{
	 char *name;
	 char *description;
	 int price;
};

struct _action
{
  int type; // NOTHING = 0, ADD = 1, REMOVE = 2, EDIT = 3
  ware *merch;
  ware copy;
};

ware *good(){
	ware *good = (struct _ware*)malloc(sizeof(struct _ware));
	good -> name = (char*)malloc(100*sizeof(char)+1);
	good -> description = (char*)malloc(100*sizeof(char)+1);
	good -> price = 0; 
}

ware*create_ware(){
	ware*item = good(); 
	char string[100];
	char amount[20];
	if(item == NULL)
		return NULL;
	strcpy(item ->name, ask_name(string));
	strcpy(item ->description, ask_description(string));
	item->price = ask_price(amount);
	return item; 

	
}; 

char*get_name(ware*item){
	return item -> name; 
};

/*
action *save_action(){

	action*new_action = (struct _action*)malloc(sizeof(struct _action));
	new_action -> type = 0;
	new_action -> merch = NULL;
	new_action -> copy = ware; 
}; 
*/




