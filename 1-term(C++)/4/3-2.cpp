//Luber's algorithm

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <windows.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)
#define fi first
#define se second

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, i, j, i1, j1, a[111][111], k = 0;
    bool f[111][111];

    cout << "n = ";
    cin >> n;

    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) f[i][j] = 0;

    i = 1; j = n/2+1;
    while (k != n*n) {
        a[i][j] = ++k;
        f[i][j] = 1;

        i1 = i-1;
        j1 = j-1;

        if (i1 < 1) i1 = n;
        if (j1 < 1) j1 = n;

        if (f[i1][j1]) {
            i1 = i+1;
            j1 = j;
        }

        i = i1;
        j = j1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) cout << setw(4) << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
