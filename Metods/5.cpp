#include <iostream>
#include <cmath>
using namespace std;

double F(double x) {
    return 10 * sin(x);         //Функция для вычисления уравнения
}

int main() {
    setlocale(LC_ALL, "ru");

    double x_0, x;
    double e = 0.000001;        //Переменные

    cout << "x_0: ";
    cin >> x_0;                 //Узнаем первый x
    double x_1 = F(x_0);        //Вычисляем след x

    while (fabs(x_1 - x_0) > e) {
        x_0 = x_1;              //Цикл: пока |x_1 - x_0| > e, делаем след x
        x_1 = F(x_0);
    }

    x = x_1;

    cout << endl;
    cout << "X: " << x;         //Вывод x

    return 0;
}