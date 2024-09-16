#ifndef MODULE_TESTS_H
#define MODULE_TESTS_H

#include <check.h>
#include <math.h>

#include "../smartcalc.h"

enum test_res { OK, FAILURE };

void s21_suit_execution(Suite *suite, int *failed_count, char *suite_name);

#endif
