#include "s21_math.h"

// MARK: Нужно обсудить реализацию с Никитой. От 05.03.24

long double s21_log(double x) {
  if (x == S21_INF_POS)
  {
    return x;
  }
  if (x == 0)
  {
    return S21_INF_NEG;  // Возвращаем INF, поскольку log(0) = -бесконечность
  }
  if (x < 0)
  {
    return S21_NAN;  // возвращаем -NAN
  }
  // Вычисляем log с помощью метода Галея
  long double res = 0, compare = 0;
  int e_repeat = 0;
  for (; x >= S21_EXP; e_repeat++)
  {
    x /= S21_EXP;
  }
  for (int i = 0; i < 100; i++)
  {
    long double compare = res;
    res = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
  }
  return res += e_repeat;
}
