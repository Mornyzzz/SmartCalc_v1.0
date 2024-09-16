#include "../smartcalc.h"

void lexems_to_postfix(char** result, int len, queue_t* queue, stack_t* stack) {
  for (int i = 0; i < len; i++) {
    if (is_bracket(result[i]) == 0 && check_op(result[i]) == 0) {
      queue_push(queue, result[i]);
    }
    if (check_op(result[i]) != 0) {
      if (stack_is_empty(stack) || is_bracket(stack_peek(stack)) == '(') {
        stack_push(stack, result[i]);
      } else if (check_op(result[i]) > check_op(stack_peek(stack))) {
        stack_push(stack, result[i]);
      } else if (check_op(result[i]) <= check_op(stack_peek(stack))) {
        while (stack_is_empty(stack) != 1 &&
               (check_op(result[i]) <= check_op(stack_peek(stack)) &&
                is_bracket(stack_peek(stack)) != '(')) {
          char* st_pop = stack_pop(stack);
          queue_push(queue, st_pop);
          free(st_pop);
        }
        stack_push(stack, result[i]);
      }
    }
    if (is_bracket(result[i]) == '(') {
      stack_push(stack, result[i]);
    }
    if (is_bracket(result[i]) == ')') {
      while (is_bracket(stack_peek(stack)) != '(') {
        char* st_pop = stack_pop(stack);
        queue_push(queue, st_pop);
        free(st_pop);
      }
      free(stack_pop(stack));
    }
  }
}