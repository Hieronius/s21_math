#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>


START_TEST(log_tests) {
  // ck_assert(s21_isnan(log(-13.54)) && s21_isnan(s21_log(-13.54)));
  ck_assert_ldouble_eq(log(-13.54), s21_log(-13.54));
  ck_assert_ldouble_eq(log(13.54), s21_log(13.54));
  ck_assert_ldouble_eq(log(0.0), s21_log(0.0));
  ck_assert_ldouble_eq(log(1.0), s21_log(1.0));
  ck_assert_ldouble_eq(log(3.14), s21_log(3.14));
  ck_assert_ldouble_eq(log(6.28), s21_log(6.28));
  ck_assert_ldouble_eq(log(2.2343), s21_log(2.2343));
  ck_assert_ldouble_eq(log(0.1234), s21_log(0.1234));
}
END_TEST

Suite *s21_log_test_suite() {
  Suite *s21_math = suite_create("s21_math");
  TCase *s21_math_tests = tcase_create("S21_MATH");
  tcase_add_test(s21_math_tests, log_tests);
  suite_add_tcase(s21_math, s21_math_tests);
  return s21_math;
}

int main() {
  Suite *s21_math = s21_log_test_suite();
  SRunner *s21_math_runner = srunner_create(s21_math);
  float number_failed;
  srunner_run_all(s21_math_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_math_runner);
  srunner_free(s21_math_runner);

  return number_failed == 0 ? 0 : 1;
}

