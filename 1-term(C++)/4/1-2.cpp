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

    int n, m, a[111][111] = { {1,2}, {3,4}}, ans1 = 1, ans2 = 0;

    cout << "n,m: ";
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] % 2) ans1 = ans1 * a[i][j];
        else ans2 += a[i][j];
    }

    cout << "Произведение нечётных элементов - " << ans1 << endl;
    cout << "Сумма чётных элементов - " << ans2 << endl;

    return 0;
}
