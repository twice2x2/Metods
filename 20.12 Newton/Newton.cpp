#include <iostream>
#include <cmath>
using namespace std;

//Задание функции f(x
double f(double x) {
    //Здесь можно изменить функцию
    return x * x;   
}

int main() { 
    double a, b, eps;
    cin >> a >> b >> eps;

    //Начальная инициализация
    double I0 = 0;          
    double I1 = 1e9;        
    int n = 5;              

    //Основной цикл уточнения
    while (fabs(I1 - I0) > eps) {
       
        n = 2 * n;

        I0 = I1;

        double h = (b - a) / n;

        I1 = 0;

        //Цикл суммирования 
        for (int i = 0; i <= n - 1; i++) {

            double x = a + i * h;

            I1 += f(x);
        }

        I1 = I1 * h;
    }

    cout << I1 << endl;

    return 0;
}
