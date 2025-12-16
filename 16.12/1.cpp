#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    //Реализованное меню через switch case:
    int choose;
    cout << "=====================МЕНЮ=====================" << endl;
    cout << "Выберите действие:\n1.Вычисление по методу Лагранжа\n2.Вычисление по первой формуле Ньютона\n3.Выход\nОтвет: ";
    cin >> choose;

    switch (choose) {
    case 1: {
        //Переменные n и х
        int n;
        double x;
        //Ввод n
        cout << "Ввод n: ";
        cin >> n;
        //Выделение памяти для массивов
        double* x_values = new double[n + 1];
        double* y_values = new double[n + 1];
        //Ввод х
        cout << "Ввод x: ";
        cin >> x;

        //Ввод таблицы значений
        cout << "\nВведите таблицу значений:\n";
        for (int i = 0; i <= n; i++) {
            cout << "x[" << i << "] = ";
            cin >> x_values[i];
            cout << "y[" << i << "] = ";
            cin >> y_values[i];
        }
        //Переменная L
        double L = 0;

        //Цикл по i
        for (int i = 0; i <= n; i++) {
            double P = y_values[i]; // Начинаем с y_i

            //Цикл по j
            for (int j = 0; j <= n; j++) {
                //Условие проверки j!=i
                if (j != i) {
                    P = P * ((x - x_values[j]) / (x_values[i] - x_values[j]));
                }
            }
            L = L + P; // Добавляем к общей сумме
        }

        cout << "\nL(" << x << ") = " << L << endl;

        //Освобождение памяти через delete
        delete[] x_values;
        delete[] y_values;
        break;
    }
    case 2: {
        //Переменная для макс.значения узлов
        const int MAX_N = 20;

        //Переменные n и x
        int n2;      // Изменил имя на n2, чтобы не конфликтовало с case 1
        double x2;   // Изменил имя на x2

        // Массивы для хранения данных
        double x_values2[MAX_N];
        double d[MAX_N][MAX_N];
        double a[MAX_N];

        // Ввод количества узлов
        cout << "Введите количество узлов интерполяции (максимум " << MAX_N << "): ";
        cin >> n2;

        //Условие для проверки ввода узлов
        if (n2 > MAX_N) {
            cout << "Ошибка!" << endl;
            break;
        }
        //Уменьшение n
        n2--;

        //Цикл для ввода значений x
        cout << "Введите значения x (узлы интерполяции):\n";
        for (int i = 0; i <= n2; i++) {
            cout << "x[" << i << "] = ";
            cin >> x_values2[i];
        }

        //Цикл для ввода значений функций 
        cout << "Введите значения функции (y[i]):\n";
        for (int i = 0; i <= n2; i++) {
            cout << "y[" << i << "] = ";
            cin >> d[0][i];
        }

        // Ввод точки х
        cout << "Введите значение x: ";
        cin >> x2;

        //Цикл внутри цикла для вычисления разностей
        for (int i = 1; i <= n2; i++) {
            for (int j = 0; j <= n2 - i; j++) {
                d[i][j] = d[i - 1][j + 1] - d[i - 1][j];
            }
        }

        //Цикл внутри цикла для вывода таблицы разностей
        cout << "\nТаблица конечных разностей:\n";
        for (int i = 0; i <= n2; i++) {
            for (int j = 0; j <= n2 - i; j++) {
                cout << d[i][j] << "\t";
            }
            cout << endl;
        }

        //Вычисление коэффициентов a_i 
        a[0] = d[0][0];
        cout << "\na[0] = " << a[0] << endl;

        //Цикл внутри цикла для вычисления коэффициента
        for (int i = 1; i <= n2; i++) {
            a[i] = d[i][0];
            for (int j = 1; j <= i; j++) {
                a[i] = a[i] / j;
            }
            cout << "a[" << i << "] = " << a[i] << endl;
        } // Добавил закрывающую скобку

        // Проверка, являются ли узлы равноотстоящими
        double h = x_values2[1] - x_values2[0];
        bool equidistant = true;

        //Цикл проверки узлов
        for (int i = 2; i <= n2; i++) {
            //Условие для проверки узлов
            if (abs((x_values2[i] - x_values2[i - 1]) - h) > 1e-10) {
                equidistant = false;
                break;
            }
        }

        //Условие проверки на равностоящие узлы
        if (!equidistant) {
            cout << "Ошибка: узлы не равноотстоящие!" << endl;
            break;
        }

        //Вычисление t = (x - x0) / h
        double t = (x2 - x_values2[0]) / h;

        //Вычисление P(x) в точке х
        double P = a[0];

        //Цикл для вычисления P(x)
        for (int i = 1; i <= n2; i++) {
            double L = a[i];
            for (int j = 1; j <= i; j++) {
                L = L * (t - j + 1);
            }
            P = P + L;
        }

        //Вывод результата
        cout << "\nP(" << x2 << ") = " << P << endl;
        cout << "t = " << t << endl;
        break;
    }
    case 3:
        //Выход
        cout << "Выход из программы." << endl;
        break;
    }

    return 0;
}

/*
ОТВЕТЫ, ПОЛУЧЕННЫЕ КОДОМ:
3 ЗАДАНИЕ:
а) L(1.02) = 2.29
б) L(0.65) ≈ 2.53
в) L(1.28) ≈ 2.16

5 ЗАДАНИЕ:
a)  P(1.065) = 0.062964
    t = 1.5

б)  P(1.083) = 0.079645
    t = 3.3
*/