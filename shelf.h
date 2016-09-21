#ifndef _shelf_h
#define _shelf_h
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct _shelf shelf;


shelf *new_shelf(); 
char *get_shelf(shelf*address);
int get_quantity(shelf*address);
int set_quantity(shelf*address); 

#endif
