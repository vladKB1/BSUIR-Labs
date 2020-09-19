#include <iostream>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)

using namespace std;

int main() {
    const double e = 1e-3;

    double d, sum = 0;
    int i = 1;
    do {
        d = pow(1./2, i) + pow(1./3, i);
        sum += d;
        i++;
    } while( d >= e);

    cout << "sum = " << sum << endl;

    return 0;
}
