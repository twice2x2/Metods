#include <iostream>
using namespace std;

//y' = f1(x, y, z)
double f1(double x, double y, double z) {
    return z;
}

//z' = f2(x, y, z)
double f2(double x, double y, double z) {
    return -y;
}

int main() {
    double x, y, z, h;
    int n;

    cout <<"Введите x0 y0 z0 h n: ";
    cin >> x >> y >> z >> h >> n;

    cout <<"Метод Рунге-Кутта 4-го порядка для системы:\n";

    for (int i = 0; i < n; i++) {
        double k1 = h * f1(x, y, z);
        double l1 = h * f2(x, y, z);

        double k2 = h * f1(x + h / 2, y + k1 / 2, z + l1 / 2);
        double l2 = h * f2(x + h / 2, y + k1 / 2, z + l1 / 2);

        double k3 = h * f1(x + h / 2, y + k2 / 2, z + l2 / 2);
        double l3 = h * f2(x + h / 2, y + k2 / 2, z + l2 / 2);

        double k4 = h * f1(x + h, y + k3, z + l3);
        double l4 = h * f2(x + h, y + k3, z + l3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        z += (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        x += h;

        cout << "x = " << x << " y = " << y << " z = " << z << endl;
    }

    return 0;
}
