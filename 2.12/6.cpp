#include <iostream>
#include <cmath>
using namespace std;

double F(double x) {
    return x * x - 1;                   //Исходная функция
}

double F_proizvodnaya(double x) {        //Производная функция
    return 2 * x;
}
int main() {
    setlocale(LC_ALL, "ru");

    double a, b, e;


    cout << "a: ";
    cin >> a;
    cout << "\nb: \n";
    cin >> b;                           //Запрос значений для переменных
    cout << "\ne: \n";
    cin >> e;

    double h = (b - a) / 100.0;
    double x = F(a);
    double y = F(a + 2 * h) - 2 * F(a + h) + F(a);          //Переменные исходя из блок схемы с формулами
    double x_0, x_1;
    double c;

    if (x * y < 0) {
        x_0 = a;
        x_1 = b;
        c = b;
    }                           // условие x * y < 0
    else {
        x_0 = b;
        x_1 = a;
        c = a;
    }

    double x_2 = (x_0 * F(c) - c * F(x_0)) / (F(c) - F(x_0));
    double x_3 = x_1 - (F(x_1) / F_proizvodnaya(x_1));

    while (fabs(x_3 - x_2) > 2 * e) {
        x_0 = x_2;
        x_2 = (x_0 * F(c) - c * F(x_0)) / (F(c) - F(x_0));
        x_1 = x_3;                                                   //Цикл - пока |x_3 - x_2| > e, цикл выполняется
        x_3 = x_1 - (F(x_1) / F_proizvodnaya(x_1));
    }

    double x_itog = (x_2 + x_3) / 2; //Получение x

    cout << endl;
    cout << "x = " << x_itog;       //Вывод x
    return 0;
}