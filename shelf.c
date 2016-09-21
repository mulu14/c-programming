#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "shelf.h"
#include "utilise.h"

struct _shelf{
	char*shelf_address;
	int quantity; 
} ;


shelf *new_shelf(){
	char string[20];
	shelf *node = malloc(sizeof(struct _shelf));
	if(node ==NULL)
		return NULL;
	node -> shelf_address = (char*)malloc(20*sizeof(char)+1);
	strcpy(node->shelf_address, ask_question_shelf(string));
	node ->quantity = ask_quantity(string);
	return node;
}

char *get_shelf( shelf*address){
	return address -> shelf_address;
}

int get_quantity(shelf*address){
	return address -> quantity; 
}

int set_quantity(shelf*address){
	char qu[20];
	int newQun = ask_price(qu); 
	return(address-> quantity = newQun); 
}



