#include "s21_math.h"

int s21_isnan(long double x) {
    // NaN (not-a-number) is represented by a floating-point number where the exponent is all 1s
    // and the mantissa is non-zero.
    // Checking if x is not equal to itself will return true for NaN.
    return (x != x);
}

int s21_isinf(long double x) {
    // Infinity is represented by a floating-point number with all 1s in the exponent
    // and a zero mantissa for positive infinity, or a one in the sign bit for negative infinity.
    // We can check if the absolute value of x is greater than the largest finite floating-point number.
    // We also need to check for division by zero.
    return (x == S21_INF_POS || x == S21_INF_NEG);
}


long double s21_log(double x) {
  if (x == S21_INF_POS) return x;
  if (x == 0)
    return S21_INF_NEG;  // Возвращаем INF, поскольку log(0) = -бесконечность
  if (x < 0) return -S21_NAN;  // возвращаем -NAN
  // Вычисляем log с помощью метода Галея
  long double res = 0;
  int e_repeat = 0;
  for (; x >= S21_E; e_repeat++) x /= S21_E;
  for (int i = 0; i < 100; i++) {
    long double compare = res;
    res = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
  }
  return res += e_repeat;
}

long double s21_pow_int(double base, long long int exp) {
  long double result = 1;
  int sign = (exp > 0);
  exp *= sign ? 1 : -1;
  for (long long int i = 0; i < exp; i++)
    result = sign ? result * base : result / base;
  return result;
}

long double s21_exp(double x) {
  if (x == S21_INF_NEG) return 0;
  long double result = 0;
  long double k = (long long int)(x / S21_LN2);
  long double r = x - k * S21_LN2;
  for (int i = 0; i < 128; i++) result += s21_pow_int(r, i) / s21_fuctorial(i);
  result *= s21_pow_int(2, k);
  return result;
}

long double s21_fuctorial(long long int x) {
  if (x == 1 || x == 0) return 1;
  if (x < 0) return S21_INF_POS;
  long double res = x * s21_fuctorial(x - 1);
  return res;
}

