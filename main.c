#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "ware.h"
#include "list.h"
#include "utilise.h"
int lastupdate; 
typedef struct _action {
  int type;
  ware *merch;
  ware *copy;
}action; 
action trace_action;


void print_menu(){
  puts("[A] add  item"); 
  puts("[R] remove item");
  puts("[E]edit  item");
  puts("[U]ndo lates change");
  puts("[L]ist the whole database");
  puts("[D]isplay content of a item");
  puts("[Q]ite"); 

}

void edit_insert(ware *item){
  int f;
  printf("%d,[N]ame \n", 1);
  printf("%d,[D]escription \n",2);
  printf("%d,[S]helf_adress \n", 3);
  printf("%d,[P]rice \n", 4);
  printf("%d, [Q]antity\n",5);
  printf("Which row you wann edit?\n");
  scanf("%d", &f);
  switch(f){
  case 1:
    printf("Please insert new name?\n");
    set_name(item); 
    printf("The new name is %s\n", get_name(item));
    break;
  case 2:
    printf("Please insert new description?\n");
    set_des(item); 
    printf("The new description %s:\n" , get_des(item));
    break;
  case 3:
    printf("Please insert new shelf_adress?\n");
    set_shelf(return_shelf(return_list(item)));
    printf("The new shelf is %s:\n", get_shelf((return_shelf(return_list(item)))));
    break;
  case 4:
    printf("-------------------------------------\n");
    printf("Please insert new price:\n");
    set_price(item); 
    printf("The new  price %d\n", get_price(item));
    break;
  case 5:
		
    printf("-------------------------------------\n");
    printf("Please insert new quantity:\n");
    setQauntity(return_shelf(return_list(item)), ask_question_int("insert Quantity : ")); 
    // printf("The old quantity %d\n", get_quantity(return_shelf(return_list(item))));
    break;	
  default:
    printf("May be you insert wrong item");	
  }
}



void alternativ (){
  printf("%d.Add to database\n", 1);
  printf("%d.Edit information\n", 2);
  printf("%d.Cancel action\n", 3);
}

void add_goods(tree_t *root , ware *wareP_t){
  int see;
  node_t*node_search = find_node(root, get_name(wareP_t));
  printf("What you wann do?\n");
  alternativ ();
  scanf("%d", &see);
  switch(see){
  case 1:
     if(node_search !=NULL){
      printf("Item exist,Insert shelf : ");
      ware*ware_name = returnNodeware(node_search); 
      shelf*add_only_shelf = new_shelf();
      list_append(return_list(ware_name),add_only_shelf);
    }
		
    else {
      insertNode(root, get_name(wareP_t), wareP_t); 
    }	
    break;
  case 2:
    edit_insert(wareP_t);
    insertNode(root,get_name(wareP_t), wareP_t); 
    break;
  case 3:
    memset(wareP_t, 0, sizeof(ware));
    break;
  default:
    break;
  }
  lastupdate = 1;
  trace_action.merch =wareP_t;
}


void remove_goods(tree_t * root){
  print(return_node_head(root));
  char itemtoRemove[100];
  printf("Remove item : ");
  scanf("%s", itemtoRemove); 
  node_t*node_search = find_node(root, itemtoRemove);

  if (node_search == NULL)
    return;
	
  else {
    ware*ware_name = returnNodeware(node_search);
    trace_action.type = 2;
    trace_action.merch = ware_name; 
    remove_N(root, get_name(ware_name));
  }
}

void edit_alternative(){
  printf("Please insert edit\n"); 
  printf("%d.Name\n", 1); 
  printf("%d.Price\n", 2);
  printf("%d.Description\n", 3);
  printf("%d.Shelf\n", 4);
  printf("%d.Quantity\n",5); 

}
void edit_goods(tree_t* root){
  int j; 
  print(return_node_head(root)); 
  char itemtoEdit[100];
  printf("Edit item : ");
  scanf("%s", itemtoEdit);
  node_t*node_search = find_node(root, itemtoEdit);

  if(node_search == NULL)
    return;
  else {
    ware*item = returnNodeware(node_search); 
    item = returnNodeware(node_search);
    trace_action.copy = createNewWare(strdup(get_name(item)), strdup(get_des(item)),get_price(item), copyListA(return_list(item)));
    trace_action.merch = item;
    trace_action.type = 3;
    edit_alternative(); 
    scanf("%d", &j);
    switch(j){
    case 1:
      printf("%s, the old name: ", get_name(returnNodeware(node_search)));
      set_name(item);
      printf("%s, name after edit: ", get_name(trace_action.copy));
      printf("%s, des after edit: ", get_des(trace_action.copy));
      printf("%d, des after edit: ", get_price(trace_action.copy));
      printf("Shelf: %s\n", get_shelf(return_shelf(return_list(trace_action.copy))));
      printf("Quantity: %d\n", get_quantity(return_shelf(return_list(trace_action.copy))));
      printf("%s, current name: ", get_name(trace_action.merch)); 
      break;
    case 2:
      printf("%d, the old price: ", get_price(returnNodeware(node_search)));
      set_price(item); 
      break; 
    case 3:
      printf("%s, the old description: ", get_des(returnNodeware(node_search)));
      set_des(item); 
      break;
    case 4:
      print_link_list(return_list(item));
      int index_shelf; 
      printf("Which index shelf you would like to edit\n");
      scanf("%d", &index_shelf);
      shelf *at_index_shelf = listGetshelf(return_list(item), index_shelf);
      printf("%s, the oldshelf: ", get_shelf(at_index_shelf));
      char *shelfname = ask_question_shelf("insert shelf : ");
      strcpy(get_shelf(at_index_shelf), shelfname); 
      break;

    case 5:
      print_link_list(return_list(item));
      int index_quantity; 
      printf("Which index shelf you would like to edit\n");
      scanf("%d", &index_quantity);
      shelf *at_index_qun = listGetshelf(return_list(item), index_quantity);
      printf("%d, the old quanity", get_quantity(at_index_qun));
      setQauntity(at_index_qun, ask_question_int("insert Quantity : ")); 
			 
    default:
      break; 
    }
   
  }
       
		
}




void list_good(tree_t *root){  
  printTree(root); 
}

        


void display_goods(tree_t *root){
  print(return_node_head(root)); 
  char itemtoDisplay[100];
  printf("Display item : ");
  scanf("%s", itemtoDisplay);
  node_t*node_search = find_node(root, itemtoDisplay);
  if(node_search !=NULL){
    printf("Name: %s:\n", get_name(returnNodeware(node_search)));
    printf("Description: %s\n", get_des(returnNodeware(node_search)));
    printf("Price: %d\n", get_price(returnNodeware(node_search)));
    printf("Shelf: %s\n", get_shelf(return_shelf(return_list((returnNodeware(node_search))))));
    printf("Quantity: %d\n", get_quantity(return_shelf(return_list((returnNodeware(node_search)))))); 
  }
}


void undo_action(tree_t*root){
  puts("0.Undo nothing to database");
  puts("1.Undo add information");
  puts("2.Undo delete action");
  puts("3.Undo edit");
  scanf("%d", &(trace_action.type));
  switch(trace_action.type){
  case 0:
    printf("There is nothing to do\n");
    break;
  case 1:
    remove_N(root, get_name(trace_action.merch));
    lastupdate = 0; 
    break;
  case 2:
    remove_N(root, get_name(trace_action.merch));
    insertNode(root,get_name(trace_action.copy), trace_action.copy);
    lastupdate = 0;
    break;
  case 3:
    remove_N(root, get_name(trace_action.merch));
    insertNode(root, get_name(trace_action.copy),trace_action.copy);
    lastupdate = 0;
    break;
  default:
    printf("There is no action to be done\n");	
  }
}


bool quit_action()
{
  do
    {
      puts("Do you want to quit? [Y/N]");
      char input = getchar(); 

      if (input == 'Y') return true;
      if (input == 'N') return false;

      puts("Only Y or N are valid answers!");
    }while(true); 

  return false;
}




int main (int argc , char **argv){
	
	
  printf("Välkommen till lagerhantering 1.0\n"); 
  printf("=================================\n");
	
  tree_t *root = tree_new();


  char c; 
  bool end_action = false;
  while(!end_action){
    puts("What are you going to do?\n");
    print_menu(); 
    scanf("%c",&c); 
    if(c =='A'){
      ware*wareName = insertInfo_at_ware(root); 
      add_goods(root, wareName);
    }
    if(c =='R'){
      remove_goods(root);
    }
    if(c =='D'){
      display_goods(root);
    }
    if(c =='E'){
      edit_goods(root);
    }
    if(c== 'U'){
      undo_action(root);
    }
    if(c=='L'){
      list_good(root);
     }
    if(c=='Q'){
			
      end_action = quit_action();
    }
		
  }
	
  free(root); 
  return 0; 
   
	

}
