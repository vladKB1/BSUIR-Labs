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

int f[1000000];

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m, i, j, a[111][111];

    cout << "n, m: ";
    cin >> n >> m;

    int **b = new int *[n];

    for (i = 0; i < n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> a[i][j];
            f[a[i][j]]++;
        }

        int Size = 0;
        for (j = 1; j <= m; j++)
            if (f[a[i][j]] > 1) Size++;

        b[i] = new int[Size+1];
        b[i][0] = Size;

        int stn = 0;
        for (j = 1; j <= m; j++)
            if (f[a[i][j]] > 1) b[i][++stn] = a[i][j];

        for (j = 1; j <= m; j++) f[a[i][j]] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 1; j <= b[i][0]; j++) cout << b[i][j] << " ";
        cout << endl;
    }

    return 0;
}
