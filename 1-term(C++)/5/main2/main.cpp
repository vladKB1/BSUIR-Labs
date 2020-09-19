#include <bits/stdc++.h>

#include "main2.h"

#define ll long long
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

int main() {
    int N;
    double x[1111];

    cin >> N;

    for (int i = 1; i <= N; i++) cin >> x[i];

    double ans = calc(1,N/2,x) * calc(N/2+1,N,x);
    cout << ans << endl;

    return 0;
}
