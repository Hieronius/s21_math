#include "s21_math.h"
long double s21_fabs(double x)
{
    if (x < 0)
    {
        return x * (-1);
    }
    else return (long double)x;
}
