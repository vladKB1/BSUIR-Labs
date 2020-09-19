#include <iostream>
#include <math.h>

#define endl '\n'

using namespace std;

int main() {
    int x, y;
    double a, b, c;

    cout << "x, y: ";
    cin >> x >> y;

    if (x > y)
        y = 0;
    else if (x < y)
        x = 0;
    else
        x = y = 0;

    cout << "x = " << x << "; y = " << y << endl;

    cout << "a, b, c: ";
    cin >> a >> b >> c;

    if (a > b && a > c)
        a -= 0.3;
    else if (b > a && b > c)
        b -= 0.3;
    else if (c > a && c > b)
        c -= 0.3;

    cout << "a = " << a << "; b = " << b << "; c = " << c << endl;

    return 0;
}
