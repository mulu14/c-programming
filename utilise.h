#ifndef _ASK_H_
#define _ASK_H_
#include<stdbool.h>
typedef union answer answer_t;
char * ask_que(); 
bool is_number(char*str);
bool string_validation(char *string);
bool right_form(char *str);
char* ask_question_shelf(char*str);
char * ask_name(char *str);
char * ask_description(char *str);
int ask_price(char* str);
int ask_quantity(char* str);
bool right_form(char *str); 
char*ask_question_string(char *question);
bool read_string_bool();
int ask_question_int(char*question); 
#endif
