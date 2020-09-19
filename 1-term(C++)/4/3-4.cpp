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

    int n, m, i, j, a[111][111];

    cout << "n, m: ";
    cin >> n >> m;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) cin >> a[i][j];
    }

    int b[111], stn = 0;
    for (i = 1; i <= n; i++) for (j = 1; j <= m-i+1; j++) b[++stn] = a[i][j];
    sort(b+1,b+1+stn);

    int k = 0;
    for (i = 1; i <= n; i++) for (j = 1; j <= m-i+1; j++) {
        k++;
        a[i][j] = b[k];
    }


    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) cout << setw(3) << a[i][j] << " ";
        cout << endl;
    }


    return 0;
}
