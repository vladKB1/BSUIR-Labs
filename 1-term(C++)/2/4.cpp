#include <iostream>
#include <math.h>

#define endl '\n'
#define sqr(a) (a) * (a)
#define cub(a) (a) * (a) * (a)
#define M_PI acos(-1)

using namespace std;

int main() {
    double L, k, x1, x2, m;

    cout << "x1, x2, m: ";
    cin >> x1 >> x2 >> m;

    k = cub(cos(sqr(x1)*M_PI/180)) + sqr(sin(cub(x2)*M_PI/180));

    if (k < 1)
        L = cub(k) + pow(m, 0.2);
    else
        L = sqr(k) - exp(m);

    cout << "L = " << L << endl;

    return 0;
}
