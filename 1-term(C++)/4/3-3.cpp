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

    int n, i, j, a[101][101], t = 0, k = 0;

    cout << "n = ";
    cin >> n;

    i = 1;
    j = 0;
    while (k < sqr(n)) {
        for (j = j+1; j <= n-t; j++) a[i][j] = ++k;
        j--;
        if (k == sqr(n)) break;

        for (i = i+1; i <= n-t; i++) a[i][j] = ++k;
        i--;
        if (k == sqr(n)) break;

        for (j = j-1; j >= t+1; j--) a[i][j] = ++k;
        j++;
        if (k == sqr(n)) break;

        t++;

        for (i = i-1; i >= t+1; i--) a[i][j] = ++k;
        i++;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) cout << setw(4) << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
