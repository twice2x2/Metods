#include <iostream>
using namespace std;

double F(double x) {
    return x * x - 1;           //Функция для решения уравнения 
}

int main() {
    setlocale(LC_ALL, "ru");

    double a, b, x, c;      //Переменные
    double h = 0.0001;      //Точность
    int N = 0;              //Счетчик итераций

    cout << "\na: \n";
    cin >> a;
    cout << "\nb: \n";
    cin >> b;                  //Запрос всех значений для переменных

    if (F(a) * F(b) > 0) {
        cout << "Ошибка!";    //Условие проверки F(a) * F(c) > 0
        return 1;
    }

    while ((b - a) > 2 * h) {    //Цикл работы алгоритма: пока (b -  a) > 2 * e, цикл продолжается
        c = (a + b) / 2;
        N++;                    //Считает итерации

        if (F(a) * F(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    x = (a + b) / 2;            //Нахождения x

    cout << endl;
    cout << "x = " << x << endl;        //Вывод ответа
    cout << "Итерации: " << N;

    return 0;
}