#include <iostream>
#include <math.h>
#include <windows.h>

#define endl '\n'
#define sqr(a) (a) * (a)
#define cub(a) (a) * (a) * (a)
#define M_PI acos(-1)

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, y, s;

    cout << "x, y: ";
    cin >> x >> y;

    if (x > 0) {
      cout << "s = (x^2 + y^3) / y = ";
      s = (sqr(x) + cub(y)) / y;
    } else
    if (x < 0) {
        cout << "s = ln|x^3| + cos(y) = ";
        s = log(fabs(cub(x))) + cos(y * M_PI / 180);
    } else {
        cout << "s = cbrt(sin(y)^2) = ";
        s = cbrt(sqr(sin(y * M_PI / 180)));
    }

    cout << s << endl;

    return 0;
}
