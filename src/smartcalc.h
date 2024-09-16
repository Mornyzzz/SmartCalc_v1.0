#ifdef CALC_H
extern "C" {
#endif

#include "data_structures/queue.h"
#include "data_structures/stack.h"
#include "math.h"
#include "string.h"

double char_to_double(char* str, double x);
char* double_to_char(double value);
int count_dots(char* str);
void replace_unary(char** array, int len);
int check_op(char* lexem);
int op_calc(char* lexem, stack_t* stack, double x);
char is_bracket(char* temp);
void expr_to_lexems(const char* expression, char** result, int* len);
int is_func(char** result, int i);
int is_num(char** result, int i);
int check_lexems(char** result, int len);
void lexems_to_postfix(char** result, int len, queue_t* queue, stack_t* stack);
char* calc(const char* temp, double x);

#ifdef CALC_H
extern "C" {
#endif