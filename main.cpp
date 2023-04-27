/**
     * Программа позволяет получить интерполяционный многочлен функции exp(x)-x при помощи представления Ньютона
     * и при помощи представления Лагранжа
     */
#include <iostream>
#include "functions.h"
#include <cmath>

using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "Задание 2. Задача алгебраического интерполировния." << endl;
    cout << "Вариант 3." << endl << "Дана функция f(x)=exp(x)-x" << endl;

    size_t m, n;
    double a, b, x;
    /*Ввод данных с клавиатуры*/
    cout << "Введите число значений в таблице: ";
    cin >> m;
    while (m > 1000)
    {
        cout << "Введите число m < 1000" << endl;
        cin >> m;
    }
    m--;
    cout << "Введите значение a(нижнюю границу): ";
    cin >> a;
    cout << endl << "Введите значение b(верхнюю границу): ";
    cin >> b;
    if (b < a)
        swap(a,b);

    /*Создание таблицы*/
    double x_table[1000], y_table[1000], step;
    step = (b-a)/m;
    cout << "Исходная таблица значений функций:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        x_table[i] = a + i*step;
        y_table[i] = func(x_table[i]);
        cout << x_table[i] << " " << y_table[i] << endl;
    }

    cout << endl << "Введите точку интерполирования: x = ";
    cin >> x;
    cout << endl << "Введите степень n интерполяционного многочлена (n <= " << m << "): ";
    cin >> n;
    while (n > m)
    {
        cout << "Введено недопустимое значение n. Введите степень n интерполяционного многочлена (n <= " << m << "): ";
        cin >> n;
    }

    cout << "Отсортированная таблица:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < m-1; j++)
        {
            if (fabs(x_table[j]-x) > fabs(x_table[j+1]-x))
            {
                swap (y_table[j], y_table[j+1]);
                swap (x_table[j], x_table[j+1]);
            }
        }
    }
    for (size_t i = 0; i < m; i++)
        cout << x_table[i] << " " << y_table[i] << endl;

    cout << "Значение интерполяционного многочлена, найденного при помощи представления Лагранжа: " << Lagrange(n, x_table, x) << endl;
    cout << "Абсолютная фактическая погрешность для формы Лагранжа: " << fabs(Lagrange(n, x_table, x) - func(x)) << endl;
    cout << "Значение интерполяционного многочлена, найденного при помощи представления Ньютона: " << Newton(n, x_table, x) << endl;
    cout << "Абсолютная фактическая погрешность для формы Ньютона: " << fabs(Newton(n, x_table, x) - func(x)) << endl;



    return 0;
}
