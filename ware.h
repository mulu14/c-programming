#ifndef _uppgift_h
#define _uppgift_h
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
typedef struct _ware{
	 char *name;
	 char *description;
	 int price;
	 list_t *shelf_list; 
}ware;
typedef struct list list_t;
ware*insertInfo_at_ware(); 
ware *createWare(); 
char *get_name(ware*item);
char *get_des(ware*item);
int get_price(ware*item);
list_t* return_list(ware *item);
char *set_name(ware*item); 
char *set_des(ware*item); 
int set_price(ware*item); 
#endif
