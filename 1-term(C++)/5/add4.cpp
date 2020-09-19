#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl "\n"
#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define M_PI acos(-1)


using namespace std;

ll ans(ll n, ll sum) {
    if (n == 0) return sum;
    ll k = (n+1)/2;
    return ans(n-k,sum + k * (1 + (1+2*(k-1))) / 2);
}

int main() {
    ll n;
    while (cin >> n) cout << ans(n,0) << endl;

    return 0;
}
