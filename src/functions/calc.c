#include "../smartcalc.h"

char* calc(const char* temp, double x) {
  if (strstr(temp, ")(") != NULL) {
    return "nan";
  }
  int len;
  char** result = calloc(300, sizeof(char*));  // memory for lexems array
  for (int i = 0; i < 300; i++) {
    result[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(temp, result, &len);
  if (check_lexems(result, len) == 0) {  //проверка лексем
    for (int i = 0; i < 300; i++) {
      free(result[i]);
    }
    free(result);
    return "nan";
  }
  stack_t* stack = stack_create();
  queue_t* queue = queue_create();
  lexems_to_postfix(result, len, queue, stack);
  while (stack_is_empty(stack) == 0) {  // calculation
    char* st_pop = stack_pop(stack);
    queue_push(queue, st_pop);
    free(st_pop);
  }
  while (queue_is_empty(queue) != 1) {
    if (check_op(queue_peek(queue)) == 0) {
      char* qu_pop = queue_pop(queue);
      stack_push(stack, qu_pop);
      free(qu_pop);
    } else {
      char* qu_pop = queue_pop(queue);
      if (op_calc(qu_pop, stack, x) == 0) {
        stack_destroy(stack);
        queue_destroy(queue);
        for (int i = 0; i < 300; i++) {
          free(result[i]);
        }
        free(result);
        free(qu_pop);
        return "nan";
      }
      free(qu_pop);
    }
  }
  char* res = stack_pop(stack);  // rounding
  int res_len = strlen(res);
  if (strchr(res, '.') != NULL) {
    while (res[res_len - 1] == '0') {
      res[res_len - 1] = '\0';
      res_len--;
    }
    if (res[res_len - 1] == '.') {
      res[res_len - 1] = '\0';
      res_len--;
    }
  }
  stack_destroy(stack);  // free
  queue_destroy(queue);
  for (int i = 0; i < 300; i++) {
    free(result[i]);
  }
  free(result);
  return res;
}