#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <cmath>

double func (double x)
{
    return exp(x)-x;
}

/*Реализация интерполяции методом Лагранжа*/
double Lagrange(size_t n, double x_table[], double x)
{
    double result = 0;
    for (size_t i = 0; i < n; i++)
    {
        double frac = 1;
        for (size_t j = 0; j < n; j++)
        {
            if(i != j)
                frac *= (x - x_table[j])/(x_table[i]-x_table[j]);
        }
        result += frac * func(x_table[i]);
    }
    return result;
}

/*Вычисление симметрической разности для коэффициентов в методе Ньютона*/
double symmetricDifference(size_t index, double x_table[]){
        double result = 0;
        for(size_t i = 0; i <= index; i++)
        {
            double temp = 1;
            for(size_t j = 0; j <= index; j++)
            {
                 if(i != j)
                     temp *= (x_table[i] - x_table[j]);
            }

            temp = 1/temp;
            result += func(x_table[i]) * temp;
        }
        return result;
    }


/*Реализация интерполяции меетодом Ньютона*/
double Newton(size_t n, double x_table[], double x)
{
    double coefficients[1000];
    coefficients[0] = func(x_table[0]);
    for (size_t i = 1; i < n; i++)
    {
        coefficients[i] = symmetricDifference(i, x_table);
    }
    double multiply = 1;
    double result = 0;
    for(size_t i = 0; i < n; i++)
    {
        result += coefficients[i]*multiply;
        multiply *= (x - x_table[i]);
    }
    return result;
}


#endif // FUNCTIONS_H_INCLUDED
