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




ware * createNewWare(char* name, char* description, int price, list_t* shelf_list){
	ware*newWare =(struct ware_t*)malloc(sizeof(struct ware_t));
	newWare -> name = (char*)malloc(strlen(name)*sizeof(char) +1);
	newWare -> description = (char*)malloc(strlen(description)*sizeof(char) +1);

	strcpy(newWare ->name, name);
	strcpy(newWare ->description, description);
	newWare -> price = price;
	newWare -> shelf_list = shelf_list;
	return newWare;  
}

ware*insertInfo_at_ware(tree_t *t){

	char *name = ask_question_string("insert item name : ");
	char *description = ask_question_string("insert item description: "); 
	int price =   ask_question_int("insert price : ");
    list_t* shelf_list = list_new();
    shelf *Newshelf = new_shelf();

	while(isShelftaken(t, Newshelf)){
			printf("The shelf is already taken please insert new shelf\n");
			Newshelf = new_shelf();
			}

	ware *item = createNewWare(name, description, price, shelf_list);
	list_append(item-> shelf_list, Newshelf);
	return item; 

	
}; 

char*get_name(ware*item){
	return item -> name;
   
};

void destroy_ware(ware*item){
	free(item -> name);
	free(item -> description);
}


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
	char *string = ask_question_string("Please insert item name: "); 
	return strcpy(item -> name, string);
}

char *set_des(ware*item){
	char *string = ask_question_string("Please insert description: "); 
	return strcpy(item -> description, string);
}

int set_price(ware*item){
		return item -> price = ask_question_int("Please insert price: "); 
}


