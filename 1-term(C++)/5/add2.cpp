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

ll F(ll x) {
    if (x == 0) return 0; else
    if (x % 10 > 0) return x % 10; else
    F(x/10);
}

int main() {
    while (1) {
        ll p, q;

        cin >> p >> q;
        if (p == -1 && q == -1) break;

        ll ans = 0;
        for (ll i = p; i <= q; i++) ans += F(i);

        cout << ans << endl;
    }

    return 0;
}
