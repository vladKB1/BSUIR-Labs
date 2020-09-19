#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <windows.h>

#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m, a[111][111], b[111][111];

    cout << "n,m: ";
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];

            b[i][j] = a[i][j];
            if (i > 1) b[i][j] = max(b[i][j],b[i-1][j]);
            if (j > 1) b[i][j] = max(b[i][j],b[i][j-1]);
            if (i > 1 && j > 1) b[i][j] = max(b[i][j],b[i-1][j-1]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << b[i][j] << " ";
        cout << endl;
    }

    return 0;

    i = 1; j = m;
    while (i <= n && j >= 1) {
        cout << a[i][j] << endl;
        i++;
        j--;
    }

}
