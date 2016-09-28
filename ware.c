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
#include "utilise.h"
 

ware*create_ware(){
	char str[100];
	char amount[20]; 
	ware *item = (ware*)malloc(sizeof(struct _ware));
	if(item == NULL)
		return NULL;
	item -> name = (char*)malloc(100*sizeof(char)+1);
	strcpy(item ->name, ask_name(str));
	item -> description = (char*)malloc(100*sizeof(char)+1);
	strcpy(item ->description, ask_description(str));
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

char *set_name(ware*item){
	char *string = (char*)malloc(100*sizeof(char)+1);
	return strcpy(item -> name, ask_name(string));
	free(string); 
}

char *set_des(ware*item){
	char *string = (char*)malloc(100*sizeof(char)+1);
	return strcpy(item -> description, ask_description(string));
	free(string); 
}

int set_price(ware*item){
	char *amount_1 = (char*)malloc(20*sizeof(char) +1); 
	return item -> price = ask_price(amount_1);
	free(amount_1); 
}


