#include "s21_math.h"

long double s21_fmod(double x, double y)
{
    if (y == 0 || x == S21_INF_NEG || x == S21_INF_POS)
    {
        return S21_NAN;
    }
    
    if (x != y && x == S21_INF_NEG && x == S21_INF_POS && y == S21_INF_NEG && y == S21_INF_POS)
    {
        return S21_NAN;
    }
    

    if ( y == S21_INF_NEG || y == S21_INF_POS)
    {
        return (long double)x;
    }
    long long int temp = 0;
    temp = x/y;
    long double res = (long double)x - temp * (long double)y;
    return res;
}

