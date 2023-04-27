/**
     * ��������� ��������� �������� ���������������� ��������� ������� exp(x)-x ��� ������ ������������� �������
     * � ��� ������ ������������� ��������
     */
#include <iostream>
#include "functions.h"
#include <cmath>

using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "������� 2. ������ ��������������� ���������������." << endl;
    cout << "������� 3." << endl << "���� ������� f(x)=exp(x)-x" << endl;

    size_t m, n;
    double a, b, x;
    /*���� ������ � ����������*/
    cout << "������� ����� �������� � �������: ";
    cin >> m;
    while (m > 1000)
    {
        cout << "������� ����� m < 1000" << endl;
        cin >> m;
    }
    m--;
    cout << "������� �������� a(������ �������): ";
    cin >> a;
    cout << endl << "������� �������� b(������� �������): ";
    cin >> b;
    if (b < a)
        swap(a,b);

    /*�������� �������*/
    double x_table[1000], y_table[1000], step;
    step = (b-a)/m;
    cout << "�������� ������� �������� �������:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        x_table[i] = a + i*step;
        y_table[i] = func(x_table[i]);
        cout << x_table[i] << " " << y_table[i] << endl;
    }

    cout << endl << "������� ����� ����������������: x = ";
    cin >> x;
    cout << endl << "������� ������� n ����������������� ���������� (n <= " << m << "): ";
    cin >> n;
    while (n > m)
    {
        cout << "������� ������������ �������� n. ������� ������� n ����������������� ���������� (n <= " << m << "): ";
        cin >> n;
    }

    cout << "��������������� �������:" << endl;
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

    cout << "�������� ����������������� ����������, ���������� ��� ������ ������������� ��������: " << Lagrange(n, x_table, x) << endl;
    cout << "���������� ����������� ����������� ��� ����� ��������: " << fabs(Lagrange(n, x_table, x) - func(x)) << endl;
    cout << "�������� ����������������� ����������, ���������� ��� ������ ������������� �������: " << Newton(n, x_table, x) << endl;
    cout << "���������� ����������� ����������� ��� ����� �������: " << fabs(Newton(n, x_table, x) - func(x)) << endl;



    return 0;
}
