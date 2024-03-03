#include <stdio.h>
#include <limits.h>

// MARK: Арсентий.
/*
 
 MARK: Нам нужно достичь 80% покрытия тестами с помощью gcov and lcov
 MARK: Точность в 16 символов нужно защить в EPSILON NUMBER = 1e-16
 MARK: 6 символов после точки, вероятн, нужно использовать как входные данные для тестов. Например, 1.123456 или 10.764123 ???
 
 MARK: Что такое ряд Тейлора на пальцах:
 Представьте себе американские горки. Наша задача получить данные о высоте каждого подьема горки. Если горки состоят из 4-5 вершин, их можно посчитать вручную, а что если горки состоят из миллиарда вершин? Тогда используется Ряд Тейлора.
 
 Давайте нарисуем прототип американских горок на графике x/y. X - дистанция горок, а Y - высота горок.
 
 Основная цель ряда Тейлора, не зная конкретных величин, отрисовать N число приблизительно таких же американских горок на том же месте. В формуле N - может иметь значение terms.
 
 Следовательно, если мы хотим получить приблизительное представление горки на графике, достаточно указать terms = 1-5
 Более высокая точность, это уже terms = 10
 В нашем случае (точность числа в 16 знаков), будет достаточно terms = 20
 
 Чем больше вариантов американских горок мы на чертим на графике, тем четке будет очертание горки, которая содержит в себе большее количество совпадений. Представьте, что вы от руки обводите одну и ту же букву в слове множество раз. Ширина и четкость шрифта, как раз и означает точность ряда Тейлора.
 
 Мы можем взять terms = 50 и даже terms = 100, но с каждым новым значением падает производительность или скорость выполнения алгоритма. Поэтому 20 в нашем случае будет оптимально.
 MARK: Конец обьяснения ряда Тейлора
 
 1. Какие глобальные переменные нужны ✅
 2. Проверки от дураков:
   В решениях у ребят не увидел проверок в функциях вообще.
 3. Разобрать тесты для функций math.h:
 
   * Алгоритм создания тестов для одной функции:
 
        - создание функции START_TEST(название функции) с помощью assert
        - создание набора тестов Suite
        - добавление теста с assert в виде case в набор тестов Suite
        - запуск набора тестов Suite в main. Для каждой функции свой файл и main
 
    * Из чего состоит стандартный тест:
 
        Пример: ck_assert_int_eq(s21_abs(0), 0)
 
        - START_TEST - макрос, который означает начало нового test case
 
        - ck_assert_int_eq - макрос, который проверяет корретный output функции
            ck - аббревиатура для check.h
            assert - означает, что функция должна вернуть true, иначе fail
            int - означает, что функция должна иметь тип данных "int"
            eq - означает, что входное значение функции и результат должны быть равны
            
 
            Первый аргумент тест-функции принимает нашу функцию с входным аргументом
            Второй аргумент тес-функции принимает желаемый результат
 
                Первый аргумент - s21_abs(0). Подаем 0 в функцию
                Второй аргумент - 0. Хотим получить 0 как результат
 
        - END_TEST - макрос, который означает конец test case
 
      * Из чего состоит стандартный набор тестов:
 
        Пример: Suite *s21_math_abs_suite() {
                Suite *suite;
                TCase *tc_abs;

                suite = suite_create("s21_abs");

                tc_abs_usual = tcase_create("s21_abs");
                tcase_add_test(tc_abs);

                suite_add_tcase(suite, tc_abs);

                return suite;
                }

        - Suite *названиеФункции_suite() - возвращает указатель на struct Suite
        - Suite *suite - указатель на Suite, чтобы хранить тестовые данные
        - TCase *названиеФункции - указатель на test case тестируемой функции (пустой)
        - suite = suite_create(название функции) - создаем новый набор тестов для функции
        - TCase *названиеФункции = tcase_create("названиеФункции") - присваиваем имя для test case
        - tcase_add_test(названиеФункции) - добавляем нужные тесты в test case
        - suite_add_tcase(s, Tcase) - добавляем test case в набор тестов
        - return suite - возвращаем заполненный набор тестов
 
      * Запуск тестов:
 
        Пример: int main() {
                Suite *suite;
                int failed = 0;
                SRunner *runner;

                suite = s21_math_abs_suite();
                runner = srunner_create(suite);

                srunner_run_all(runner, CK_NORMAL);
                failed = srunner_ntests_failed(runner);
                srunner_free(runner);
                return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
                }
        
        - int main {} - место для запуска тестов
        - Suite *suite - указатель на пустой набор тестов
        - int failed = 0 - место для хранения счетчика проваленных тестов
        - SRunner *runner - переменная отвечает за запуск тестов
        - suite = s21_math_abs_suite() - присваеваем конкретный набор тестов
        - runner = srunner_create(suite) - "создать запуск тестов (набор тестов)"
        - srunner_run_all(runner, CK_NORMAL) - стандартный запуск тестов
            - CK_NORMAL - означает уровень деталей выводимых на консоль. Без ньюансов непонятных обычному пользователю
        - failed = srunner_ntests_failed(runner) - запись числа проваленных тестов
        - srunner_free(runner) - освобождение памяти, выделенной на тесты
        - return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE - если проваленных тестов нет, верни TRUE. В противном случае верни False
 */

// MARK: Влад. Разобрать какие глобальные переменные и проверки от дураков, разобрать тесты для функций math.h

// MARK: - Константы для math.h

#define S21_PI 3.1415926535897932 // (возможно надо поставить L - в конец числа, значит long. Тут не 16 знаков, но число округлено верно. Возможно нам больше не надо.
#define S21_EXPONENT // Нашел такое число - 2.7182818284590452. Не знаю с чем связано
#define S21_EPSILON 1e-9 // Находил разные вариации: 1e-10, 1e-17. Полагаю такая высокая точность нам не нужна
#define S21_POSITIVE_INF 1.0 / 0.0 // есть еще и негативная бесконечность: -1.0 / 0.0
#define S21_NEGATIVE_INF -1.0 / 0.0
#define S21_NAN 0.0 / 0.0 // полагаю, потому что - "0 на 0 делить нельзя", вот и выходит "не число".


// MARK: - Уже готовы (добавить проверки)
int s21_abs(int x); // вычисляет абсолютное значение целого числа + // 0 ✅
long double s21_fabs(double x); // вычисляет абсолютное значение числа с плавающей ✅ точкой +

long double s21_ceil(double x); // возвращает ближайшее целое число, не меньшее заданного значения +
long double s21_floor(double x); // возвращает ближайшее целое число, не превышающее заданное значение + ✅
long double s21_fmod(double x, double y); // остаток операции деления с плавающей ✅ точкой +
long double s21_exp(double x); // вычисляет экспоненту числа с плавающей точкой с помощью ряда Тейлора ✅
long double s21_sqrt(double x); // вычисляет квадратный корень ✅

// Простые функции

// MARK: - Саша
long double s21_cos(double x); // вычисляет косинус ❗️
long double s21_sin(double x); //  вычисляет синус ❗️
long double s21_tan(double x); // вычисляет тангенс ❗️

// Будут использованы стандартные sqrt и pow для реализации функций, затем заменим на созданные прототипы

long double s21_acos(double x); //вычисляет арккосинус // требует Pow, sqrt и cos ❗️
long double s21_asin(double x); //вычисляет арксинус // требует Pow, sqrt и sin ❗️
long double s21_atan(double x); // вычисляет арктангенс ❗️

// MARK: - Руслан
long double s21_pow(double base, double exp); // возводит число в заданную степень ❗️ // 1
// factorial (рекурсия)
// Если будет время, пожалуйста, напиши простенький makefile без проверок на macOS/linux.

// MARK: - Никита
long double s21_log(double x); // вычисляет натуральный логарифм ❗️


// MARK: Info and notes

/*
 
 https://github.com/SolutionOP/Math - S21_Math from one of the students with makefile, libraries and tests
 
 https://github.com/MustafaNatur/S21_math_lib/tree/master - Another S21_math implementation. All functions are separated
 
 https://www.youtube.com/watch?v=sQt9ZP7u5m4 - math.h lecture from Sber students
 
 
 
 
*/



int main()
{
//    printf("%Lf\n", s21_exp(5.0));
//    printf("%Lf\n", s21_fmod(99,4));
//    printf("%Lf\n", s21_ceil(59.234));
//    printf("%Lf\n", s21_ceil(-59.234));
//    printf("%Lf\n", s21_floor(49.234));
//    printf("%Lf\n", s21_floor(-49.234));
//    printf("%Lf\n", s21_sqrt(49));
    
}

// Рассчитываем факториал, но не рекурсивно, а итеративно.
// Причина - более высокая точность и скорость обработки
// Защищает нас от stack overflow - переполнения стека
long double factorial(int n) {
    long double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to compute the power of a number
long double power(long double base, int exponent) {
    long double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}


// Синус угла АB в треугольнике ABC равен отношению противолежащей стороны (катета) C к гипотенузе С
// sin(AB) = C/C
// Принимает значения в радианах.
long double my_sin(long double x) {
    long double result = 0.0;
    long double term = 0.0;

    for (int i = 0; i < 20; i++) { // Используем 20 для ряда Тейлора, чтобы увеличить точность, но не перегружать скорость выполнения алгоритма O(n)
        term = power(-1, i) * power(x, 2 * i + 1) / factorial(2 * i + 1);
        result += term;
        if (term < 1e-16) // Останови выполнение, если точность не совпадает
            break;
    }

    return result;
}

// Косинус угла AB в треугольнике ABС равен отношению прилежащей стороны (катета) А или B к гипотенузе С
// cos(AB) = A/C или B/C
long double s21_cos(double x) {
    // Используем ряд Тейлора
}

// Tангенс угла АВ в треугольнике АBC равен отношению противоположной стороны (катета) C к прилежающей стороне A или B
// tan(AB) = C/A или C/B
long double s21_tan(double x) {

}


long double s21_acos(double x) { //вычисляет арккосинус // требует Pow, sqrt и cos ❗️

}
//long double s21_asin(double x) { //вычисляет арксинус // требует Pow, sqrt и sin ❗️
//
//}
//long double s21_atan(double x) { // вычисляет арктангенс ❗️
//
//}


// для инт ✅
int s21_abs(int x) {
    if (x < 0)  {
        return x * (-1);
    } else {
        return x;
        // Поставить защиту от дурака
    }
}
    
    
    // для double ✅
    long double s21_fabs(double x) {
        if (x < 0) return x * (-1);
        else return x;
        // Поставить защиту от дураков
    }
    
    // Переделать на основе POW ✅
    long double s21_sqrt(double n) {
        const double eps = 1e-9; // epsilon число
        double x = 1;
        while (s21_abs(x * x - n) > eps)
            x = (x + n / x) / 2;
        return x;
    }
    
    
    // Округляет число в большую сторону ✅
    long double s21_ceil(double x) {
        if (x < 0){
            double temp = s21_fabs(x);
            while (temp > 1.0){
                temp = temp - 1.0;
                
            }
            return x  + temp;
        }
        double prev = x;
        while (prev > 1.0){
            prev = prev - 1.0;
        }
        
        return x + 1.0 - prev;
    }
    
    // Округляет в меньшую сторону ✅
    long double s21_floor(double x) {
        if (x < 0){
            double temp = s21_fabs(x);
            while (temp > 1.0){
                temp = temp - 1.0;
                
            }
            return x  - 1 + temp;
        } else {
            double temp = x;
            while (temp > 1.0){
                temp = temp - 1.0;
            }
            
            return x  - temp;
        }
    }
    
    // Остаток от деления для чисел с плавающей точкой ✅
    long double s21_fmod(double x, double y) {
        int temp = x/y;
        int res = x - temp * y;
        return res;
    }
    
    // Нахождение экспоненты
    long double s21_exp(double x) {
        long double result = 1.0;
        long double term = 1.0;
        int i = 1;
        const double eps = 1e-9;
        
        while (1) {
            term *= x / i;
            result += term;
            if (term < eps && term > -eps)
                break;
            i++;
        }
        
        return result;
    }


