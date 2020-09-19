#include <iostream>
#include <math.h>

#define endl '\n'
#define sqr(a) (a) * (a)
#define cub(a) (a) * (a) * (a)

using namespace std;

int main() {
    double a, b, c, d, Z;

    cout << "a, b, c, d: ";
    cin >> a >> b >> c >> d;

    if (c >= d && a < d)
        Z = a + b / c;
    else if (c < d && a >= d)
        Z = a - b / c;
    else
        Z = 0;

    cout << "Z = " << Z << endl;

    return 0;
}
