//variant 5

#pragma hdrstop
#pragma argsused

#include <iostream>
#include <math.h>

#define endl '\n'
#define M_PI acos(-1)

using namespace std;

int main() {
    double n, m, x, A, D, K, y;

    cout << "n, m, x, K : ";
    cin >> n >> m >> x >> K;

    A = fabs(n + m);

    D = tan(x * M_PI / 180);
    y = 1.29 + (K / A) + D * D;

    cout << "y = " << y << endl;

    return 0;
}
