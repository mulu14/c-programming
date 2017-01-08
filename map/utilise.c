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


bool right_form(char *string){
    int len = strlen(string);
    if (!isalpha(string[0]) || (len > 1 && !isdigit(string[1])))
        return false;

    for (int i = 1; i < len && string[i] != '\n'; ++i)
        if (!isdigit(string[i]))
            return false;

    return true;
}



union answer {
  int i;
  float f;
  char *s; 
};


bool not_empty(char*str){
  return strlen(str) > 0;
}






answer_t ask_question(char *question, check_func check, convert_func convert){
  int size = 200;
  char buf[size];
  do{
    printf("%s", question);
    read_string(buf, size); 
    
  } while(!check(buf));
  return convert(buf);  
}


answer_t make_string(char *str)
{
  answer_t a;
  a.s = strdup(str);
  return a;
}


char *ask_Question_string(char *question)
{
  return ask_question(question, not_empty, make_string).s;
}



answer_t make_int(char*str){
  answer_t a; 
  a.i = atoi(str);
  return a; 
}



int ask_Question_int(char *question)
{
  return ask_question(question, not_empty, make_int).i;
}



answer_t make_float(char *str){
  return (answer_t){.f = atof(str)}; 
}


char * ask_question_string(char *str){
	char * input = ask_Question_string(str); 
	while(!string_validation(input)){
		printf("Invalid input \n");
		input = ask_Question_string(str); 
	}
//	free(input); 
	return input; 
}


int ask_question_int(char* str){
    char *input = ask_Question_string(str); 
	while(!is_number(input)){
		puts("invalid input");
	   input = ask_Question_string(str);
	}
	return atoi(input); 
		}



char* ask_question_shelf(char*str){
	  char * input = ask_Question_string(str);
	 while(!right_form(input)){
		 printf("Invalid input\n");
		 input = ask_Question_string(str);
	 }
	 //free(input); 
	 return input; 
	 }


