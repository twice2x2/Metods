#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    double x0;
    cin >> x0;

    vector<double> h(n - 1);
    for (int i = 0; i < n - 1; i++)
        h[i] = x[i + 1] - x[i];

    // z[j][j-1], z[j][j], z[j][j+1]
    vector<vector<double>> z(n, vector<double>(3, 0.0));
    vector<double> b(n, 0.0);

    for (int j = 1; j <= n - 2; j++) {
        if (j == 1) {
            z[j][0] = 2 * (h[0] + h[1]);
            z[j][1] = h[1];
        }
        else if (j == n - 2) {
            z[j][0] = h[n - 3];
            z[j][1] = 2 * (h[n - 3] + h[n - 2]);
        }
        else {
            z[j][0] = h[j - 1];
            z[j][1] = 2 * (h[j - 1] + h[j]);
            z[j][2] = h[j];
        }

        b[j] = 3 * (
            (y[j + 1] - y[j]) / h[j] -
            (y[j] - y[j - 1]) / h[j - 1]
            );
    }

    vector<double> alpha(n), beta(n), gamma(n);
    for (int i = 2; i <= n - 2; i++)
        alpha[i] = z[i][0];

    for (int i = 1; i <= n - 2; i++)
        beta[i] = z[i][1];

    for (int i = 1; i <= n - 3; i++)
        gamma[i] = z[i][2];

    vector<double> c(n), d(n);

    c[1] = gamma[1] / beta[1];
    d[1] = b[1] / beta[1];

    for (int i = 2; i <= n - 3; i++) {
        c[i] = gamma[i] / (alpha[i] * c[i - 1] + beta[i]);
        d[i] = (b[i] - alpha[i] * d[i - 1]) /
            (alpha[i] * c[i - 1] + beta[i]);
    }

    vector<double> t3(n, 0.0);
    t3[n - 2] =
        (b[n - 2] - alpha[n - 2] * d[n - 3]) /
        (alpha[n - 2] * c[n - 3] + beta[n - 2]);

    for (int i = n - 3; i >= 1; i--)
        t3[i] = c[i] * t3[i + 1] + d[i];

    t3[n - 1] = 0;

    vector<double> t4(n), t2(n), t1(n);

    for (int i = 1; i <= n - 2; i++)
        t4[i] = (t3[i] - t3[i - 1]) / (3 * h[i - 1]);

    t4[0] = t3[0] / (3 * h[0]);

    for (int i = 0; i < n - 1; i++) {
        t2[i] = (y[i + 1] - y[i]) / h[i]
            + h[i] * t3[i]
            - h[i] * h[i] * t4[i];
        t1[i] = y[i];
    }

    int k = n - 2;
    for (int i = 1; i < n; i++) {
        if (x0 <= x[i]) {
            k = i - 1;
            break;
        }
    }

    double dx = x0 - x[k];
    double y0 = t1[k]
        + t2[k] * dx
        + t3[k] * dx * dx
        + t4[k] * dx * dx * dx;

    cout << y0 << endl;

    return 0;
}
