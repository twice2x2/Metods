#include <iostream>
#include <cmath>

using namespace std;

//Правая часть ОДУ y' = f(x, y)
double f(double x, double y) {
    return x + y;
}

//Метод Эйлера
void euler(double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    cout << "Метод Эйлера:\n";
    for (int i = 0; i < n; i++) {
        y = y + h * f(x, y);
        x = x + h;
        cout << "x = " << x << " y = " << y << endl;
    }
}

//Метод Эйлера-Коши
void eulerCauchy(double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    cout << "Метод Эйлера-Коши:\n";
    for (int i = 0; i < n; i++) {
        double y1 = y + h * f(x, y);
        y = y + h / 2 * (f(x, y) + f(x + h, y1));
        x = x + h;
        cout << "x = " << x << " y = " << y << endl;
    }
}

//Метод Рунге-Кутта 4 порядка
void rungeKutta(double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    cout << "Метод Рунге-Кутта 4-го порядка:\n";
    for (int i = 0; i < n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;

        cout << "x = " << x << " y = " << y << endl;
    }
}

int main() {
    double x0, y0, h;
    int n, choice;

    cout << "Введите x0 y0 h n: ";
    cin >> x0 >> y0 >> h >> n;

    cout << "1 - Эйлер\n2 - Эйлер-Коши\n3 - Рунге-Кутта 4\n";
    cin >> choice;

    switch (choice) {
    case 1: euler(x0, y0, h, n); break;
    case 2: eulerCauchy(x0, y0, h, n); break;
    case 3: rungeKutta(x0, y0, h, n); break;
    default: cout << "Ошибка выбора\n";
    }

    return 0;
}
