#ifndef _uppgift_h
#define _uppgift_h
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"

typedef struct _ware ware;
typedef struct _action action ; 
ware * create_ware();
ware *good();
char *get_name(ware*item);
char * ask_name(char *str); 
char * ask_description(char *str) ;
int ask_price(char* str);
int ask_quantity(char* str);
bool is_number_(char*str);
bool string_validation(char *string);
bool right_form(char *str);
#endif
