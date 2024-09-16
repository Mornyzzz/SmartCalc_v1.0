#include "controller_tests.h"

/*  TEST OPTIONS */

START_TEST(api_calc_opt_1) {
  char *input = "(5+10+97+0*log(12))";
  char *result = calc(input, 0);
  long double result_ld = strtold(result, NULL);
  free(result);
  ck_assert_ldouble_eq(result_ld, 112.000000);
}
END_TEST

START_TEST(api_calc_opt_2) {
  char *input = "(2^(2^3))";
  char *result = calc(input, 0);
  long double result_ld = strtold(result, NULL);
  free(result);
  ck_assert_ldouble_eq(result_ld, 256.000000);
}
END_TEST

START_TEST(api_calc_opt_3) {
  char *input = "(acos(15)+asin(30)/(atan(2)*sqrt(9)))";
  char *result = calc(input, 0);
  ck_assert_str_eq(result, "nan");
  free(result);
}
END_TEST

START_TEST(api_calc_opt_4) {
  char *input = "(cos(3-1)/sin(5)*tan(1)^1)";
  char *result = calc(input, 0);
  ck_assert_str_eq(result, "nan");
  free(result);
}
END_TEST

START_TEST(api_calc_opt_5) {
  char *input = "(3%2-(-1))";
  char *result = calc(input, 0);
  long double result_ld = strtold(result, NULL);
  free(result);
  ck_assert_ldouble_eq(result_ld, 2.000000);
}
END_TEST

START_TEST(api_calc_opt_6) {
  char *input =
      "(15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
      "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1))))";
  char *result = calc(input, 0);
  long double result_ld = strtold(result, NULL);
  int test_res = fabsl(result_ld - (-30.0722)) < 1e-4 ? OK : FAILURE;
  free(result);
  ck_assert_ldouble_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_7) {
  char *input = "(cos(3-1)/sin(5)*tg(1)^1)";
  char *result = calc(input, 0);
  long double result_ld = strtold(result, NULL);
  int test_res = fabsl(result_ld - (0.675873)) < 1e-6 ? OK : FAILURE;
  free(result);
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_8) {
  char *input = "((10^5)+(10^4)/(10^(-1)))";
  char *result = calc(input, 0);
  long double result_ld = strtold(result, NULL);
  free(result);
  ck_assert_ldouble_eq(result_ld, 200000.000000);
}
END_TEST

START_TEST(api_calc_opt_9) {
  char *input = "(ln(10)-(-log(2)))";
  char *result = calc(input, 0);
  long double result_ld = strtold(result, NULL);
  int test_res = fabsl(result_ld - (2.603615)) < 1e-4 ? OK : FAILURE;
  free(result);
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_opt_10) {
  char *input = "(acos(6)+asin(9)/atan(0.5)+sqrt(0.01))";
  char *result = calc(input, 0);
  ck_assert_str_eq(result, "nan");
  free(result);
}
END_TEST

START_TEST(api_calc_opt_11) {
  char *input = "(5+67)";
  char *result = calc(input, 4);
  long double result_ld = strtold(result, NULL);
  free(result);
  ck_assert_ldouble_eq(result_ld, 72.000000);
}
END_TEST

START_TEST(api_calc_opt_12) {
  char *input = "(cos(()))";
  char *result = calc(input, 0);
  ck_assert_str_eq(result, "nan");
}
END_TEST

START_TEST(api_calc_with_x_opt_1) {
  char *input = "(x*x*x)";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  free(result);
  ck_assert_double_eq(result_ld, -8.000000);
}
END_TEST

START_TEST(api_calc_with_x_opt_2) {
  char *input = "(cos(3-1)/sin(5)*tg(1)^(1*x))";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  int test_res = fabsl(result_ld - (0.178920)) < 1e-6 ? OK : FAILURE;
  free(result);
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_with_x_opt_3) {
  char *input = "acos(6)+asin(9)/atan(0.5x)+sqrt(0.01)";
  char *result = calc(input, -2);
  ck_assert_str_eq(result, "nan");
}
END_TEST

START_TEST(api_calc_with_x_opt_4) {
  char *input = "(ln(10)-(-log(2*x*x)))";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  int test_res = fabsl(result_ld - (3.205675)) < 1e-4 ? OK : FAILURE;
  free(result);
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_with_x_opt_5) {
  char *input = "ln(10*x*x)-x*(-log(2))";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  int test_res = fabsl(result_ld - (3.086819)) < 1e-4 ? OK : FAILURE;
  free(result);
  ck_assert_int_eq(test_res, OK);
}
END_TEST

START_TEST(api_calc_with_x_opt_6) {
  char *input = "(10^5+(10^4)/(0.01*x))";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  free(result);
  ck_assert_ldouble_eq(result_ld, -400000.000000);
}
END_TEST

START_TEST(api_calc_with_x_opt_7) {
  char *input = "(12031997+05101997)";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  ck_assert_ldouble_eq(result_ld, 17133994.000000);
  free(result);
}
END_TEST

START_TEST(api_calc_with_x_opt_8) {
  char *input = "(x+5)";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  int test_res = fabsl(result_ld - (3)) < 1e-4 ? OK : FAILURE;
  ck_assert_int_eq(test_res, OK);
  free(result);
}
END_TEST

START_TEST(api_calc_with_x_opt_9) {
  char *input = "(10^6-x)";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  ck_assert_ldouble_eq(result_ld, 1000002.000000);
  free(result);
}
END_TEST

START_TEST(api_calc_with_x_opt_10) {
  char *input = "(sin(130)+x-x*x*(x))";
  char *result = calc(input, -2);
  long double result_ld = strtold(result, NULL);
  int test_res = fabsl(result_ld - (5.069894)) < 1e-4 ? OK : FAILURE;
  ck_assert_int_eq(test_res, OK);
  free(result);
}
END_TEST

START_TEST(api_calc_with_x_opt_11) {
  char *input = "(5/x)";
  char *result = calc(input, 0);
  ck_assert_str_eq(result, "inf");
  free(result);
}
END_TEST

START_TEST(api_calc_with_x_opt_12) {
  char *input = "(8%x)";
  char *result = calc(input, 3);
  long double result_ld = strtold(result, NULL);
  ck_assert_ldouble_eq(result_ld, 2.000000);
  free(result);
}
END_TEST

// START_TEST(api_infix_to_postfix_opt_1) {
//   char *input = "sin(130)";
//   char res[510] = {'\0'};
//   api_infix_to_postfix_notation(input, res);
//   ck_assert_str_eq(res, "130 sin ");
// }
// END_TEST

START_TEST(api_infix_to_postfix_opt_1) {
  char input[] = "(sin(130))";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "130sin");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_2) {
  char input[] = "((sin(130)+x-x*x*(x)))";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();

  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "130sinx+xx*x*-");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_3) {
  char input[] = "(cos(3-1)/sin(5)*tg(1)^(1*x))";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "31-cos5sin/1tg1x*^*");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_4) {
  char input[] = "(ln(10)-(-log(2)))";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "10ln2log!-");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_5) {
  char input[] = "(acos(6)+asin(9)/atan(0.5)+sqrt(0.01))";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "6acos9asin0.5atan/+0.01sqrt+");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_6) {
  char input[] = "(3%2-(-1))";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "32%1!-");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_7) {
  char input[] = "(5+10+97+0*log(12))";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "510+97+012log*+");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_8) {
  char input[] = "(x*x*x)";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "xx*x*");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_9) {
  char input[] = "(10^6-x)";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "106^x-");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

START_TEST(api_infix_to_postfix_opt_10) {
  char input[] = "(x+5)";
  char *result = calloc(255, sizeof(char));
  int len = 0;
  char **temp = calloc(300, sizeof(char *));
  for (int i = 0; i < 300; i++) {
    temp[i] = calloc(50, sizeof(char));
  }
  expr_to_lexems(input, temp, &len);
  queue_t *queue = queue_create();
  stack_t *stack = stack_create();
  lexems_to_postfix(temp, len, queue, stack);
  while (!queue_is_empty(queue)) {
    char *qwe = queue_pop(queue);
    strcat(result, qwe);
    free(qwe);
  }
  queue_destroy(queue);
  stack_destroy(stack);
  ck_assert_str_eq(result, "x5+");
  for (int i = 0; i < 300; i++) {
    free(temp[i]);
  }
  free(temp);
  free(result);
}
END_TEST

/*  TEST SUITES */

Suite *api_calc_suit(void) {
  Suite *suite = suite_create("api_calc");
  TCase *tc_core = tcase_create("core_of_api_calc");
  tcase_add_test(tc_core, api_calc_opt_1);
  tcase_add_test(tc_core, api_calc_opt_2);
  tcase_add_test(tc_core, api_calc_opt_3);
  tcase_add_test(tc_core, api_calc_opt_4);
  tcase_add_test(tc_core, api_calc_opt_5);
  tcase_add_test(tc_core, api_calc_opt_6);
  tcase_add_test(tc_core, api_calc_opt_7);
  tcase_add_test(tc_core, api_calc_opt_8);
  tcase_add_test(tc_core, api_calc_opt_9);
  tcase_add_test(tc_core, api_calc_opt_10);
  tcase_add_test(tc_core, api_calc_opt_11);
  tcase_add_test(tc_core, api_calc_opt_12);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *api_calc_with_x_suit(void) {
  Suite *suite = suite_create("api_calc_with_x");
  TCase *tc_core = tcase_create("core_of_api_calc_with_x");
  tcase_add_test(tc_core, api_calc_with_x_opt_1);
  tcase_add_test(tc_core, api_calc_with_x_opt_2);
  tcase_add_test(tc_core, api_calc_with_x_opt_3);
  tcase_add_test(tc_core, api_calc_with_x_opt_4);
  tcase_add_test(tc_core, api_calc_with_x_opt_5);
  tcase_add_test(tc_core, api_calc_with_x_opt_6);
  tcase_add_test(tc_core, api_calc_with_x_opt_7);
  tcase_add_test(tc_core, api_calc_with_x_opt_8);
  tcase_add_test(tc_core, api_calc_with_x_opt_9);
  tcase_add_test(tc_core, api_calc_with_x_opt_10);
  tcase_add_test(tc_core, api_calc_with_x_opt_11);
  tcase_add_test(tc_core, api_calc_with_x_opt_12);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *api_infix_to_postfix_suit(void) {
  Suite *suite = suite_create("api_infix_to_postfix");
  TCase *tc_core = tcase_create("core_api_infix_to_postfix");
  tcase_add_test(tc_core, api_infix_to_postfix_opt_1);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_2);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_3);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_4);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_5);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_6);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_7);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_8);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_9);
  tcase_add_test(tc_core, api_infix_to_postfix_opt_10);
  suite_add_tcase(suite, tc_core);

  return suite;
}

/*  SUITES EXECUTION SCRIPT */

void s21_suit_execution(Suite *suite, int *failed_count, char *suite_name) {
  SRunner *suite_runner = srunner_create(suite);
  srunner_set_log(suite_runner, suite_name);
  srunner_run_all(suite_runner, CK_NORMAL);
  *failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
}

/*  TESTS MAIN */

int main(void) {
  int failed_count = 0;

  s21_suit_execution(api_calc_suit(), &failed_count,
                     "tests/api_calc_tests.log");
  s21_suit_execution(api_calc_with_x_suit(), &failed_count,
                     "tests/api_calc_with_x_tests.log");
  s21_suit_execution(api_infix_to_postfix_suit(), &failed_count,
                     "tests/api_infix_to_postfix_tests.log");

  return failed_count == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
