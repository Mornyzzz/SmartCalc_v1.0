#include "../smartcalc.h"

int op_calc(char* lexem, stack_t* stack, double x) {
  char* two[] = {"^", "*", "/", "%", "+", "-"};
  double first = 0, second = 0, res = 0;
  for (int i = 0; i < 6; i++) {
    if (strcmp(lexem, two[i]) == 0) {
      if (stack_is_empty(stack)) return 0;
      char* second_str = stack_pop(stack);
      second = char_to_double(second_str, x);
      free(second_str);
    }
  }
  if (stack_is_empty(stack)) return 0;
  char* first_str = stack_pop(stack);
  first = char_to_double(first_str, x);
  free(first_str);

  if (strcmp(lexem, "^") == 0) res = pow(first, second);
  if (strcmp(lexem, "*") == 0) res = first * second;
  if (strcmp(lexem, "/") == 0) res = first / second;
  if (strcmp(lexem, "%") == 0) res = fmod(first, second);
  if (strcmp(lexem, "+") == 0) res = first + second;
  if (strcmp(lexem, "-") == 0) res = first - second;

  if (strcmp(lexem, "!") == 0) res = -first;
  if (strcmp(lexem, "=") == 0) res = +first;
  if (strcmp(lexem, "cos") == 0) res = cos(first);
  if (strcmp(lexem, "sin") == 0) res = sin(first);
  if (strcmp(lexem, "tg") == 0) res = tan(first);
  if (strcmp(lexem, "acos") == 0) res = acos(first);
  if (strcmp(lexem, "asin") == 0) res = asin(first);
  if (strcmp(lexem, "atan") == 0) res = atan(first);
  if (strcmp(lexem, "sqrt") == 0) res = sqrt(first);
  if (strcmp(lexem, "ln") == 0) res = log(first);
  if (strcmp(lexem, "log") == 0) res = log10(first);

  char* res_str = double_to_char(res);
  stack_push(stack, res_str);
  free(res_str);
  return 1;
}