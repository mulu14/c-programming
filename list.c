#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#include "shelf.h"
#include<stdbool.h>


struct link {
	shelf *shelfName;
	struct link *next; 
};
struct list{
	struct link  *first;
	struct link *last; 
};

list_t *list_new(){
	list_t *n = calloc(1, sizeof(struct list)); 
	return n; 
};

void list_prepend (list_t *head, shelf*address){
	struct link *listHead = malloc(sizeof(struct link));
	
	if(head -> first == NULL){
	listHead -> shelfName = address;
	head -> first = listHead;
	head -> last = listHead;
	listHead -> next = NULL;
	}
	else
	{
		listHead -> shelfName = address; 
		listHead -> next = head -> first; 
		head->first = listHead;
	}
  
};

shelf*return_shelf(list_t *head){
	return head -> first -> shelfName; 
}
void list_append (list_t *head, shelf *address){
	struct link *listTail = malloc(sizeof(struct link));
	if(head -> first == NULL){
		list_prepend(head, address);
		return ; 
	}
	
	head -> last -> next = listTail;
	head -> last = listTail;
	listTail -> shelfName = address; 
	listTail -> next = NULL;
   
};

int list_length(list_t* head)
{
	if(head-> first == NULL)
	return 0;

	
	struct link *current = head-> first;
	int size = 0;

  while (current!= NULL)
  {
    current = current->next;
	++size;
  }

  return size;
}

bool list_insert(list_t*head, int index, shelf*address){

	int max = list_length(head);
	struct link*temp = head -> first;
	
	if(index == 0){
		list_prepend(head, address);
		return true;
		}
	
	if(index < max){
	struct link *current = head-> first;
	int i;
	for( i = 0; i <= index-1; ++i){
			current = current -> next;
		}
	temp->next = current -> next;
	current -> next = temp;
	temp-> shelfName = address; 
	return true;
	}
	if(index > max){
		puts("the index is out of range\n");
		return false;
	}
	if(index == max){
		list_append(head, address);
		return true; 
	}
	if(index < 0){
		int i = 0;
		struct link * current = head -> first; 
		for(i = 0; i < max + 1 - index; ++i){
			current = current -> next; 
		}
		temp -> next = current -> next;
		current -> next = temp;
		temp -> shelfName = address;
		return true; 
	}

	return true;

}



		


bool list_remove(list_t *head, int index, shelf*address){

	int length = list_length(head);
	struct link *current = head -> first; 
	if(index > length){
		printf("ERROR: the node does not exit\n");
		return false;
	}
	if(index == 0){
	   current = head -> first;
	   head -> first = head-> first-> next;
		free(current);
	}

	int i;
	for(i = 0; i <= index -1; i++){
		current = current -> next;
	}
		struct link *temp = current -> next;
		current -> next = temp -> next;
		free(temp);
	  return true;
	}


char *list_get(list_t *head, int index){
	struct link  *current = head -> first; 
	int length = list_length(head);
	int i = 0;
	if(current == NULL)
		return NULL;
	if(index > length){
		printf("ERROR: no item \n");
		return NULL; 
	}

	
	if(index < length){
		for(i = 0; i <= index; ++i) {
		current = current -> next; 
	}
		return get_shelf(current ->shelfName);
	}
	
	return NULL;

	
}

shelf *listGetshelf(list_t *head, int index){
	struct link  *current = head -> first; 
	int length = list_length(head);
	int i = 0;
	if(current == NULL)
		return NULL;
	if(index > length){
		printf("ERROR: no item \n");
		return NULL; 
	}

	
	if(index < length){
		for(i = 0; i < index; ++i) {
		current = current -> next; 
	}
		return current ->shelfName;
	}
	
	return NULL;
}




char *list_first(list_t *head){
	if(head -> first != NULL)
		return get_shelf(head -> first->shelfName);
	return NULL; 
} 


char * list_last(list_t *head){
	if(head -> last !=NULL)
		return get_shelf(head -> last->shelfName);
	return NULL; 
}

bool isexist(list_t * head, shelf*address){
	struct link *current = head -> first;

	if(current == NULL)
		return false;

	while(current != NULL){
		if(strcmp(get_shelf(current ->shelfName), get_shelf(address)) == 0)
			return true;
		current = current -> next; 
}
	return false; 
}

void print_link_list(list_t*head){
	int i = 0; 
	if(head -> first == NULL){
		printf("There is no item to print");
		return; 
	} else{
		struct link *current = head -> first;
		while(current != NULL){
			printf("%d.%s\n", i,  get_shelf(current-> shelfName));
			printf("%d.%d\n", i, get_quantity(current -> shelfName)); 
			++i; 
			current = current -> next; 
		}
	}
}
