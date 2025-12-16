#include <iostream>
#include <cmath>
using namespace std;


double F(double x) {                     //Исходная функция
    return x * x - 1;  // x^2 - 1 = 0
}


double F_proizvodnaya(double x) {                  //Производная функции
    return 2 * x;  // производная от x^2 - 1
}

int main() {
    setlocale(LC_ALL, "ru");

    double a, b, e;
    double x_0, x_1;                    //Переменные

    cout << "a: ";
    cin >> a;
    cout << "\nb: \n";
    cin >> b;                           //Запрос значений для переменных
    cout << "\ne: \n";
    cin >> e;

    double h = (b - a) / 100.0;         //Вычисление h


    double x_val = F(a);
    double y_val = F(a + 2 * h) - 2 * F(a + h) + F(a);              //Вычисления x и y для проверки выпуклости


    if (x_val * y_val > 0) {
        x_0 = a;                    //Условие для x_val * y_val > 0
    }
    else {
        x_0 = b;
    }


    x_1 = x_0 - F(x_0) / F_proizvodnaya(x_0);         //Метод касательных

    while (fabs(x_1 - x_0) > e) {
        x_0 = x_1;                                 //Цикл - пока |x_1 - x_0| > e, цикл выполняется
        x_1 = x_0 - F(x_0) / F_proizvodnaya(x_0);
    }

    cout << endl;
    cout << "x = " << x_1;                          //Вывод x

    return 0;
}