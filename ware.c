#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdint.h>
#include "ware.h"
#include "list.h"
#include "shelf.h"
#include "tree.h"
 struct _ware{
	 char *name;
	 char *description;
	 int price;
	 list_t *shelf_list; 
};

struct _action
{
  int type; 
  ware *merch;
  ware copy;
};


ware*create_ware(){
	char string[100];
	char amount[20];
	ware *item = (struct _ware*)malloc(sizeof(struct _ware));
	if(item == NULL)
		return NULL;
	item -> name = (char*)malloc(100*sizeof(char)+1);
	strcpy(item ->name, ask_name(string));
	item -> description = (char*)malloc(100*sizeof(char)+1);
	strcpy(item ->description, ask_description(string));
	item->price = ask_price(amount);
	item -> shelf_list = list_new();
    shelf *Newshelf = new_shelf();

	/*
	while(!isShelfexist(t, Newshelf)){
			printf("The shelf is already taken please insert new shelf\n");
			Newshelf = new_shelf();
			tree_t * t = tree_new();
			}*/
	list_append(item-> shelf_list, Newshelf); 
	return item; 

	
}; 

char*get_name(ware*item){
	return item -> name; 
};


char *get_des(ware*item){
	return item ->description;  
}

int get_price(ware*item){
	return item -> price; 
}

list_t* return_list(ware *item){
	return item -> shelf_list; 
}



