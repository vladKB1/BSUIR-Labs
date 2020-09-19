#include <bits/stdc++.h>

#define ll long long
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

double average(int *a, const int Size) {
    double ans = 0;
    for (int i = 0; i < Size; i++) ans += a[i];
    return ans/max(1,Size);
}

int main() {
    int n, m;

    cin >> n >> m;

    int **a = new int *[n];
    int Size = 0;

    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if ((j+1) % 2 == 0 && a[i][j] % 2) Size++;
        }
    }

    int *ans = new int[Size];
    Size = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    if (((j+1) % 2 == 0 && a[i][j] % 2)) ans[Size++] = a[i][j];

    for (int i = 0; i < Size; i++) cout << ans[i] << " ";
    cout << endl;

    cout << "Average = " << average(ans,Size) << endl;

    return 0;
}
