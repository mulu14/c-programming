#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include "utilise.h"


int read_string(char*buf, int bt_siz){
	int c;
	int i = 0;
 

	do {
          c = getchar(); 
          buf[i] = c ;
          ++i;
	}while(i < bt_siz &&  c!='\n');
        buf[i-1] = '\0';
	return i -1; 
}

char * ask_question_string_(char* question, char*buf, int buf_siz){
	do {
		printf("%s", question);
	}while(read_string(buf, buf_siz) == 0);
  return buf;
}



bool string_validation(char *string) {
	for(int i = 0; i < strlen(string); ++i)
		if (!isalnum(string[i]) && !isspace(string[i]))
            return false;
	return true;
}


bool is_number(char*str0){

  int str_length = strlen(str0);
  int i = 0;
  for(i = 0; i < str_length; ++i){
    if(!isdigit(str0[i])) {
      return false ; 
    }
  }
  return true;
}


bool right_form(char *str0){
   int i = 1;
   while(toupper(isalpha(str0[0]))){
		for(i = 1; i < strlen(str0); ++i){
			if(!isdigit(str0[i])) {
				return false ;
			}
		}
		return true;
	}
	return false;
}

char * ask_que(char *str){
	char * input = ask_question_string_("Please insert Name: ", str, 100); 
	while(!string_validation(input)){
		printf("Invalid input \n");
		input = ask_question_string_("Please insert Name: ", str, 100); 
	}
	return str; 
}

char * ask_name(char *str){
	char * input = ask_question_string_("Please insert Name: ", str, 100); 
	while(!string_validation(input)){
		printf("Invalid input \n");
		input = ask_question_string_("Please insert Name: ", str, 100); 
	}
	return str; 
}



char * ask_description(char *str){
	char * input = ask_question_string_("Please insert description: ", str, 100); 
	while(!string_validation(input)){
		printf("Invalid input \n");
		input = ask_question_string_("Please insert description: ", str, 100); 
	}
	return str; 
	
}


int ask_price(char* str){
    char * input = ask_question_string_("Please insert price: ", str, 10);
	while(!is_number(input)){
		puts("invalid input");
	   input = ask_question_string_("Please insert price: ", str, 10);
	}
	return atoi(str); 
		}


int ask_quantity(char* str){
    char * input = ask_question_string_("Please insert quantity: ", str, 10);
	while(!is_number(input)){
	   puts("invalid input");
	   input = ask_question_string_("Please insert quantity: ", str, 10);
	}
	return atoi(str); 
		}


char* ask_question_shelf(char*str){
	  char * input = ask_question_string_("Insert shelf: ", str, 10);
	 while(!right_form(input)){
		 printf("Invalid input\n");
		 input = ask_question_string_("Insert shelf: ", str, 10);
	 }
	 return str; 
}


/*
bool is_number(char*str0){

  int str_length = strlen(str0);
  int i = 0;
  for(i = 0; i < str_length; ++i){
    if(!isdigit(str0[i])) {
      return false ; 
    }
  }
  return true;
  }*/
/*
bool string_validation(char *string) {
	for(int i = 0; i < strlen(string); ++i)
		if (!isalnum(string[i]) && !isspace(string[i]))
            return false;
	return true;
	}*/


bool read_string_bool(){
	bool correct;
	char *buff = (char*)malloc(100*sizeof(char)+ 1); 

	do{
		fgets(buff, 99, stdin);
		correct = false;
		if(!string_validation(buff)){
			printf("you put invalid input try again \n");
	
		} else {
			correct = true;
   
		}
	} while (!correct);

	free(buff); 
	return true; 
}

bool read_int(){
	bool correct;
	char *buf = (char*)malloc(50*sizeof(char)+ 1); 

	do{
		fgets(buf, 50, stdin);
		correct = false;
		if(!is_number(buf)){
			printf("you put invalid input try again \n");
	
		} else {
			correct = true;
   
		}
	} while (!correct);

	free(buf); 
	return true; 
}


char* ask_question_string(char *question)
{
  do
    {
      printf("%s\n", question);
    }
  while (!read_string_bool());
  return question; 
}


int ask_question_int(char *question)
{
  do
    {
      printf("%s: ", question);
    }
  while (!read_int());
  return atoi(question); 
}


