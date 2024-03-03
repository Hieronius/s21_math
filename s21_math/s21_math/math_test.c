#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>

START_TEST(test_log_positive) {
    double input = 13.54;
    long double expected = log(input);
    long double result = s21_log(input);
    ck_assert_double_eq_tol(result, expected, 1e-6); // Tolerance for comparison
}
END_TEST

START_TEST(test_log_zero) {
    double input = 0.0;
    long double expected = log(input);
    long double result = s21_log(input);
    ck_assert(result == expected); // Compare the result with the expected value
}
END_TEST

START_TEST(test_log_negative) {
    double input = -13.54;
    long double result = s21_log(input);
    ck_assert(s21_isnan(result)); // Log of negative number should be NaN
}
END_TEST

START_TEST(test_log_inf_positive) {
    double input = INFINITY;
    long double expected = log(input);
    long double result = s21_log(input);
    ck_assert(result == expected);
}
END_TEST

START_TEST(test_log_nan) {
    double input = NAN;
    long double result = s21_log(input);
    ck_assert(s21_isnan(result)); // Log of NaN should be NaN
}
END_TEST

Suite *log_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Log");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_log_positive);
    tcase_add_test(tc_core, test_log_zero);
    tcase_add_test(tc_core, test_log_negative);
    tcase_add_test(tc_core, test_log_inf_positive);
    tcase_add_test(tc_core, test_log_nan);
    suite_add_tcase(s, tc_core);

    return s;
}
END_TEST

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = log_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

