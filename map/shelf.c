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

shelf * makeShelf(char *shelfname, int quantity){
	shelf *node = malloc(sizeof(struct _shelf));
	node -> shelf_address = malloc(strlen(shelfname)*sizeof(char)+1);
	strcpy(node -> shelf_address, shelfname);
	node -> quantity = quantity;
	return node; 
}

shelf *new_shelf(){
	char *shelfname = ask_question_shelf("insert shelf : ");
	int quantity = ask_question_int("insert item quantity: ");
	shelf *add = makeShelf(shelfname, quantity); 
    return add;
}

char *get_shelf(shelf*address){
	return address -> shelf_address;
}

int get_quantity(shelf*address){
	return address -> quantity; 
}

int set_quantity(shelf*address){
	return address-> quantity = ask_question_int("insert quantity: "); 
}


char *set_shelf(shelf *address){
	char *shelfname = ask_question_shelf("insert shelf : ");
	return strcpy(address->shelf_address, shelfname) ;
}
