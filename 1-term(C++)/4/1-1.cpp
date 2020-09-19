#include <iostream>
#include <algorithm>
#include <math.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

bool f[1000000];

int main() {
    int k, a[111], stn = 0;

    cout << "k = ";
    cin >> k;

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (!f[a[i]]) a[++stn] = a[i];
        f[a[i]] = 1;
    }

    for (int i = 1; i <= stn; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
