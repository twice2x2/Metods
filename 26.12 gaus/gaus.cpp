#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Функция для интегрирования
double f(double x) {
    return 4 * x * x * x;
}

int main() {
    double a, b, epsilon;

    cout << "Введите a, b, epsilon: ";
    cin >> a >> b >> epsilon;

    //Начальные значения
    double f0 = f(a);
    double f1 = f(b);
    double S = f0 + f1;

    //Начальное приближение методом трапеций
    S = (b - a) * (f0 + f1) / 2.0;

    int n = 2;
    double S1, S2 = 0.0;
    double d;

    cout << fixed << setprecision(10);

    do {
        //Сохраняем предыдущее значение
        S1 = S2;

        //Вычисляем новое значение методом Гаусса
        double h = (b - a) / n;
        S2 = 0.0;

        for (int i = 0; i < n; i++) {
            double left = a + i * h;
            double right = left + h;

            //Двухточечная формула Гаусса для подынтервала [left, right]
            //Узлы Гаусса для интервала [-1, 1]: -1/√3, 1/√3
            //Преобразование в [left, right]:
            double x1 = (right + left) / 2.0 - (right - left) / (2.0 * sqrt(3.0));
            double x2 = (right + left) / 2.0 + (right - left) / (2.0 * sqrt(3.0));

            S2 += (right - left) / 2.0 * (f(x1) + f(x2));
        }

        //Оценка погрешности 
        d = fabs(S1 - S2) / 3.0;  //В блок-схеме было /15, но для метода Гаусса 2 точки обычно /3

        cout << "n = " << n << ", S = " << S2 << ", d = " << d << endl;

        n = 2 * n;

    } while (d > epsilon);

    //Вывод результатов
    cout << "\n=== ИТОГОВЫЙ РЕЗУЛЬТАТ ===" << endl;
    cout << "Интеграл: " << S2 << endl;
    cout << "Точное значение: " << (b * b * b * b - a * a * a * a) << endl;
    cout << "Погрешность: " << fabs(S2 - (b * b * b * b - a * a * a * a)) << endl;
    cout << "Количество интервалов: " << n / 2 << endl;

    return 0;
}