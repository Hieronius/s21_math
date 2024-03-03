#ifndef s21_math_h
#define s21_math_h

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

#define S21_LN2 0.693147180559945309417232
#define S21_E 2.7182818284590452353602874713527
#define S21_INF_NEG -1.0 / 0.0
#define S21_INF_POS 1.0 / 0.0
#define S21_NAN 0.0 / 0.0;
#define S21_INT_MAX 2147483647.0

int s21_isnan(long double x);
int s21_isinf(long double x);

long double s21_log(double x);
long double s21_pow_int(double base, long long int exp);
long double s21_exp(double x);
long double s21_fuctorial(long long int x);

#endif /* s21_math_h */
