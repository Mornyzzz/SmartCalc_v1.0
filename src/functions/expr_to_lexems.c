#include "../smartcalc.h"

void expr_to_lexems(const char* expression, char** result, int* len) {
  int q = 0;
  int count = 0;
  char delimiters[] = "+-*/()^%";  // разделители лексем

  int index = -1;
  while (expression[count] != '\0') {
    //нашли разделитель
    if (strchr(delimiters, expression[count]) != NULL) {
      //разделители не подряд - заносим число или функцию
      if (count != index + 1) {
        strncpy(result[q], expression + index + 1, count - index - 1);
        q++;
      }
      //заносим разделитель
      sprintf(result[q], "%c", expression[count]);
      q++;

      //унарный минус или плюс
      replace_unary(result, q);
      index = count;
    }
    count++;
  }
  if (index != (int)strlen(expression) - 1) {
    strncpy(result[q], expression + index + 1, count - index - 1);
  }
  *len = q;
}