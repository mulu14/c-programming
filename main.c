#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "ware.h"
#include "list.h"





int main (int argc , char **argv){
    char * good = "pen"; 
	tree_t *t = tree_new();
	insertNode(&t, good );
	print_order(t);
	remove_N(&t, good);
	print_order(t);
//find_node(&t, good); 
	return 0;

}
