#include <iostream>
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

    int n;

    cout << "n = ";
    cin >> n;

    double **a = new double *[n];

    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    double mx = -1e18, mn = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < min(i+1,n/2); j++) {
            mx = max(mx,max(a[i][j],a[i][n-j-1]));
            mn = min(mn,min(a[i][j],a[i][n-j-1]));
        }
    }

    for (int i = 0; i < n; i++) delete[] a[i];
    delete[] a;

    cout << "min = " << mn << endl;
    cout << "max = " << mx << endl;

    return 0;
}
