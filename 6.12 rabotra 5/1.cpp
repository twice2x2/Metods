#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int n;
    double eps;
    cout << "Введите n: ";          //Ввод n
    cin >> n;
    cout << "Введите ε: ";          //Ввод точности
    cin >> eps;

    double alpha[10][11];           //Матрица коэффициентов
    double x[10];            //Текущее решение
    double y[10];           //Новое решение

    cout << "Введите коэффициенты:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) { //Ввод матрицы
            cin >> alpha[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        x[i] = alpha[i][n];         //Начальное приближение
    }

    double d = 0;                   //Разница между итерациями


    for (int i = 0; i < n; i++) {    // Первая итерация
        y[i] = alpha[i][n];         //Свободный член
        for (int j = 0; j < n; j++) {
            y[i] = y[i] + alpha[i][j] * x[j];  //Цикл: пока j < n, добавляем а_ij * x_j
        }
        d = d + (y[i] - x[i]) * (y[i] - x[i]); //Сумма квадратов разниц
    }


    if (d > eps) {
        cout << "Ошибка" << endl;    //Условие для сходимости
        return 0;
    }


    do {
        for (int i = 0; i < n; i++) {
            x[i] = y[i];            //Обновляем текущее решение
        }

        d = 0;                      //Сбрасываем разницу

        for (int i = 0; i < n; i++) {
            y[i] = alpha[i][n];     //Начинаем со свободного члена
            for (int j = 0; j < n; j++) {
                y[i] = y[i] + alpha[i][j] * x[j];  //Вычисление нового значения
            }
            d = d + (y[i] - x[i]) * (y[i] - x[i]); //Сумма разницы
        }
    } while (d > eps);               //Пока не достигнем точности

    cout << "Решение:" << endl;
    for (int i = 0; i < n; i++) {    //Вывод ответа
        cout << "y" << i + 1 << " = " << y[i] << endl;
    }

    return 0;
}
/*
Ответы при вводе данных:
а)
y1 = 0.5001
y2 = 0.6002
y3 = 0.2999
б)
y1 = -0.2001
y2 = -0.3000
y3 = 0.1002
y4 = 0.1503
в)
y1 = 0.3502
y2 = -0.4501
y3 = -0.1003
y4 = -0.5504
y5 = 0.2500
*/