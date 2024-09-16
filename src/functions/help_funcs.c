#include "../smartcalc.h"

double char_to_double(char *str, double x) {
  if (strcmp(str, "x") == 0) {
    return x;
  }
  char *endptr;
  double value = strtod(str, &endptr);
  if (*endptr != '\0') {
    // Строка не является допустимым представлением числа с плавающей запятой
    return NAN;
  }
  return value;
}

char *double_to_char(double value) {
  char *str = calloc(50, sizeof(char));
  sprintf(str, "%lf", value);
  return str;
}

int count_dots(char *str) {
  int count = 0;
  for (char *p = str; *p != '\0'; p++) {
    if (*p == '.') {
      count++;
    }
  }
  return count;
}

void replace_unary(char **array, int len) {
  if (len != 1) {
    char *ops[] = {"(",   "^",  "+",    "-",    "/",    "*",    "%",  "cos",
                   "sin", "tg", "acos", "asin", "atan", "sqrt", "ln", "log"};
    int c = 0;

    for (int i = 0; i < 16; i++) {
      if (strcmp(array[len - 2], ops[i]) == 0) {
        c++;
      }
    }
    if (c == 0) return;
  }
  if (strcmp(array[len - 1], "+") == 0) {
    strcpy(array[len - 1], "=");
  } else if (strcmp(array[len - 1], "-") == 0) {
    strcpy(array[len - 1], "!");
  }
}

int check_op(char *lexem) {
  char *funcs[] = {"^",    "cos",  "sin",  "tg", "acos",
                   "asin", "atan", "sqrt", "ln", "log"};

  for (int i = 0; i < 10; i++) {
    if (strcmp(lexem, funcs[i]) == 0) {
      return 4;
    }
  }
  if (strcmp(lexem, "!") == 0 || strcmp(lexem, "=") == 0) {
    return 3;
  }
  if (strcmp(lexem, "*") == 0 || strcmp(lexem, "/") == 0 ||
      strcmp(lexem, "%") == 0) {
    return 2;
  }
  if (strcmp(lexem, "+") == 0 || strcmp(lexem, "-") == 0) {
    return 1;
  }
  return 0;
}

char is_bracket(char *temp) {
  if (strcmp(temp, "(") == 0) return '(';
  if (strcmp(temp, ")") == 0) return ')';
  return 0;
}

int is_func(char **result, int i) {
  char *endptr;
  strtod(result[i], &endptr);
  int func =
      (strcmp(result[i], "^") == 0) || (strcmp(result[i], "*") == 0) ||
              (strcmp(result[i], "/") == 0) || (strcmp(result[i], "%") == 0) ||
              (strcmp(result[i], "+") == 0) || (strcmp(result[i], "-") == 0) ||
              (strcmp(result[i], "(") == 0) || (strcmp(result[i], ")") == 0)
          ? 0
          : 1;
  return func;
}

int is_num(char **result, int i) {
  char *endptr;
  strtod(result[i], &endptr);
  int num = (*endptr == '\0') || (strcmp(result[i], "x") == 0) ? 1 : 0;
  return num;
}

int check_lexems(char **result, int len) {
  char alphabet[] = "qwertyuiopasdfghjklzxcvbnm";
  char digits[] = "0123456789";

  for (int i = 0; i < len; i++) {
    int flag = 0;
    for (int j = 0; j < (int)strlen(alphabet); j++) {
      if (strchr(result[i], alphabet[j]) != NULL) {
        flag++;
        break;
      }
    }
    for (int j = 0; j < (int)strlen(digits); j++) {
      if (strchr(result[i], digits[j]) != NULL) {
        flag++;
        break;
      }
    }
    if (flag == 2) return 0;
  }

  int flag = 0;
  for (int i = 0; i < len; i++) {
    if ((strcmp(result[i], "(") != 0) && (strcmp(result[i], ")") != 0)) {
      flag++;
    }
  }
  if (flag == 0) return 0;

  for (int i = 0; i < len - 1; i++) {
    if (count_dots(result[i]) > 1 || count_dots(result[i + 1]) > 1) {
      return 0;
    }
    int num_or_func_1 = is_num(result, i) || is_func(result, i);
    int num_or_func_2 = is_num(result, i + 1) || is_func(result, i + 1);
    if ((num_or_func_1 == 1) && (num_or_func_2 == 1) &&
        (strcmp(result[i], "!") != 0) && (strcmp(result[i], "=") != 0)) {
      return 0;
    }
    if (is_num(result, i) == 1 && (strcmp(result[i + 1], "(") == 0)) {
      return 0;
    }
    if (num_or_func_2 == 1 && (strcmp(result[i], ")") == 0)) {
      return 0;
    }
  }
  return 1;
}

// int main() {
// char temp[] = "-5*6.2541+(tan(3.456)-9)+3+(-4)"; //20
// char temp[] =
// "x/(7-(1+1))*3-(2+(1+1))*x/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+x/(7-(1+1))*3-(2+(1+1)))";
// char temp[] = "23-5*15/(7-(200+1))";
// char temp[] = "5*6+(2-9)";
//     char input[] = "(cos(()))";
//     puts(calc(input, 4));
//     char* result = calloc(255, sizeof(char ));
//     int len = 0;
//     char **temp = calloc(300, sizeof(char *));
//     for (int i = 0; i < 300; i++) {
//         temp[i] = calloc(50, sizeof(char));
//     }
//     expr_to_lexems(input, temp, &len);
//     queue_t *queue = queue_create();
//     stack_t *stack = stack_create();
//     lexems_to_postfix(temp, len, queue, stack);
//     while (!queue_is_empty(queue)) {
//         char* qwe = queue_pop(queue);
//         strcat(result, qwe);
//     }
//     puts(result);
// }
