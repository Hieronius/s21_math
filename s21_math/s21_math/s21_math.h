// MARK: Обновлено 05.03.24

#ifndef s21_math_h
#define s21_math_h

#include <stdio.h>
#include <limits.h>

#define S21_LN2 0.693147180559945309417232
#define S21_EXP 2.7182818284590452353602874713527
#define S21_INF_NEG -1.0 / 0.0
#define S21_INF_POS +1.0 / 0.0
#define S21_NAN 0.0 / -0.0; // нужен ли тут минус?
#define S21_INT_MAX 2147483647.0

// Дополнительные глобальные переменные Руслана:
#define S21_MAX 1e100
#define S21_EPS 1e-100


long double s21_fabs(double x); // вычисляет абсолютное значение числа с плавающей ✅ точкой +
long double s21_fmod(double x, double y); // остаток операции деления с плавающей ✅ точкой +
long double s21_exp(double x); // вычисляет экспоненту числа с плавающей точкой с помощью ряда Тейлора ✅
long double s21_pow(double base, double exp); // вычисляет степень числа base ✅
long double s21_log(double x); // вычисляет логарифм числа ✅
long double s21_factorial(int N); // вычисляет факториал числа ✅


#endif /* s21_math_h */
