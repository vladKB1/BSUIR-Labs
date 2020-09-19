//variant 3
#include <iostream>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

int main() {
    int k, x = 0, i = 1;

    cout << "k = ";
    cin >> k;

    while (1) {
        int a = sqr(i), len = 0;

        while (a > 0) {
            len++;
            a = a / 10;
        }
        x += len;

        if (x >= k) {
            a = sqr(i);
            for (int j = 1; j <= x-k; j++) a /= 10;
            cout << "ans = " << a % 10 << endl;
            return 0;
        }

        i++;
    }

    return 0;
}
