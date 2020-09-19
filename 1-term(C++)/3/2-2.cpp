#include <iostream>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

int main() {
    int k;

    cout << "K = ";
    cin >> k;


    double ans = 1e8, ansx;
    for (int i = 0; i <= k; i++) {
        double x = -2 + i * 4./k;
        double res = acos(exp(-sqr(x+1))) + sin(x);

        if (fabs(ans) - fabs(res) >= 1e-6) {
            ans = res;
            ansx = x;
        }
    }

    cout << ansx << endl;

    return 0;
}
